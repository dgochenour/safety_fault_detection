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
#include "common_utils.h"

DDS_ReturnCode_t enable_all_entities(DDS_DomainParticipant *participant) {
    DDS_Entity *entity;
    DDS_ReturnCode_t retcode;
    entity = DDS_DomainParticipant_as_entity(participant);
    retcode = DDS_Entity_enable(entity);
    return retcode;
}

DDS_ReturnCode_t register_rh_wh(RT_Registry_T *registry) {
    if(!RT_Registry_register( 
            registry, 
            DDSHST_WRITER_DEFAULT_HISTORY_NAME,
            WHSM_HistoryFactory_get_interface(), 
            NULL, 
            NULL)) {
        printf("failed to register wh\n");
        return DDS_RETCODE_ERROR;
    }
    if(!RT_Registry_register(
            registry, 
            DDSHST_READER_DEFAULT_HISTORY_NAME,
            RHSM_HistoryFactory_get_interface(), 
            NULL,
            NULL)) {
        printf("failed to register rh\n");
        return DDS_RETCODE_ERROR;
    }
    return DDS_RETCODE_OK;
}

DDS_ReturnCode_t configure_udp_transport(
        RT_Registry_T *registry, 
        struct UDP_InterfaceFactoryProperty *udp_property,
        char *udp_intf) {
    
    /* Configure UDP transport's allowed interfaces */
    if(!RT_Registry_unregister(registry, NETIO_DEFAULT_UDP_NAME, NULL, NULL)) {
        printf("failed to unregister udp\n");
        return DDS_RETCODE_ERROR;
    }
    if(!DDS_StringSeq_set_maximum(&udp_property->allow_interface,2)) {
        printf("failed to set allow_interface maximum\n");
        return DDS_RETCODE_ERROR;
    }
    if(!DDS_StringSeq_set_length(&udp_property->allow_interface,2)) {
        printf("failed to set allow_interface length\n");
        return DDS_RETCODE_ERROR;
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
        return DDS_RETCODE_ERROR;
    }
    return DDS_RETCODE_OK;
}