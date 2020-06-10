/*
* (c) Copyright, Real-Time Innovations, 2020.  All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "motion_controller_common.h"
#include "longitudinal_system_callbacks.h"
#include "common_utils.h"
#include "Engagement_t.h"
#include "Engagement_tSupport.h"
#include "Engagement_tPlugin.h"

int subscriber_main_w_args(
        DDS_Long domain_id, 
        char *udp_intf, 
        char *peer,
        DDS_Long sleep_time, 
        DDS_Long count) {
            
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
    /* Topics */
    DDS_Topic *throttle_cmd_topic;
    DDS_Topic *brake_cmd_topic;
    DDS_Subscriber *subscriber;
    /* DataReaders */
    DDS_DataReader *throttle_cmd_topic_dr = NULL;
    DDS_DataReader *brake_cmd_topic_dr = NULL;
    /* DataReader QoS */
    struct DDS_DataReaderQos throttle_cmd_topic_dr_qos = 
            DDS_DataReaderQos_INITIALIZER;
    struct DDS_DataReaderQos brake_cmd_topic_dr_qos = 
            DDS_DataReaderQos_INITIALIZER;
    /* DataReader Listeners */          
    struct DDS_DataReaderListener throttle_cmd_topic_dr_listener = 
            DDS_DataReaderListener_INITIALIZER;
    struct DDS_DataReaderListener brake_cmd_topic_dr_listener = 
            DDS_DataReaderListener_INITIALIZER;
    /* remote publication discovery information (required for DPSE) */         
    struct DDS_PublicationBuiltinTopicData throttle_cmd_topic_pub_data =
            DDS_PublicationBuiltinTopicData_INITIALIZER;
    struct DDS_PublicationBuiltinTopicData brake_cmd_topic_pub_data =
            DDS_PublicationBuiltinTopicData_INITIALIZER;

    DDS_ReturnCode_t retcode;

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
    
    /* configure the UDP transport */
    udp_property = (struct UDP_InterfaceFactoryProperty *)
            malloc(sizeof(struct UDP_InterfaceFactoryProperty));
    if (udp_property == NULL) {
        printf("failed to allocate udp properties\n");
    }
    *udp_property = UDP_INTERFACE_FACTORY_PROPERTY_DEFAULT;
    retcode = configure_udp_transport(registry, udp_property, udp_intf);
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to configure UDP\n");
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
    dp_qos.resource_limits.local_writer_allocation = 2;
    dp_qos.resource_limits.local_reader_allocation = 2;
    dp_qos.resource_limits.max_destination_ports = 32;
    dp_qos.resource_limits.max_receive_ports = 32;
    dp_qos.resource_limits.local_topic_allocation = 2;
    dp_qos.resource_limits.local_type_allocation = 10;
    dp_qos.resource_limits.remote_participant_allocation = 1;
    dp_qos.resource_limits.remote_writer_allocation = 2;

    /* set the name of the local DomainParticipant */
    strcpy(dp_qos.participant_name.name, LONGITUDINAL_SYSTEM_PARTICIPANT_NAME);

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
    brake_cmd_topic = DDS_DomainParticipant_create_topic(
            dp,
            control_BRAKE_CMD_TOPIC_NAME,
            control_ENGAGEMENT_TYPE_NAME,
            &DDS_TOPIC_QOS_DEFAULT, 
            NULL,
            DDS_STATUS_MASK_NONE);
    if (throttle_cmd_topic == NULL) {
        printf("topic == NULL\n");
    }

    /* assert any remote DomainParticipants we expect to discover */
    retcode = DPSE_RemoteParticipant_assert(dp, MOTION_CONTROLLER_PARTICIPANT_NAME);
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to assert remote participant\n");
    }

    /* throttle_cmd_topic DataReader */
    throttle_cmd_topic_dr_qos.protocol.rtps_object_id = 
            THROTTLE_CMD_TOPIC_DR_RTPS_OBJ_ID;
    throttle_cmd_topic_dr_qos.resource_limits.max_instances = 2;
    throttle_cmd_topic_dr_qos.resource_limits.max_samples_per_instance = 32;
    throttle_cmd_topic_dr_qos.resource_limits.max_samples = 
            throttle_cmd_topic_dr_qos.resource_limits.max_instances *
            throttle_cmd_topic_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    throttle_cmd_topic_dr_qos.reader_resource_limits.max_remote_writers = 10;
    throttle_cmd_topic_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    throttle_cmd_topic_dr_qos.history.depth = 32;
    throttle_cmd_topic_dr_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;

    /* assign throttle_cmd_topic DataReader callbacks */
    throttle_cmd_topic_dr_listener.on_data_available = 
            throttle_cmd_topic_dr_on_data_available;
    throttle_cmd_topic_dr_listener.on_subscription_matched =
            throttle_cmd_topic_dr_on_subscription_matched;

    throttle_cmd_topic_dr = DDS_Subscriber_create_datareader(
            subscriber,
            DDS_Topic_as_topicdescription(throttle_cmd_topic), 
            &throttle_cmd_topic_dr_qos,
            &throttle_cmd_topic_dr_listener,
            DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);
    if(throttle_cmd_topic_dr == NULL) {
        printf("datareader == NULL\n");
    }

    /* configure discovery information for the remote throttle_cmd_topic 
     * DataWriter
     */
    throttle_cmd_topic_pub_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 
            THROTTLE_CMD_TOPIC_DW_RTPS_OBJ_ID;
    throttle_cmd_topic_pub_data.topic_name = 
            DDS_String_dup(control_THROTTLE_CMD_TOPIC_NAME);
    throttle_cmd_topic_pub_data.type_name = 
            DDS_String_dup(control_ENGAGEMENT_TYPE_NAME);
    throttle_cmd_topic_pub_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    retcode = DPSE_RemotePublication_assert(
            dp,
            MOTION_CONTROLLER_PARTICIPANT_NAME,
            &throttle_cmd_topic_pub_data,
            control_Engagement_get_key_kind(control_EngagementTypePlugin_get(), NULL));
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to assert remote publication\n");
    }

    /* brake_cmd_topic DataReader */
    brake_cmd_topic_dr_qos.protocol.rtps_object_id = 
            BRAKE_CMD_TOPIC_DR_RTPS_OBJ_ID;
    brake_cmd_topic_dr_qos.resource_limits.max_instances = 2;
    brake_cmd_topic_dr_qos.resource_limits.max_samples_per_instance = 32;
    brake_cmd_topic_dr_qos.resource_limits.max_samples = 
            brake_cmd_topic_dr_qos.resource_limits.max_instances *
            brake_cmd_topic_dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    brake_cmd_topic_dr_qos.reader_resource_limits.max_remote_writers = 10;
    brake_cmd_topic_dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    brake_cmd_topic_dr_qos.history.depth = 32;
    brake_cmd_topic_dr_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;

    /* assign brake_cmd_topic DataReader callbacks */
    brake_cmd_topic_dr_listener.on_data_available = 
            brake_cmd_topic_dr_on_data_available;
    brake_cmd_topic_dr_listener.on_subscription_matched =
            brake_cmd_topic_dr_on_subscription_matched;

    brake_cmd_topic_dr = DDS_Subscriber_create_datareader(
            subscriber,
            DDS_Topic_as_topicdescription(brake_cmd_topic), 
            &brake_cmd_topic_dr_qos,
            &brake_cmd_topic_dr_listener,
            DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);
    if(brake_cmd_topic_dr == NULL) {
        printf("datareader == NULL\n");
    }

    /* configure discovery information for the remote brake_cmd_topic 
     * DataWriter
     */
    brake_cmd_topic_pub_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 
            BRAKE_CMD_TOPIC_DW_RTPS_OBJ_ID;
    brake_cmd_topic_pub_data.topic_name = 
            DDS_String_dup(control_BRAKE_CMD_TOPIC_NAME);
    brake_cmd_topic_pub_data.type_name = 
            DDS_String_dup(control_ENGAGEMENT_TYPE_NAME);
    brake_cmd_topic_pub_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    retcode = DPSE_RemotePublication_assert(
            dp,
            MOTION_CONTROLLER_PARTICIPANT_NAME,
            &brake_cmd_topic_pub_data,
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
