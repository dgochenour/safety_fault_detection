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

#ifndef MOTION_CONTROLLER_COMMON_H
#define MOTION_CONTROLLER_COMMON_H

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"
#include "netio/netio_udp.h"

const char *MOTION_CONTROLLER_PARTICIPANT_NAME = "motion_controller";
const char *LONGITUDINAL_SYSTEM_PARTICIPANT_NAME = "longitudinal_system";
const char *LATERAL_SYSTEM_PARTICIPANT_NAME = "lateral_system";

const int THROTTLE_CMD_TOPIC_DW_RTPS_OBJ_ID = 100;
const int THROTTLE_CMD_TOPIC_DR_RTPS_OBJ_ID = 200;
const int BRAKE_CMD_TOPIC_DW_RTPS_OBJ_ID = 300;
const int BRAKE_CMD_TOPIC_DR_RTPS_OBJ_ID = 400;
const int STEERING_CMD_TOPIC_DW_RTPS_OBJ_ID = 500;
const int STEERING_CMD_TOPIC_DR_RTPS_OBJ_ID = 600;

#endif /* MOTION_CONTROLLER_COMMON_H */