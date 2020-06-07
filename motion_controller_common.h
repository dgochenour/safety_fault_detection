#ifndef MOTION_CONTROLLER_COMMON_H
#define MOTION_CONTROLLER_COMMON_H

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"
#include "netio/netio_udp.h"

const char *MOTION_CONTROLLER_PARTICIPANT_NAME = "motion_controller";
const char *THROTTLE_SYSTEM_PARTICIPANT_NAME = "throttle_system";
const char *BRAKE_SYSTEM_PARTICIPANT_NAME = "brake_system";

const int THROTTLE_CMD_TOPIC_DW_RTPS_OBJ_ID = 100;
const int THROTTLE_CMD_TOPIC_DR_RTPS_OBJ_ID = 200;
const int BRAKE_CMD_TOPIC_DW_RTPS_OBJ_ID = 300;
const int BRAKE_CMD_TOPIC_DR_RTPS_OBJ_ID = 400;

#endif /* MOTION_CONTROLLER_COMMON_H */