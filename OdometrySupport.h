/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Odometry.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef OdometrySupport_1402262145_h
#define OdometrySupport_1402262145_h

#include <stdlib.h>

/* Uses */
#include "Odometry.h"
/* Requires */
#include "OdometryPlugin.h"

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_PointTypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_PointTypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_PointTypeSupport_get_type_name(void);

    NDDSUSERDllExport extern geometry_msgs_msg_Point *
    geometry_msgs_msg_PointTypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    geometry_msgs_msg_PointTypeSupport_delete_data(
        geometry_msgs_msg_Point *data);
    #endif

    DDS_DATAWRITER_C(geometry_msgs_msg_PointDataWriter, geometry_msgs_msg_Point);

    DDS_DATAREADER_C(geometry_msgs_msg_PointDataReader, geometry_msgs_msg_PointSeq, geometry_msgs_msg_Point);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_QuaternionTypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_QuaternionTypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_QuaternionTypeSupport_get_type_name(void);

    NDDSUSERDllExport extern geometry_msgs_msg_Quaternion *
    geometry_msgs_msg_QuaternionTypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    geometry_msgs_msg_QuaternionTypeSupport_delete_data(
        geometry_msgs_msg_Quaternion *data);
    #endif

    DDS_DATAWRITER_C(geometry_msgs_msg_QuaternionDataWriter, geometry_msgs_msg_Quaternion);

    DDS_DATAREADER_C(geometry_msgs_msg_QuaternionDataReader, geometry_msgs_msg_QuaternionSeq, geometry_msgs_msg_Quaternion);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_Vector3TypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_Vector3TypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_Vector3TypeSupport_get_type_name(void);

    NDDSUSERDllExport extern geometry_msgs_msg_Vector3 *
    geometry_msgs_msg_Vector3TypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    geometry_msgs_msg_Vector3TypeSupport_delete_data(
        geometry_msgs_msg_Vector3 *data);
    #endif

    DDS_DATAWRITER_C(geometry_msgs_msg_Vector3DataWriter, geometry_msgs_msg_Vector3);

    DDS_DATAREADER_C(geometry_msgs_msg_Vector3DataReader, geometry_msgs_msg_Vector3Seq, geometry_msgs_msg_Vector3);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_PoseTypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_PoseTypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_PoseTypeSupport_get_type_name(void);

    NDDSUSERDllExport extern geometry_msgs_msg_Pose *
    geometry_msgs_msg_PoseTypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    geometry_msgs_msg_PoseTypeSupport_delete_data(
        geometry_msgs_msg_Pose *data);
    #endif

    DDS_DATAWRITER_C(geometry_msgs_msg_PoseDataWriter, geometry_msgs_msg_Pose);

    DDS_DATAREADER_C(geometry_msgs_msg_PoseDataReader, geometry_msgs_msg_PoseSeq, geometry_msgs_msg_Pose);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_TwistTypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_TwistTypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_TwistTypeSupport_get_type_name(void);

    NDDSUSERDllExport extern geometry_msgs_msg_Twist *
    geometry_msgs_msg_TwistTypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    geometry_msgs_msg_TwistTypeSupport_delete_data(
        geometry_msgs_msg_Twist *data);
    #endif

    DDS_DATAWRITER_C(geometry_msgs_msg_TwistDataWriter, geometry_msgs_msg_Twist);

    DDS_DATAREADER_C(geometry_msgs_msg_TwistDataReader, geometry_msgs_msg_TwistSeq, geometry_msgs_msg_Twist);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_PoseWithCovarianceTypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_PoseWithCovarianceTypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_PoseWithCovarianceTypeSupport_get_type_name(void);

    NDDSUSERDllExport extern geometry_msgs_msg_PoseWithCovariance *
    geometry_msgs_msg_PoseWithCovarianceTypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    geometry_msgs_msg_PoseWithCovarianceTypeSupport_delete_data(
        geometry_msgs_msg_PoseWithCovariance *data);
    #endif

    DDS_DATAWRITER_C(geometry_msgs_msg_PoseWithCovarianceDataWriter, geometry_msgs_msg_PoseWithCovariance);

    DDS_DATAREADER_C(geometry_msgs_msg_PoseWithCovarianceDataReader, geometry_msgs_msg_PoseWithCovarianceSeq, geometry_msgs_msg_PoseWithCovariance);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_TwistWithCovarianceTypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    geometry_msgs_msg_TwistWithCovarianceTypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_TwistWithCovarianceTypeSupport_get_type_name(void);

    NDDSUSERDllExport extern geometry_msgs_msg_TwistWithCovariance *
    geometry_msgs_msg_TwistWithCovarianceTypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    geometry_msgs_msg_TwistWithCovarianceTypeSupport_delete_data(
        geometry_msgs_msg_TwistWithCovariance *data);
    #endif

    DDS_DATAWRITER_C(geometry_msgs_msg_TwistWithCovarianceDataWriter, geometry_msgs_msg_TwistWithCovariance);

    DDS_DATAREADER_C(geometry_msgs_msg_TwistWithCovarianceDataReader, geometry_msgs_msg_TwistWithCovarianceSeq, geometry_msgs_msg_TwistWithCovariance);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern DDS_ReturnCode_t
    nav_msgs_msg_OdometryTypeSupport_register_type(
        DDS_DomainParticipant* participant,
        const char* type_name);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern DDS_ReturnCode_t
    nav_msgs_msg_OdometryTypeSupport_unregister_type(
        DDS_DomainParticipant* participant,
        const char* type_name);
    #endif

    NDDSUSERDllExport extern const char*
    nav_msgs_msg_OdometryTypeSupport_get_type_name(void);

    NDDSUSERDllExport extern nav_msgs_msg_Odometry *
    nav_msgs_msg_OdometryTypeSupport_create_data(void);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern void
    nav_msgs_msg_OdometryTypeSupport_delete_data(
        nav_msgs_msg_Odometry *data);
    #endif

    DDS_DATAWRITER_C(nav_msgs_msg_OdometryDataWriter, nav_msgs_msg_Odometry);

    DDS_DATAREADER_C(nav_msgs_msg_OdometryDataReader, nav_msgs_msg_OdometrySeq, nav_msgs_msg_Odometry);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif  /* OdometrySupport_1402262145_h */

