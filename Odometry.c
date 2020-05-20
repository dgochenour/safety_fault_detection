/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Odometry.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "Odometry.h"

#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

/*** SOURCE_BEGIN ***/

/* ========================================================================= */

RTI_BOOL
std_msgs_msg_Time_initialize(std_msgs_msg_Time* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_long(&sample->sec);
    CDR_Primitive_init_unsigned_long(&sample->nanosec);
    return RTI_TRUE;
}

std_msgs_msg_Time *
std_msgs_msg_Time_create(void)
{
    std_msgs_msg_Time* sample;
    OSAPI_Heap_allocate_struct(&sample, std_msgs_msg_Time);
    if (sample != NULL) {
        if (!std_msgs_msg_Time_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
std_msgs_msg_Time_finalize(std_msgs_msg_Time* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void
std_msgs_msg_Time_delete(std_msgs_msg_Time*sample)
{
    if (sample != NULL) {
        /* std_msgs_msg_Time_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        std_msgs_msg_Time_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
std_msgs_msg_Time_copy(std_msgs_msg_Time* dst,const std_msgs_msg_Time* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_long(&dst->sec, &src->sec);
    CDR_Primitive_copy_unsigned_long(&dst->nanosec, &src->nanosec);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'std_msgs_msg_Time' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T std_msgs_msg_Time
#define TSeq std_msgs_msg_TimeSeq
#define T_initialize std_msgs_msg_Time_initialize
#define T_finalize   std_msgs_msg_Time_finalize
#define T_copy       std_msgs_msg_Time_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

RTI_BOOL
std_msgs_msg_Header_initialize(std_msgs_msg_Header* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!std_msgs_msg_Time_initialize(&sample->stamp)) {
        return RTI_FALSE;
    }
    if (!CDR_String_initialize(&sample->frame_id, (255)))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

std_msgs_msg_Header *
std_msgs_msg_Header_create(void)
{
    std_msgs_msg_Header* sample;
    OSAPI_Heap_allocate_struct(&sample, std_msgs_msg_Header);
    if (sample != NULL) {
        if (!std_msgs_msg_Header_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
std_msgs_msg_Header_finalize(std_msgs_msg_Header* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    std_msgs_msg_Time_finalize(&sample->stamp);
    CDR_String_finalize(&sample->frame_id);
    return RTI_TRUE;
}

void
std_msgs_msg_Header_delete(std_msgs_msg_Header*sample)
{
    if (sample != NULL) {
        /* std_msgs_msg_Header_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        std_msgs_msg_Header_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
std_msgs_msg_Header_copy(std_msgs_msg_Header* dst,const std_msgs_msg_Header* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if (!std_msgs_msg_Time_copy(
        &dst->stamp, &src->stamp)) {
        return RTI_FALSE;
    }
    if (!CDR_String_copy(&dst->frame_id, &src->frame_id, (255)))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'std_msgs_msg_Header' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T std_msgs_msg_Header
#define TSeq std_msgs_msg_HeaderSeq
#define T_initialize std_msgs_msg_Header_initialize
#define T_finalize   std_msgs_msg_Header_finalize
#define T_copy       std_msgs_msg_Header_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *geometry_msgs_msg_PointTYPENAME = "geometry_msgs::msg::Point";

RTI_BOOL
geometry_msgs_msg_Point_initialize(geometry_msgs_msg_Point* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_double(&sample->x);
    CDR_Primitive_init_double(&sample->y);
    CDR_Primitive_init_double(&sample->z);
    return RTI_TRUE;
}

geometry_msgs_msg_Point *
geometry_msgs_msg_Point_create(void)
{
    geometry_msgs_msg_Point* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_Point);
    if (sample != NULL) {
        if (!geometry_msgs_msg_Point_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_Point_finalize(geometry_msgs_msg_Point* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void
geometry_msgs_msg_Point_delete(geometry_msgs_msg_Point*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_Point_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_Point_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_Point_copy(geometry_msgs_msg_Point* dst,const geometry_msgs_msg_Point* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_double(&dst->x, &src->x);
    CDR_Primitive_copy_double(&dst->y, &src->y);
    CDR_Primitive_copy_double(&dst->z, &src->z);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_Point' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Point
#define TSeq geometry_msgs_msg_PointSeq
#define T_initialize geometry_msgs_msg_Point_initialize
#define T_finalize   geometry_msgs_msg_Point_finalize
#define T_copy       geometry_msgs_msg_Point_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *geometry_msgs_msg_QuaternionTYPENAME = "geometry_msgs::msg::Quaternion";

RTI_BOOL
geometry_msgs_msg_Quaternion_initialize(geometry_msgs_msg_Quaternion* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_double(&sample->x);
    CDR_Primitive_init_double(&sample->y);
    CDR_Primitive_init_double(&sample->z);
    CDR_Primitive_init_double(&sample->w);
    return RTI_TRUE;
}

geometry_msgs_msg_Quaternion *
geometry_msgs_msg_Quaternion_create(void)
{
    geometry_msgs_msg_Quaternion* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_Quaternion);
    if (sample != NULL) {
        if (!geometry_msgs_msg_Quaternion_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_Quaternion_finalize(geometry_msgs_msg_Quaternion* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void
geometry_msgs_msg_Quaternion_delete(geometry_msgs_msg_Quaternion*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_Quaternion_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_Quaternion_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_Quaternion_copy(geometry_msgs_msg_Quaternion* dst,const geometry_msgs_msg_Quaternion* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_double(&dst->x, &src->x);
    CDR_Primitive_copy_double(&dst->y, &src->y);
    CDR_Primitive_copy_double(&dst->z, &src->z);
    CDR_Primitive_copy_double(&dst->w, &src->w);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_Quaternion' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Quaternion
#define TSeq geometry_msgs_msg_QuaternionSeq
#define T_initialize geometry_msgs_msg_Quaternion_initialize
#define T_finalize   geometry_msgs_msg_Quaternion_finalize
#define T_copy       geometry_msgs_msg_Quaternion_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *geometry_msgs_msg_Vector3TYPENAME = "geometry_msgs::msg::Vector3";

RTI_BOOL
geometry_msgs_msg_Vector3_initialize(geometry_msgs_msg_Vector3* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_double(&sample->x);
    CDR_Primitive_init_double(&sample->y);
    CDR_Primitive_init_double(&sample->z);
    return RTI_TRUE;
}

geometry_msgs_msg_Vector3 *
geometry_msgs_msg_Vector3_create(void)
{
    geometry_msgs_msg_Vector3* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_Vector3);
    if (sample != NULL) {
        if (!geometry_msgs_msg_Vector3_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_Vector3_finalize(geometry_msgs_msg_Vector3* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void
geometry_msgs_msg_Vector3_delete(geometry_msgs_msg_Vector3*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_Vector3_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_Vector3_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_Vector3_copy(geometry_msgs_msg_Vector3* dst,const geometry_msgs_msg_Vector3* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_double(&dst->x, &src->x);
    CDR_Primitive_copy_double(&dst->y, &src->y);
    CDR_Primitive_copy_double(&dst->z, &src->z);
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_Vector3' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Vector3
#define TSeq geometry_msgs_msg_Vector3Seq
#define T_initialize geometry_msgs_msg_Vector3_initialize
#define T_finalize   geometry_msgs_msg_Vector3_finalize
#define T_copy       geometry_msgs_msg_Vector3_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *geometry_msgs_msg_PoseTYPENAME = "geometry_msgs::msg::Pose";

RTI_BOOL
geometry_msgs_msg_Pose_initialize(geometry_msgs_msg_Pose* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!geometry_msgs_msg_Point_initialize(&sample->position)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Quaternion_initialize(&sample->orientation)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

geometry_msgs_msg_Pose *
geometry_msgs_msg_Pose_create(void)
{
    geometry_msgs_msg_Pose* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_Pose);
    if (sample != NULL) {
        if (!geometry_msgs_msg_Pose_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_Pose_finalize(geometry_msgs_msg_Pose* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    geometry_msgs_msg_Point_finalize(&sample->position);
    geometry_msgs_msg_Quaternion_finalize(&sample->orientation);
    return RTI_TRUE;
}

void
geometry_msgs_msg_Pose_delete(geometry_msgs_msg_Pose*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_Pose_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_Pose_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_Pose_copy(geometry_msgs_msg_Pose* dst,const geometry_msgs_msg_Pose* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Point_copy(
        &dst->position, &src->position)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Quaternion_copy(
        &dst->orientation, &src->orientation)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_Pose' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Pose
#define TSeq geometry_msgs_msg_PoseSeq
#define T_initialize geometry_msgs_msg_Pose_initialize
#define T_finalize   geometry_msgs_msg_Pose_finalize
#define T_copy       geometry_msgs_msg_Pose_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *geometry_msgs_msg_TwistTYPENAME = "geometry_msgs::msg::Twist";

RTI_BOOL
geometry_msgs_msg_Twist_initialize(geometry_msgs_msg_Twist* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!geometry_msgs_msg_Vector3_initialize(&sample->linear)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Vector3_initialize(&sample->angular)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

geometry_msgs_msg_Twist *
geometry_msgs_msg_Twist_create(void)
{
    geometry_msgs_msg_Twist* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_Twist);
    if (sample != NULL) {
        if (!geometry_msgs_msg_Twist_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_Twist_finalize(geometry_msgs_msg_Twist* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    geometry_msgs_msg_Vector3_finalize(&sample->linear);
    geometry_msgs_msg_Vector3_finalize(&sample->angular);
    return RTI_TRUE;
}

void
geometry_msgs_msg_Twist_delete(geometry_msgs_msg_Twist*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_Twist_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_Twist_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_Twist_copy(geometry_msgs_msg_Twist* dst,const geometry_msgs_msg_Twist* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Vector3_copy(
        &dst->linear, &src->linear)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Vector3_copy(
        &dst->angular, &src->angular)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_Twist' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Twist
#define TSeq geometry_msgs_msg_TwistSeq
#define T_initialize geometry_msgs_msg_Twist_initialize
#define T_finalize   geometry_msgs_msg_Twist_finalize
#define T_copy       geometry_msgs_msg_Twist_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

RTI_BOOL
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_initialize(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_array(
        (*sample), ((36)*CDR_DOUBLE_SIZE));
    return RTI_TRUE;
}

geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36 *
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_create(void)
{
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36);
    if (sample != NULL) {
        if (!geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_finalize(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_delete(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_copy(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* dst,const geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_array( (*dst), (*src),((36)*CDR_DOUBLE_SIZE));
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36
#define TSeq geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36Seq
#define T_initialize geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_initialize
#define T_finalize   geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_finalize
#define T_copy       geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *geometry_msgs_msg_PoseWithCovarianceTYPENAME = "geometry_msgs::msg::PoseWithCovariance";

RTI_BOOL
geometry_msgs_msg_PoseWithCovariance_initialize(geometry_msgs_msg_PoseWithCovariance* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!geometry_msgs_msg_Pose_initialize(&sample->pose)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_initialize(&sample->covariance)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

geometry_msgs_msg_PoseWithCovariance *
geometry_msgs_msg_PoseWithCovariance_create(void)
{
    geometry_msgs_msg_PoseWithCovariance* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_PoseWithCovariance);
    if (sample != NULL) {
        if (!geometry_msgs_msg_PoseWithCovariance_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_PoseWithCovariance_finalize(geometry_msgs_msg_PoseWithCovariance* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    geometry_msgs_msg_Pose_finalize(&sample->pose);
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_finalize(&sample->covariance);
    return RTI_TRUE;
}

void
geometry_msgs_msg_PoseWithCovariance_delete(geometry_msgs_msg_PoseWithCovariance*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_PoseWithCovariance_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_PoseWithCovariance_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_PoseWithCovariance_copy(geometry_msgs_msg_PoseWithCovariance* dst,const geometry_msgs_msg_PoseWithCovariance* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Pose_copy(
        &dst->pose, &src->pose)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_copy(
        &dst->covariance, &src->covariance)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_PoseWithCovariance' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_PoseWithCovariance
#define TSeq geometry_msgs_msg_PoseWithCovarianceSeq
#define T_initialize geometry_msgs_msg_PoseWithCovariance_initialize
#define T_finalize   geometry_msgs_msg_PoseWithCovariance_finalize
#define T_copy       geometry_msgs_msg_PoseWithCovariance_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

RTI_BOOL
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_initialize(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    CDR_Primitive_init_array(
        (*sample), ((36)*CDR_DOUBLE_SIZE));
    return RTI_TRUE;
}

geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36 *
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_create(void)
{
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36);
    if (sample != NULL) {
        if (!geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_finalize(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_delete(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_copy(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* dst,const geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    CDR_Primitive_copy_array( (*dst), (*src),((36)*CDR_DOUBLE_SIZE));
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36
#define TSeq geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36Seq
#define T_initialize geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_initialize
#define T_finalize   geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_finalize
#define T_copy       geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *geometry_msgs_msg_TwistWithCovarianceTYPENAME = "geometry_msgs::msg::TwistWithCovariance";

RTI_BOOL
geometry_msgs_msg_TwistWithCovariance_initialize(geometry_msgs_msg_TwistWithCovariance* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!geometry_msgs_msg_Twist_initialize(&sample->twist)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_initialize(&sample->covariance)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

geometry_msgs_msg_TwistWithCovariance *
geometry_msgs_msg_TwistWithCovariance_create(void)
{
    geometry_msgs_msg_TwistWithCovariance* sample;
    OSAPI_Heap_allocate_struct(&sample, geometry_msgs_msg_TwistWithCovariance);
    if (sample != NULL) {
        if (!geometry_msgs_msg_TwistWithCovariance_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
geometry_msgs_msg_TwistWithCovariance_finalize(geometry_msgs_msg_TwistWithCovariance* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    geometry_msgs_msg_Twist_finalize(&sample->twist);
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_finalize(&sample->covariance);
    return RTI_TRUE;
}

void
geometry_msgs_msg_TwistWithCovariance_delete(geometry_msgs_msg_TwistWithCovariance*sample)
{
    if (sample != NULL) {
        /* geometry_msgs_msg_TwistWithCovariance_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        geometry_msgs_msg_TwistWithCovariance_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
geometry_msgs_msg_TwistWithCovariance_copy(geometry_msgs_msg_TwistWithCovariance* dst,const geometry_msgs_msg_TwistWithCovariance* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_Twist_copy(
        &dst->twist, &src->twist)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_copy(
        &dst->covariance, &src->covariance)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'geometry_msgs_msg_TwistWithCovariance' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_TwistWithCovariance
#define TSeq geometry_msgs_msg_TwistWithCovarianceSeq
#define T_initialize geometry_msgs_msg_TwistWithCovariance_initialize
#define T_finalize   geometry_msgs_msg_TwistWithCovariance_finalize
#define T_copy       geometry_msgs_msg_TwistWithCovariance_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

/* ========================================================================= */

const char *nav_msgs_msg_OdometryTYPENAME = "nav_msgs::msg::Odometry";

RTI_BOOL
nav_msgs_msg_Odometry_initialize(nav_msgs_msg_Odometry* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    if (!std_msgs_msg_Header_initialize(&sample->header)) {
        return RTI_FALSE;
    }
    if (!CDR_String_initialize(&sample->child_frame_id, (255)))
    {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_PoseWithCovariance_initialize(&sample->pose)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_TwistWithCovariance_initialize(&sample->twist)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

nav_msgs_msg_Odometry *
nav_msgs_msg_Odometry_create(void)
{
    nav_msgs_msg_Odometry* sample;
    OSAPI_Heap_allocate_struct(&sample, nav_msgs_msg_Odometry);
    if (sample != NULL) {
        if (!nav_msgs_msg_Odometry_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

#ifndef RTI_CERT

RTI_BOOL
nav_msgs_msg_Odometry_finalize(nav_msgs_msg_Odometry* sample)
{
    if (sample == NULL)
    {
        return RTI_FALSE;
    }

    std_msgs_msg_Header_finalize(&sample->header);
    CDR_String_finalize(&sample->child_frame_id);
    geometry_msgs_msg_PoseWithCovariance_finalize(&sample->pose);
    geometry_msgs_msg_TwistWithCovariance_finalize(&sample->twist);
    return RTI_TRUE;
}

void
nav_msgs_msg_Odometry_delete(nav_msgs_msg_Odometry*sample)
{
    if (sample != NULL) {
        /* nav_msgs_msg_Odometry_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        nav_msgs_msg_Odometry_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}
#endif

RTI_BOOL
nav_msgs_msg_Odometry_copy(nav_msgs_msg_Odometry* dst,const nav_msgs_msg_Odometry* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return RTI_FALSE;
    }
    if (!std_msgs_msg_Header_copy(
        &dst->header, &src->header)) {
        return RTI_FALSE;
    }
    if (!CDR_String_copy(&dst->child_frame_id, &src->child_frame_id, (255)))
    {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_PoseWithCovariance_copy(
        &dst->pose, &src->pose)) {
        return RTI_FALSE;
    }
    if (!geometry_msgs_msg_TwistWithCovariance_copy(
        &dst->twist, &src->twist)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'nav_msgs_msg_Odometry' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T nav_msgs_msg_Odometry
#define TSeq nav_msgs_msg_OdometrySeq
#define T_initialize nav_msgs_msg_Odometry_initialize
#define T_finalize   nav_msgs_msg_Odometry_finalize
#define T_copy       nav_msgs_msg_Odometry_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

