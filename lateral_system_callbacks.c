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
#include "lateral_system_callbacks.h"

void steering_cmd_topic_dr_on_data_available(
        void *listener_data,
        DDS_DataReader * reader) {

    control_AngleDataReader *hw_reader = 
            control_AngleDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    control_Angle *sample = NULL;
    struct DDS_SampleInfoSeq info_seq = DDS_SEQUENCE_INITIALIZER;
    struct control_AngleSeq sample_seq = DDS_SEQUENCE_INITIALIZER;
    const DDS_Long TAKE_MAX_SAMPLES = 32;
    DDS_Long i;

    printf("\nGOT TO CALLBACK\n");

    retcode = control_AngleDataReader_take(
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
    for (i = 0; i < control_AngleSeq_get_length(&sample_seq); ++i) {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);
        if (sample_info->valid_data) {
            sample = control_AngleSeq_get_reference(&sample_seq, i);
            printf("\nSAMPLE RECEIVED: steering_cmd_topic\n");
            printf("\tdevice_id = %d\n", sample->device_id);
            printf("\ttheta = %f\n", sample->theta);
            printf("\tsequence num = %d %ud\n", 
                    sample_info->publication_sequence_number.high,
                    sample_info->publication_sequence_number.low);
        } else {
            printf("INFO: metadata\n");
        }
    }

    control_AngleDataReader_return_loan(hw_reader, &sample_seq, &info_seq);
    control_AngleSeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
}

void steering_cmd_topic_dr_on_subscription_matched(
        void *listener_data,
        DDS_DataReader * reader,
        const struct DDS_SubscriptionMatchedStatus *status) {
    if (status->current_count_change > 0) {
        printf("Matched a publisher: steering_cmd_topic\n");
    }
    else if (status->current_count_change < 0) {
        printf("Unmatched a publisher: steering_cmd_topic\n");
    }
}

