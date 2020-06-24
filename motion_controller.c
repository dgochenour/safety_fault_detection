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
#include "motion_controller_callbacks.h"
#include "common_utils.h"

#include "Engagement_t.h"
#include "Engagement_tPlugin.h"
#include "Engagement_tSupport.h"
#include "Angle_t.h"
#include "Angle_tPlugin.h"
#include "Angle_tSupport.h"

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
    struct UDP_InterfaceFactoryProperty *udp_property = NULL;
    struct DPSE_DiscoveryPluginProperty discovery_plugin_properties =
            DPSE_DiscoveryPluginProperty_INITIALIZER;
    DDS_Publisher *publisher = NULL;
    /* Topics */
    DDS_Topic *throttle_cmd_topic;
    DDS_Topic *brake_cmd_topic;
    DDS_Topic *steering_cmd_topic;
    /* data samples */
    control_Engagement *throttle_cmd_topic_sample = NULL;
    control_Engagement *brake_cmd_topic_sample = NULL; 
    control_Angle *steering_cmd_topic_sample = NULL;   
    /* DataWriters */
    DDS_DataWriter *throttle_cmd_topic_dw   = NULL;
    DDS_DataWriter *brake_cmd_topic_dw      = NULL;
    DDS_DataWriter *steering_cmd_topic_dw   = NULL;
    control_EngagementDataWriter *throttle_cmd_topic_dw_narrow  = NULL;
    control_EngagementDataWriter *brake_cmd_topic_dw_narrow     = NULL;
    control_AngleDataWriter *steering_cmd_topic_dw_narrow        = NULL;
    /* DataWriter QoS */
    struct DDS_DataWriterQos throttle_cmd_topic_dw_qos = 
            DDS_DataWriterQos_INITIALIZER;
    struct DDS_DataWriterQos brake_cmd_topic_dw_qos = 
            DDS_DataWriterQos_INITIALIZER;
    struct DDS_DataWriterQos steering_cmd_topic_dw_qos = 
            DDS_DataWriterQos_INITIALIZER;
    /* DataWriter Listeners */        
    struct DDS_DataWriterListener throttle_cmd_topic_dw_listener =
            DDS_DataWriterListener_INITIALIZER;   
    struct DDS_DataWriterListener brake_cmd_topic_dw_listener =
            DDS_DataWriterListener_INITIALIZER;     
    struct DDS_DataWriterListener steering_cmd_topic_dw_listener =
            DDS_DataWriterListener_INITIALIZER;         
    /* remote subscription discovery information (required for DPSE) */        
    struct DDS_SubscriptionBuiltinTopicData throttle_cmd_topic_sub_data =
            DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    struct DDS_SubscriptionBuiltinTopicData brake_cmd_topic_sub_data =
            DDS_SubscriptionBuiltinTopicData_INITIALIZER;
    struct DDS_SubscriptionBuiltinTopicData steering_cmd_topic_sub_data =
            DDS_SubscriptionBuiltinTopicData_INITIALIZER;

    DDS_ReturnCode_t retcode;
    DDS_Long i;


    dpf = DDS_DomainParticipantFactory_get_instance();
    registry = DDS_DomainParticipantFactory_get_registry(dpf);

    /* register writer and reader history */
    retcode = register_rh_wh(registry);
    if(retcode != DDS_RETCODE_OK) {
        printf("failed to register rh and wh\n");
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

    if(!RT_ComponentFactoryId_set_name(&dp_qos.discovery.discovery.name, "dpse")) {
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
    dp_qos.resource_limits.local_writer_allocation = 3;
    dp_qos.resource_limits.local_reader_allocation = 2;
    dp_qos.resource_limits.max_destination_ports = 32;
    dp_qos.resource_limits.max_receive_ports = 32;
    dp_qos.resource_limits.local_topic_allocation = 3;
    dp_qos.resource_limits.local_type_allocation = 3;
    dp_qos.resource_limits.remote_participant_allocation = 2;
    dp_qos.resource_limits.remote_reader_allocation = 8;
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
    retcode = DDS_DomainParticipant_register_type(
            dp,
            control_ANGLE_TYPE_NAME,
            control_AngleTypePlugin_get());
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
    if (brake_cmd_topic == NULL) {
        printf("topic == NULL\n");
    }
    steering_cmd_topic = DDS_DomainParticipant_create_topic(
            dp,
            control_STEERING_CMD_TOPIC_NAME,
            control_ANGLE_TYPE_NAME,
            &DDS_TOPIC_QOS_DEFAULT, 
            NULL,
            DDS_STATUS_MASK_NONE);
    if (brake_cmd_topic == NULL) {
        printf("topic == NULL\n");
    }

    /* assert the remote DomainParticipants we expect to discover */
    retcode = DPSE_RemoteParticipant_assert(dp, LONGITUDINAL_SYSTEM_PARTICIPANT_NAME);
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to assert remote participant\n");
    }
    retcode = DPSE_RemoteParticipant_assert(dp, LATERAL_SYSTEM_PARTICIPANT_NAME);
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to assert remote participant\n");
    }

    /* throttle_cmd_topic DataWriter */
    throttle_cmd_topic_dw_qos.protocol.rtps_object_id = 
            THROTTLE_CMD_TOPIC_DW_RTPS_OBJ_ID;
    throttle_cmd_topic_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    throttle_cmd_topic_dw_qos.resource_limits.max_samples_per_instance = 32;
    throttle_cmd_topic_dw_qos.resource_limits.max_instances = 2;
    throttle_cmd_topic_dw_qos.resource_limits.max_samples = 
            throttle_cmd_topic_dw_qos.resource_limits.max_instances *
            throttle_cmd_topic_dw_qos.resource_limits.max_samples_per_instance;
    throttle_cmd_topic_dw_qos.history.depth = 32;
    throttle_cmd_topic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    throttle_cmd_topic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    /* assign throttle_cmd_topic DataWriter callbacks */
    throttle_cmd_topic_dw_listener.on_publication_matched =
            throttle_cmd_topic_dw_on_publication_matched;

    throttle_cmd_topic_dw = DDS_Publisher_create_datawriter(
            publisher, 
            throttle_cmd_topic, 
            &throttle_cmd_topic_dw_qos,
            &throttle_cmd_topic_dw_listener,
            DDS_PUBLICATION_MATCHED_STATUS);
    if (throttle_cmd_topic_dw == NULL) {
        printf("throttle_cmd_topic_dw == NULL\n");
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
    throttle_cmd_topic_sub_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    if(DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
            dp,
            LONGITUDINAL_SYSTEM_PARTICIPANT_NAME,
            &throttle_cmd_topic_sub_data,
            control_Engagement_get_key_kind(control_EngagementTypePlugin_get(), NULL))) {
        printf("failed to assert remote throttle_cmd_topic subscription\n");
    }

    throttle_cmd_topic_dw_narrow = 
            control_EngagementDataWriter_narrow(throttle_cmd_topic_dw);

    /* brake_cmd_topic DataWriter */
    brake_cmd_topic_dw_qos.protocol.rtps_object_id = 
            BRAKE_CMD_TOPIC_DW_RTPS_OBJ_ID;
    brake_cmd_topic_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    brake_cmd_topic_dw_qos.resource_limits.max_samples_per_instance = 32;
    brake_cmd_topic_dw_qos.resource_limits.max_instances = 2;
    brake_cmd_topic_dw_qos.resource_limits.max_samples = 
            brake_cmd_topic_dw_qos.resource_limits.max_instances *
            brake_cmd_topic_dw_qos.resource_limits.max_samples_per_instance;
    brake_cmd_topic_dw_qos.history.depth = 32;
    brake_cmd_topic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    brake_cmd_topic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    /* assign brake_cmd_topic DataWriter callbacks */
    brake_cmd_topic_dw_listener.on_publication_matched =
            brake_cmd_topic_dw_on_publication_matched;

    brake_cmd_topic_dw = DDS_Publisher_create_datawriter(
            publisher, 
            brake_cmd_topic, 
            &brake_cmd_topic_dw_qos,
            &brake_cmd_topic_dw_listener,
            DDS_PUBLICATION_MATCHED_STATUS);
    if (brake_cmd_topic_dw == NULL) {
        printf("brake_cmd_topic_dw == NULL\n");
    }

    /* configure discovery information for the remote brake_cmd_topic 
     * DataReader
     */
    brake_cmd_topic_sub_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 
            BRAKE_CMD_TOPIC_DR_RTPS_OBJ_ID;
    brake_cmd_topic_sub_data.topic_name = 
            DDS_String_dup(control_BRAKE_CMD_TOPIC_NAME);
    brake_cmd_topic_sub_data.type_name = 
            DDS_String_dup(control_ENGAGEMENT_TYPE_NAME);
    brake_cmd_topic_sub_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    if(DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
            dp,
            LONGITUDINAL_SYSTEM_PARTICIPANT_NAME,
            &brake_cmd_topic_sub_data,
            control_Engagement_get_key_kind(control_EngagementTypePlugin_get(), NULL))) {
        printf("failed to assert remote brake_cmd_topic subscription\n");
    }

    brake_cmd_topic_dw_narrow = 
            control_EngagementDataWriter_narrow(brake_cmd_topic_dw);


    /* steering_cmd_topic DataWriter */
    steering_cmd_topic_dw_qos.protocol.rtps_object_id = 
            STEERING_CMD_TOPIC_DW_RTPS_OBJ_ID;
    steering_cmd_topic_dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    steering_cmd_topic_dw_qos.resource_limits.max_samples_per_instance = 32;
    steering_cmd_topic_dw_qos.resource_limits.max_instances = 2;
    steering_cmd_topic_dw_qos.resource_limits.max_samples = 
            steering_cmd_topic_dw_qos.resource_limits.max_instances *
            steering_cmd_topic_dw_qos.resource_limits.max_samples_per_instance;
    steering_cmd_topic_dw_qos.history.depth = 32;
    steering_cmd_topic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    steering_cmd_topic_dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    /* assign brake_cmd_topic DataWriter callbacks */
    steering_cmd_topic_dw_listener.on_publication_matched =
            steering_cmd_topic_dw_on_publication_matched;

    steering_cmd_topic_dw = DDS_Publisher_create_datawriter(
            publisher, 
            steering_cmd_topic, 
            &steering_cmd_topic_dw_qos,
            &steering_cmd_topic_dw_listener,
            DDS_PUBLICATION_MATCHED_STATUS);
    if (steering_cmd_topic_dw == NULL) {
        printf("brake_cmd_topic_dw == NULL\n");
    }

    /* configure discovery information for the remote steering_cmd_topic 
     * DataReader
     */
    steering_cmd_topic_sub_data.key.value[DDS_BUILTIN_TOPIC_KEY_OBJECT_ID] = 
            STEERING_CMD_TOPIC_DR_RTPS_OBJ_ID;
    steering_cmd_topic_sub_data.topic_name = 
            DDS_String_dup(control_STEERING_CMD_TOPIC_NAME);
    steering_cmd_topic_sub_data.type_name = 
            DDS_String_dup(control_ANGLE_TYPE_NAME);
    steering_cmd_topic_sub_data.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    if(DDS_RETCODE_OK != DPSE_RemoteSubscription_assert(
            dp,
            LATERAL_SYSTEM_PARTICIPANT_NAME,
            &steering_cmd_topic_sub_data,
            control_Angle_get_key_kind(control_AngleTypePlugin_get(), NULL))) {
        printf("failed to assert remote steering_cmd_topic subscription\n");
    }

    steering_cmd_topic_dw_narrow = 
            control_AngleDataWriter_narrow(steering_cmd_topic_dw);

    enable_all_entities(dp);

    /* create samples used to update instances */
    throttle_cmd_topic_sample = control_Engagement_create();
    if(throttle_cmd_topic_sample == NULL) {
        printf("failed control_Engagement_create\n");
    }
    brake_cmd_topic_sample = control_Engagement_create();
    if(brake_cmd_topic_sample == NULL) {
        printf("failed control_Engagement_create\n");
    }
    steering_cmd_topic_sample = control_Angle_create();
    if(steering_cmd_topic_sample == NULL) {
        printf("failed control_Angle_create\n");
    }

    for (i = 0; (count > 0 && i < count) || (count == 0); ++i) {
        
        /* set throttle_cmd_topic TEST values */
        throttle_cmd_topic_sample->device_id = 10;
        throttle_cmd_topic_sample->device_type = THROTTLE;
        throttle_cmd_topic_sample->percentage = 75;

        retcode = control_EngagementDataWriter_write(
                throttle_cmd_topic_dw_narrow,
                throttle_cmd_topic_sample,
                &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK) {
            printf("Failed to write sample\n");
        } else {
            printf("Written sample %d\n",(i+1));
        } 

        /* set brake_cmd_topic TEST values */
        brake_cmd_topic_sample->device_id = 20;
        brake_cmd_topic_sample->device_type = BRAKE;
        brake_cmd_topic_sample->percentage = 75;

        retcode = control_EngagementDataWriter_write(
                brake_cmd_topic_dw_narrow,
                brake_cmd_topic_sample,
                &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK) {
            printf("Failed to write sample\n");
        } else {
            printf("Written sample %d\n",(i+1));
        } 

        /* set steering_cmd_topic TEST values */
        steering_cmd_topic_sample->device_id = 20;
        steering_cmd_topic_sample->theta = 30;

        retcode = control_AngleDataWriter_write(
                steering_cmd_topic_dw_narrow,
                steering_cmd_topic_sample,
                &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK) {
            printf("Failed to write sample\n");
        } else {
            printf("Written sample %d\n",(i+1));
        } 

        OSAPI_Thread_sleep(sleep_time);
    }

    if (throttle_cmd_topic_sample != NULL)
    {
        control_Engagement_delete(throttle_cmd_topic_sample);
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

