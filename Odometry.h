/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Odometry.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef Odometry_1402262145_h
#define Odometry_1402262145_h

#ifndef rti_me_c_h
#include "rti_me_c.h"
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

typedef struct std_msgs_msg_Time

{

    CDR_Long sec;
    CDR_UnsignedLong nanosec;

} std_msgs_msg_Time ;

#define REDA_SEQUENCE_USER_API
#define T std_msgs_msg_Time
#define TSeq std_msgs_msg_TimeSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T std_msgs_msg_Time
    #define TSeq std_msgs_msg_TimeSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    std_msgs_msg_Time_initialize(std_msgs_msg_Time* sample);

    NDDSUSERDllExport extern std_msgs_msg_Time*
    std_msgs_msg_Time_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    std_msgs_msg_Time_finalize(std_msgs_msg_Time* sample);

    NDDSUSERDllExport extern void
    std_msgs_msg_Time_delete(std_msgs_msg_Time* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    std_msgs_msg_Time_copy(std_msgs_msg_Time* dst, const std_msgs_msg_Time* src);
    #ifdef __cplusplus
}
#endif

typedef struct std_msgs_msg_Header

{

    std_msgs_msg_Time stamp;
    CDR_String frame_id;

} std_msgs_msg_Header ;

#define REDA_SEQUENCE_USER_API
#define T std_msgs_msg_Header
#define TSeq std_msgs_msg_HeaderSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T std_msgs_msg_Header
    #define TSeq std_msgs_msg_HeaderSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    std_msgs_msg_Header_initialize(std_msgs_msg_Header* sample);

    NDDSUSERDllExport extern std_msgs_msg_Header*
    std_msgs_msg_Header_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    std_msgs_msg_Header_finalize(std_msgs_msg_Header* sample);

    NDDSUSERDllExport extern void
    std_msgs_msg_Header_delete(std_msgs_msg_Header* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    std_msgs_msg_Header_copy(std_msgs_msg_Header* dst, const std_msgs_msg_Header* src);
    #ifdef __cplusplus
}
#endif

typedef struct geometry_msgs_msg_Point

{

    CDR_Double x;
    CDR_Double y;
    CDR_Double z;

} geometry_msgs_msg_Point ;

NDDSUSERDllExport extern const char *geometry_msgs_msg_PointTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Point
#define TSeq geometry_msgs_msg_PointSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_Point
    #define TSeq geometry_msgs_msg_PointSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Point_initialize(geometry_msgs_msg_Point* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_Point*
    geometry_msgs_msg_Point_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Point_finalize(geometry_msgs_msg_Point* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_Point_delete(geometry_msgs_msg_Point* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Point_copy(geometry_msgs_msg_Point* dst, const geometry_msgs_msg_Point* src);
    #ifdef __cplusplus
}
#endif

typedef struct geometry_msgs_msg_Quaternion

{

    CDR_Double x;
    CDR_Double y;
    CDR_Double z;
    CDR_Double w;

} geometry_msgs_msg_Quaternion ;

NDDSUSERDllExport extern const char *geometry_msgs_msg_QuaternionTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Quaternion
#define TSeq geometry_msgs_msg_QuaternionSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_Quaternion
    #define TSeq geometry_msgs_msg_QuaternionSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Quaternion_initialize(geometry_msgs_msg_Quaternion* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_Quaternion*
    geometry_msgs_msg_Quaternion_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Quaternion_finalize(geometry_msgs_msg_Quaternion* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_Quaternion_delete(geometry_msgs_msg_Quaternion* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Quaternion_copy(geometry_msgs_msg_Quaternion* dst, const geometry_msgs_msg_Quaternion* src);
    #ifdef __cplusplus
}
#endif

typedef struct geometry_msgs_msg_Vector3

{

    CDR_Double x;
    CDR_Double y;
    CDR_Double z;

} geometry_msgs_msg_Vector3 ;

NDDSUSERDllExport extern const char *geometry_msgs_msg_Vector3TYPENAME;

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Vector3
#define TSeq geometry_msgs_msg_Vector3Seq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_Vector3
    #define TSeq geometry_msgs_msg_Vector3Seq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Vector3_initialize(geometry_msgs_msg_Vector3* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_Vector3*
    geometry_msgs_msg_Vector3_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Vector3_finalize(geometry_msgs_msg_Vector3* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_Vector3_delete(geometry_msgs_msg_Vector3* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Vector3_copy(geometry_msgs_msg_Vector3* dst, const geometry_msgs_msg_Vector3* src);
    #ifdef __cplusplus
}
#endif

typedef struct geometry_msgs_msg_Pose

{

    geometry_msgs_msg_Point position;
    geometry_msgs_msg_Quaternion orientation;

} geometry_msgs_msg_Pose ;

NDDSUSERDllExport extern const char *geometry_msgs_msg_PoseTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Pose
#define TSeq geometry_msgs_msg_PoseSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_Pose
    #define TSeq geometry_msgs_msg_PoseSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Pose_initialize(geometry_msgs_msg_Pose* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_Pose*
    geometry_msgs_msg_Pose_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Pose_finalize(geometry_msgs_msg_Pose* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_Pose_delete(geometry_msgs_msg_Pose* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Pose_copy(geometry_msgs_msg_Pose* dst, const geometry_msgs_msg_Pose* src);
    #ifdef __cplusplus
}
#endif

typedef struct geometry_msgs_msg_Twist

{

    geometry_msgs_msg_Vector3 linear;
    geometry_msgs_msg_Vector3 angular;

} geometry_msgs_msg_Twist ;

NDDSUSERDllExport extern const char *geometry_msgs_msg_TwistTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_Twist
#define TSeq geometry_msgs_msg_TwistSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_Twist
    #define TSeq geometry_msgs_msg_TwistSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Twist_initialize(geometry_msgs_msg_Twist* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_Twist*
    geometry_msgs_msg_Twist_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Twist_finalize(geometry_msgs_msg_Twist* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_Twist_delete(geometry_msgs_msg_Twist* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Twist_copy(geometry_msgs_msg_Twist* dst, const geometry_msgs_msg_Twist* src);
    #ifdef __cplusplus
}
#endif

typedef CDR_Double geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36[36];

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36
#define TSeq geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36Seq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36
    #define TSeq geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36Seq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_initialize(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36*
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_finalize(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_delete(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_copy(geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* dst, const geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36* src);
    #ifdef __cplusplus
}
#endif

typedef struct geometry_msgs_msg_PoseWithCovariance

{

    geometry_msgs_msg_Pose pose;
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36 covariance;

} geometry_msgs_msg_PoseWithCovariance ;

NDDSUSERDllExport extern const char *geometry_msgs_msg_PoseWithCovarianceTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_PoseWithCovariance
#define TSeq geometry_msgs_msg_PoseWithCovarianceSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_PoseWithCovariance
    #define TSeq geometry_msgs_msg_PoseWithCovarianceSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_PoseWithCovariance_initialize(geometry_msgs_msg_PoseWithCovariance* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_PoseWithCovariance*
    geometry_msgs_msg_PoseWithCovariance_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_PoseWithCovariance_finalize(geometry_msgs_msg_PoseWithCovariance* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_PoseWithCovariance_delete(geometry_msgs_msg_PoseWithCovariance* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_PoseWithCovariance_copy(geometry_msgs_msg_PoseWithCovariance* dst, const geometry_msgs_msg_PoseWithCovariance* src);
    #ifdef __cplusplus
}
#endif

typedef CDR_Double geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36[36];

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36
#define TSeq geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36Seq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36
    #define TSeq geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36Seq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_initialize(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36*
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_finalize(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_delete(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_copy(geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* dst, const geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36* src);
    #ifdef __cplusplus
}
#endif

typedef struct geometry_msgs_msg_TwistWithCovariance

{

    geometry_msgs_msg_Twist twist;
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36 covariance;

} geometry_msgs_msg_TwistWithCovariance ;

NDDSUSERDllExport extern const char *geometry_msgs_msg_TwistWithCovarianceTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T geometry_msgs_msg_TwistWithCovariance
#define TSeq geometry_msgs_msg_TwistWithCovarianceSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T geometry_msgs_msg_TwistWithCovariance
    #define TSeq geometry_msgs_msg_TwistWithCovarianceSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_TwistWithCovariance_initialize(geometry_msgs_msg_TwistWithCovariance* sample);

    NDDSUSERDllExport extern geometry_msgs_msg_TwistWithCovariance*
    geometry_msgs_msg_TwistWithCovariance_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_TwistWithCovariance_finalize(geometry_msgs_msg_TwistWithCovariance* sample);

    NDDSUSERDllExport extern void
    geometry_msgs_msg_TwistWithCovariance_delete(geometry_msgs_msg_TwistWithCovariance* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_TwistWithCovariance_copy(geometry_msgs_msg_TwistWithCovariance* dst, const geometry_msgs_msg_TwistWithCovariance* src);
    #ifdef __cplusplus
}
#endif

typedef struct nav_msgs_msg_Odometry

{

    std_msgs_msg_Header header;
    CDR_String child_frame_id;
    geometry_msgs_msg_PoseWithCovariance pose;
    geometry_msgs_msg_TwistWithCovariance twist;

} nav_msgs_msg_Odometry ;

NDDSUSERDllExport extern const char *nav_msgs_msg_OdometryTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T nav_msgs_msg_Odometry
#define TSeq nav_msgs_msg_OdometrySeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T nav_msgs_msg_Odometry
    #define TSeq nav_msgs_msg_OdometrySeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern RTI_BOOL
    nav_msgs_msg_Odometry_initialize(nav_msgs_msg_Odometry* sample);

    NDDSUSERDllExport extern nav_msgs_msg_Odometry*
    nav_msgs_msg_Odometry_create(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL
    nav_msgs_msg_Odometry_finalize(nav_msgs_msg_Odometry* sample);

    NDDSUSERDllExport extern void
    nav_msgs_msg_Odometry_delete(nav_msgs_msg_Odometry* sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL
    nav_msgs_msg_Odometry_copy(nav_msgs_msg_Odometry* dst, const nav_msgs_msg_Odometry* src);
    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* Odometry */

