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
#include "motion_controller_callbacks.h"

void throttle_cmd_topic_dw_on_publication_matched(
        void *listener_data,
        DDS_DataWriter * writer,
        const struct DDS_PublicationMatchedStatus *status) {
    if (status->current_count_change > 0)
    {
        printf("Matched a throttle_cmd_topic subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a subscriber\n");
    }
}

void brake_cmd_topic_dw_on_publication_matched(
            void *listener_data,
        DDS_DataWriter * writer,
        const struct DDS_PublicationMatchedStatus *status) {
    if (status->current_count_change > 0)
    {
        printf("Matched a brake_cmd_topic subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a subscriber\n");
    }            
}