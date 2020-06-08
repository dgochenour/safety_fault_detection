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

#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"
#include "netio/netio_udp.h"

DDS_ReturnCode_t enable_all_entities(DDS_DomainParticipant *participant);
DDS_ReturnCode_t configure_udp_transport(
        RT_Registry_T *registry, 
        struct UDP_InterfaceFactoryProperty *udp_property,
        char *udp_intf);
         
#endif /* COMMON_UTILS_H */