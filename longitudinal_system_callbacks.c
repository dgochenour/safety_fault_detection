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
#include "longitudinal_system_callbacks.h"

void throttle_cmd_topic_dr_on_data_available(
        void *listener_data,
        DDS_DataReader * reader) {

    control_EngagementDataReader *hw_reader = 
            control_EngagementDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    control_Engagement *sample = NULL;
    struct DDS_SampleInfoSeq info_seq = DDS_SEQUENCE_INITIALIZER;
    struct control_EngagementSeq sample_seq = DDS_SEQUENCE_INITIALIZER;
    const DDS_Long TAKE_MAX_SAMPLES = 32;
    DDS_Long i;

    retcode = control_EngagementDataReader_take(
            hw_reader, 
            &sample_seq, 
            &info_seq, 
            TAKE_MAX_SAMPLES, 
            DDS_ANY_SAMPLE_STATE, 
            DDS_ANY_VIEW_STATE, 
            DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK) {
        printf("failed to take data, retcode(%d)\n", retcode);
    }

    /* Print each valid sample taken */
    for (i = 0; i < control_EngagementSeq_get_length(&sample_seq); ++i) {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);
        if (sample_info->valid_data) {
            sample = control_EngagementSeq_get_reference(&sample_seq, i);
            printf("\nSAMPLE RECEIVED: throttle_cmd_topic\n");
            printf("\tdevice_id = %d\n", sample->device_id);
            printf("\tpercentage = %d\n", sample->percentage);
            printf("\tsequence num = %d %ud\n", 
                    sample_info->publication_sequence_number.high,
                    sample_info->publication_sequence_number.low);
        } else {
            printf("INFO: metadata\n");
        }
    }

    control_EngagementDataReader_return_loan(hw_reader, &sample_seq, &info_seq);
    control_EngagementSeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
}

void throttle_cmd_topic_dr_on_subscription_matched(
        void *listener_data,
        DDS_DataReader * reader,
        const struct DDS_SubscriptionMatchedStatus *status) {
    if (status->current_count_change > 0) {
        printf("Matched a publisher: throttle_cmd_topic\n");
    }
    else if (status->current_count_change < 0) {
        printf("Unmatched a publisher: throttle_cmd_topic\n");
    }
}

void brake_cmd_topic_dr_on_data_available(
        void *listener_data,
        DDS_DataReader * reader) {

    control_EngagementDataReader *hw_reader = 
            control_EngagementDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    control_Engagement *sample = NULL;
    struct DDS_SampleInfoSeq info_seq = DDS_SEQUENCE_INITIALIZER;
    struct control_EngagementSeq sample_seq = DDS_SEQUENCE_INITIALIZER;
    const DDS_Long TAKE_MAX_SAMPLES = 32;
    DDS_Long i;

    retcode = control_EngagementDataReader_take(
            hw_reader, 
            &sample_seq, 
            &info_seq, 
            TAKE_MAX_SAMPLES, 
            DDS_ANY_SAMPLE_STATE, 
            DDS_ANY_VIEW_STATE, 
            DDS_ANY_INSTANCE_STATE);\
    if (retcode != DDS_RETCODE_OK) {
        printf("failed to take data, retcode(%d)\n", retcode);
    }

    /* Print each valid sample taken */
    for (i = 0; i < control_EngagementSeq_get_length(&sample_seq); ++i) {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data) {
            sample = control_EngagementSeq_get_reference(&sample_seq, i);
            printf("\nSAMPLE RECEIVED: brake_cmd_topic\n");
            printf("\tdevice_id = %d\n", sample->device_id);
            printf("\tpercentage = %d\n", sample->percentage);
            printf("\tsequence num = %ld %lu\n", 
                    sample_info->publication_sequence_number.high,
                    sample_info->publication_sequence_number.low);
        }
    }

    control_EngagementDataReader_return_loan(hw_reader, &sample_seq, &info_seq);
    control_EngagementSeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
}

void brake_cmd_topic_dr_on_subscription_matched(
        void *listener_data,
        DDS_DataReader * reader,
        const struct DDS_SubscriptionMatchedStatus *status) {
    if (status->current_count_change > 0) {
        printf("Matched a publisher: brake_cmd_topic\n");
    }
    else if (status->current_count_change < 0) {
        printf("Unmatched a publisher: brake_cmd_topic\n");
    }
}