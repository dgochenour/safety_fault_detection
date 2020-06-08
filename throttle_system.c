
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "motion_controller_common.h"
#include "Engagement_t.h"
#include "Engagement_tSupport.h"
#include "Engagement_tPlugin.h"

DDS_ReturnCode_t enable_all_entities(DDS_DomainParticipant *participant) {
    DDS_Entity *entity;
    DDS_ReturnCode_t retcode;

    entity = DDS_DomainParticipant_as_entity(participant);
    retcode = DDS_Entity_enable(entity);
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to enable entity\n");
    }
    return retcode;
}

void
control_EngagementSubscriber_on_data_available(void *listener_data,
DDS_DataReader * reader)
{
    control_EngagementDataReader *hw_reader = control_EngagementDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    control_Engagement *sample = NULL;

    struct DDS_SampleInfoSeq info_seq = 
    DDS_SEQUENCE_INITIALIZER;
    struct control_EngagementSeq sample_seq = 
    DDS_SEQUENCE_INITIALIZER;

    const DDS_Long TAKE_MAX_SAMPLES = 32;
    DDS_Long i;

    retcode = control_EngagementDataReader_take(hw_reader, 
    &sample_seq, &info_seq, TAKE_MAX_SAMPLES, 
    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to take data, retcode(%d)\n", retcode);
        goto done;
    }

    /* Print each valid sample taken */
    for (i = 0; i < control_EngagementSeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = control_EngagementSeq_get_reference(&sample_seq, i);

            printf("\nValid sample received\n");
            /* TODO read sample attributes here */ 
        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    control_EngagementDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
    control_EngagementSeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
}

void
control_EngagementSubscriber_on_subscription_matched(void *listener_data,
DDS_DataReader * reader,
const struct
DDS_SubscriptionMatchedStatus
*status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a publisher\n");
    }
}



int
subscriber_main_w_args(DDS_Long domain_id, char *udp_intf, char *peer,
DDS_Long sleep_time, DDS_Long count)
{
    DDS_DomainParticipantFactory *dpf = NULL;
    struct DDS_DomainParticipantFactoryQos dpf_qos =
            DDS_DomainParticipantFactoryQos_INITIALIZER;
    DDS_DomainParticipant *dp = NULL;        
    struct DDS_DomainParticipantQos dp_qos =
            DDS_DomainParticipantQos_INITIALIZER;
    RT_Registry_T *registry = NULL;

    struct UDP_InterfaceFactoryProperty *udp_property = NULL;

    struct DPSE_DiscoveryPluginProperty discovery_plugin_properties =
            DPSE_DiscoveryPluginProperty_INITIALIZER;
    DDS_Topic *throttle_cmd_topic;
    DDS_Subscriber *subscriber;
    DDS_DataReader *throttle_cmd_topic_dr = NULL;
    struct DDS_DataReaderQos dr_qos = DDS_DataReaderQos_INITIALIZER;
    DDS_ReturnCode_t retcode;
    struct DDS_DataReaderListener dr_listener = 
            DDS_DataReaderListener_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData throttle_cmd_topic_pub_data =
            DDS_PublicationBuiltinTopicData_INITIALIZER;

    dpf = DDS_DomainParticipantFactory_get_instance();
    registry = DDS_DomainParticipantFactory_get_registry(dpf);

    if(!RT_Registry_register(
            registry, 
            DDSHST_WRITER_DEFAULT_HISTORY_NAME,
            WHSM_HistoryFactory_get_interface(), 
            NULL, 
            NULL)) {
        printf("failed to register wh\n");
    }
    if(!RT_Registry_register(
            registry, 
            DDSHST_READER_DEFAULT_HISTORY_NAME,
            RHSM_HistoryFactory_get_interface(), 
            NULL,
            NULL)) {
        printf("failed to register rh\n");
    }
    
    /* Configure UDP transport's allowed interfaces */
    if(!RT_Registry_unregister(registry, NETIO_DEFAULT_UDP_NAME, NULL, NULL)) {
        printf("failed to unregister udp\n");
    }
    udp_property = (struct UDP_InterfaceFactoryProperty *)
            malloc(sizeof(struct UDP_InterfaceFactoryProperty));
    if (udp_property == NULL) {
        printf("failed to allocate udp properties\n");
    }

    *udp_property = UDP_INTERFACE_FACTORY_PROPERTY_DEFAULT;
    if(!DDS_StringSeq_set_maximum(&udp_property->allow_interface,2)) {
        printf("failed to set allow_interface maximum\n");
    }
    if(!DDS_StringSeq_set_length(&udp_property->allow_interface,2)) {
        printf("failed to set allow_interface length\n");
    }
    *DDS_StringSeq_get_reference(&udp_property->allow_interface,0) = 
            DDS_String_dup("lo0");
    *DDS_StringSeq_get_reference(&udp_property->allow_interface,1) = 
            DDS_String_dup(udp_intf);

    if(!RT_Registry_register(
            registry, 
            NETIO_DEFAULT_UDP_NAME,
            UDP_InterfaceFactory_get_interface(),
            (struct RT_ComponentFactoryProperty*)udp_property, 
            NULL)) {
        printf("failed to register udp\n");
    }

    DDS_DomainParticipantFactory_get_qos(dpf, &dpf_qos);
    dpf_qos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;
    DDS_DomainParticipantFactory_set_qos(dpf, &dpf_qos);

    if(!RT_Registry_register(
            registry,
            "dpse",
            DPSE_DiscoveryFactory_get_interface(),
            &discovery_plugin_properties._parent,
            NULL))
    {
        printf("failed to register dpse\n");
    }

    if(!RT_ComponentFactoryId_set_name(
            &dp_qos.discovery.discovery.name,
            "dpse")) {
        printf("failed to set discovery plugin name\n");
    }
    if(!DDS_StringSeq_set_maximum(&dp_qos.discovery.initial_peers,1)) {
        printf("failed to set initial peers maximum\n");
    }
    if(!DDS_StringSeq_set_length(&dp_qos.discovery.initial_peers,1)) {
        printf("failed to set initial peers length\n");
    }

    if (peer == NULL) {
        peer = "127.0.0.1";
    }
    *DDS_StringSeq_get_reference(&dp_qos.discovery.initial_peers,0) = 
        DDS_String_dup(peer);

    dp_qos.resource_limits.max_destination_ports = 32;
    dp_qos.resource_limits.max_receive_ports = 32;
    dp_qos.resource_limits.local_topic_allocation = 2;
    dp_qos.resource_limits.local_type_allocation = 10;

    dp_qos.resource_limits.remote_participant_allocation = 1;

    /* set the name of the local DomainParticipant */
    strcpy(dp_qos.participant_name.name, THROTTLE_SYSTEM_PARTICIPANT_NAME);

    dp = DDS_DomainParticipantFactory_create_participant(
            dpf,
            domain_id,
            &dp_qos,
            NULL,
            DDS_STATUS_MASK_NONE);
    if(dp == NULL) {
        printf("failed to create participant\n");
    }


    subscriber = DDS_DomainParticipant_create_subscriber(
            dp,
            &DDS_SUBSCRIBER_QOS_DEFAULT,
            NULL, 
            DDS_STATUS_MASK_NONE);
    if(subscriber == NULL) {
        printf("subscriber == NULL\n");
    }

    /* register types */
    retcode = DDS_DomainParticipant_register_type(
            dp,
            control_ENGAGEMENT_TYPE_NAME,
            control_EngagementTypePlugin_get());
    if(retcode != DDS_RETCODE_OK) {
        printf("failed to register type\n");
    }

    /* create Topics */
    throttle_cmd_topic = DDS_DomainParticipant_create_topic(
            dp,
            control_THROTTLE_CMD_TOPIC_NAME,
            control_ENGAGEMENT_TYPE_NAME,
            &DDS_TOPIC_QOS_DEFAULT, 
            NULL,
            DDS_STATUS_MASK_NONE);
    if (throttle_cmd_topic == NULL) {
        printf("topic == NULL\n");
    }
    retcode = DPSE_RemoteParticipant_assert(dp, MOTION_CONTROLLER_PARTICIPANT_NAME);
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to assert remote participant\n");
    }
    
    dr_listener.on_data_available = 
            control_EngagementSubscriber_on_data_available;
    dr_listener.on_subscription_matched =
            control_EngagementSubscriber_on_subscription_matched;

    dr_qos.protocol.rtps_object_id = THROTTLE_CMD_TOPIC_DR_RTPS_OBJ_ID;
    dr_qos.resource_limits.max_instances = 2;
    dr_qos.resource_limits.max_samples_per_instance = 32;
    dr_qos.resource_limits.max_samples = dr_qos.resource_limits.max_instances *
    dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    dr_qos.reader_resource_limits.max_remote_writers = 10;
    dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    dr_qos.history.depth = 32;
    /* Reliability QoS */
    #ifdef USE_RELIABLE_QOS
    dr_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    #else
    dr_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    #endif

    throttle_cmd_topic_dr = DDS_Subscriber_create_datareader(
            subscriber,
            DDS_Topic_as_topicdescription(throttle_cmd_topic), 
            &dr_qos,
            &dr_listener,
            DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);
    if(throttle_cmd_topic_dr == NULL) {
        printf("datareader == NULL\n");
    }

    throttle_cmd_topic_pub_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 100;
    throttle_cmd_topic_pub_data.topic_name = 
            DDS_String_dup(control_THROTTLE_CMD_TOPIC_NAME);
    throttle_cmd_topic_pub_data.type_name = 
            DDS_String_dup(control_ENGAGEMENT_TYPE_NAME);
#ifdef USE_RELIABLE_QOS
    throttle_cmd_topic_pub_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    throttle_cmd_topic_pub_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif

    retcode = DPSE_RemotePublication_assert(
       dp,
       MOTION_CONTROLLER_PARTICIPANT_NAME,
       &throttle_cmd_topic_pub_data,
       control_Engagement_get_key_kind(control_EngagementTypePlugin_get(), NULL));
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to assert remote publication\n");
    }
    enable_all_entities(dp);

    if (count != 0)
    {
        printf("Running for %d seconds, press Ctrl-C to exit\n",
        count);
        OSAPI_Thread_sleep(count * 1000);
    }
    else
    {
        int sleep_loop_count =  (24 * 60 * 60) / 2000;
        int sleep_loop_left = (24 * 60 * 60) % 2000;

        printf("Running for 24 hours, press Ctrl-C to exit\n");

        while (sleep_loop_count)
        {
            OSAPI_Thread_sleep(2000  * 1000); /* sleep is in ms */
            --sleep_loop_count;
        }

        OSAPI_Thread_sleep(sleep_loop_left * 1000);
    }

    return 0;
}

int main(int argc, char **argv) {
    DDS_Long i = 0;
    DDS_Long domain_id = 0;
    char *peer = NULL;
    char *udp_intf = "en0";
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    for (i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-domain"))
        {
            ++i;
            if (i == argc)
            {
                printf("-domain <domain_id>\n");
                return -1;
            }
            domain_id = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-udp_intf"))
        {
            ++i;
            if (i == argc)
            {
                printf("-udp_intf <interface>\n");
                return -1;
            }
            udp_intf = argv[i];
        }
        else if (!strcmp(argv[i], "-peer"))
        {
            ++i;
            if (i == argc)
            {
                printf("-peer <address>\n");
                return -1;
            }
            peer = argv[i];
        }
        else if (!strcmp(argv[i], "-sleep"))
        {
            ++i;
            if (i == argc)
            {
                printf("-sleep_time <sleep_time>\n");
                return -1;
            }
            sleep_time = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-count"))
        {
            ++i;
            if (i == argc)
            {
                printf("-count <count>\n");
                return -1;
            }
            count = strtol(argv[i], NULL, 0);
        }
        else
        {
            printf("unknown option: %s\n", argv[i]);
            return -1;
        }
    }

    return subscriber_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
