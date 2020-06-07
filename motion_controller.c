
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "motion_controller_common.h"
#include "Engagement_t.h"
#include "Engagement_tSupport.h"

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
control_EngagementPublisher_on_publication_matched(void *listener_data,
DDS_DataWriter * writer,
const struct
DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a subscriber\n");
    }
}

int
publisher_main_w_args(DDS_Long domain_id, char *udp_intf, char *peer,
DDS_Long sleep_time, DDS_Long count)
{

    DDS_DomainParticipantFactory *dpf = NULL;
    struct DDS_DomainParticipantFactoryQos dpf_qos =
            DDS_DomainParticipantFactoryQos_INITIALIZER;
    DDS_DomainParticipant *dp = NULL;        
    struct DDS_DomainParticipantQos dp_qos =
            DDS_DomainParticipantQos_INITIALIZER;
    RT_Registry_T *registry = NULL;

    DDS_Boolean success = DDS_BOOLEAN_FALSE;

    struct UDP_InterfaceFactoryProperty *udp_property = NULL;

    struct DPSE_DiscoveryPluginProperty discovery_plugin_properties =
            DPSE_DiscoveryPluginProperty_INITIALIZER;
     DDS_Topic *throttle_cmd_topic;

    DDS_Publisher *publisher = NULL;
    DDS_DataWriter *throttle_cmd_topic_dw = NULL;
    control_EngagementDataWriter *throttle_cmd_topic_dw_narrow = NULL;
    struct DDS_DataWriterQos dw_qos = DDS_DataWriterQos_INITIALIZER;
    struct DDS_SubscriptionBuiltinTopicData throttle_cmd_topic_sub_data =
            DDS_SubscriptionBuiltinTopicData_INITIALIZER;

    DDS_ReturnCode_t retcode;
    control_Engagement *sample = NULL;
    struct Application *application = NULL;
    DDS_Long i;
    struct DDS_DataWriterListener dw_listener =
    DDS_DataWriterListener_INITIALIZER;

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
    strcpy(dp_qos.participant_name.name, MOTION_CONTROLLER_PARTICIPANT_NAME);

    dp = DDS_DomainParticipantFactory_create_participant(
            dpf,
            domain_id,
            &dp_qos,
            NULL,
            DDS_STATUS_MASK_NONE);
    if(dp == NULL) {
        printf("failed to create participant\n");
    }


    sample = control_Engagement_create();
    if(sample == NULL) {
        printf("failed control_Engagement_create\n");
    }

    publisher = DDS_DomainParticipant_create_publisher(
            dp,
            &DDS_PUBLISHER_QOS_DEFAULT,
            NULL,
            DDS_STATUS_MASK_NONE);
    if(publisher == NULL) {
        printf("publisher == NULL\n");
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

    retcode = DPSE_RemoteParticipant_assert(dp, THROTTLE_SYSTEM_PARTICIPANT_NAME);
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to assert remote participant\n");
    }

    /* throttle_cmd_topic DataWriter */
    dw_qos.protocol.rtps_object_id = THROTTLE_CMD_TOPIC_DW_RTPS_OBJ_ID;
    #ifdef USE_RELIABLE_QOS
    dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    #else
    dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    #endif
    dw_qos.resource_limits.max_samples_per_instance = 32;
    dw_qos.resource_limits.max_instances = 2;
    dw_qos.resource_limits.max_samples = dw_qos.resource_limits.max_instances *
    dw_qos.resource_limits.max_samples_per_instance;
    dw_qos.history.depth = 32;
    dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;


    dw_listener.on_publication_matched =
            control_EngagementPublisher_on_publication_matched;

    throttle_cmd_topic_dw = DDS_Publisher_create_datawriter(
            publisher, 
            throttle_cmd_topic, 
            &dw_qos,
            &dw_listener,
            DDS_PUBLICATION_MATCHED_STATUS);
    if (throttle_cmd_topic_dw == NULL) {
        printf("datawriter == NULL\n");
    }

    /* configure discovery information for the remote throttle_cmd_topic 
     * DataReader
     */
    throttle_cmd_topic_sub_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 
            THROTTLE_CMD_TOPIC_DR_RTPS_OBJ_ID;
    throttle_cmd_topic_sub_data.topic_name = 
            DDS_String_dup(control_THROTTLE_CMD_TOPIC_NAME);
    throttle_cmd_topic_sub_data.type_name = 
            DDS_String_dup(control_ENGAGEMENT_TYPE_NAME);
#ifdef USE_RELIABLE_QOS
    throttle_cmd_topic_sub_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
#else
    throttle_cmd_topic_sub_data.reliability.kind  = DDS_BEST_EFFORT_RELIABILITY_QOS;
#endif
    if(DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
           dp,
           THROTTLE_SYSTEM_PARTICIPANT_NAME,
           &throttle_cmd_topic_sub_data,
           control_Engagement_get_key_kind(control_EngagementTypePlugin_get(), NULL))) {
        printf("failed to assert remote subscription\n");
    }

    throttle_cmd_topic_dw_narrow = 
            control_EngagementDataWriter_narrow(throttle_cmd_topic_dw);

    enable_all_entities(dp);

    for (i = 0; (count > 0 && i < count) || (count == 0); ++i) {
        /* TODO set sample attributes here */

        retcode = control_EngagementDataWriter_write(
                throttle_cmd_topic_dw_narrow,
                sample,
                &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write sample\n");
        } 
        else
        {
            printf("Written sample %d\n",(i+1));
        } 

        OSAPI_Thread_sleep(sleep_time);
    }

    if (sample != NULL)
    {
        control_Engagement_delete(sample);
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

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}

