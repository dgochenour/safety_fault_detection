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

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"
#include "disc_dpse/disc_dpse_dpsediscovery.h"
#include "netio/netio_udp.h"

#include "Engagement_t.h"
#include "Engagement_tSupport.h"

void throttle_cmd_topic_dr_on_data_available(
        void *listener_data,
        DDS_DataReader * reader);

void throttle_cmd_topic_dr_on_subscription_matched(
        void *listener_data,
        DDS_DataReader * reader,
        const struct DDS_SubscriptionMatchedStatus *status);