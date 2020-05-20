/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Odometry.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef OdometryPlugin_1402262145_h
#define OdometryPlugin_1402262145_h

#include "Odometry.h"

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Time_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Time_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    std_msgs_msg_Time_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Time_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Time_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    std_msgs_msg_Time_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Time_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Header_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Header_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    std_msgs_msg_Header_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Header_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Header_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    std_msgs_msg_Header_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    std_msgs_msg_Header_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    geometry_msgs_msg_PointTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_PointTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    geometry_msgs_msg_Point_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_PointPlugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PointPlugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PointPlugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Point_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Point_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Point_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Point_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Point_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Point_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Point_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    geometry_msgs_msg_QuaternionTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_QuaternionTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    geometry_msgs_msg_Quaternion_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_QuaternionPlugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_QuaternionPlugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_QuaternionPlugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Quaternion_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Quaternion_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Quaternion_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Quaternion_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Quaternion_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Quaternion_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Quaternion_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    geometry_msgs_msg_Vector3TypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_Vector3TypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    geometry_msgs_msg_Vector3_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_Vector3Plugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Vector3Plugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Vector3Plugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Vector3_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Vector3_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Vector3_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Vector3_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Vector3_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Vector3_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Vector3_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    geometry_msgs_msg_PoseTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_PoseTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    geometry_msgs_msg_Pose_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_PosePlugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PosePlugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PosePlugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Pose_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Pose_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Pose_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Pose_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Pose_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Pose_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Pose_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    geometry_msgs_msg_TwistTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_TwistTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    geometry_msgs_msg_Twist_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_TwistPlugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistPlugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistPlugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Twist_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Twist_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Twist_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Twist_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Twist_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_Twist_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_Twist_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    geometry_msgs_msg_PoseWithCovarianceTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_PoseWithCovarianceTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    geometry_msgs_msg_PoseWithCovariance_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_PoseWithCovariancePlugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PoseWithCovariancePlugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PoseWithCovariancePlugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PoseWithCovariance_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PoseWithCovariance_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_PoseWithCovariance_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PoseWithCovariance_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PoseWithCovariance_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_PoseWithCovariance_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_PoseWithCovariance_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    geometry_msgs_msg_TwistWithCovarianceTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    geometry_msgs_msg_TwistWithCovarianceTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    geometry_msgs_msg_TwistWithCovariance_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    geometry_msgs_msg_TwistWithCovariancePlugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistWithCovariancePlugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistWithCovariancePlugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistWithCovariance_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistWithCovariance_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_TwistWithCovariance_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistWithCovariance_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistWithCovariance_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    geometry_msgs_msg_TwistWithCovariance_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    geometry_msgs_msg_TwistWithCovariance_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
    #endif

    NDDSUSERDllExport extern struct NDDS_Type_Plugin*
    nav_msgs_msg_OdometryTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    nav_msgs_msg_OdometryTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    nav_msgs_msg_Odometry_get_key_kind(
        struct NDDS_Type_Plugin *plugin,
        void *param);
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    nav_msgs_msg_OdometryPlugin_create_sample(
        struct NDDS_Type_Plugin *plugin, void **sample,void *param);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    nav_msgs_msg_OdometryPlugin_delete_sample(
        struct NDDS_Type_Plugin *plugin, void *sample,void *param);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    nav_msgs_msg_OdometryPlugin_copy_sample(
        struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    nav_msgs_msg_Odometry_cdr_serialize(
        struct CDR_Stream_t *stream, const void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    nav_msgs_msg_Odometry_cdr_deserialize(
        struct CDR_Stream_t *stream, void *void_sample, void *param);

    NDDSUSERDllExport extern RTI_UINT32
    nav_msgs_msg_Odometry_get_serialized_sample_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    nav_msgs_msg_Odometry_cdr_serialize_key(
        struct CDR_Stream_t *keystream, const void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    nav_msgs_msg_Odometry_cdr_deserialize_key(
        struct CDR_Stream_t *keystream, void *sample,
        void *param);

    NDDSUSERDllExport extern RTI_UINT32
    nav_msgs_msg_Odometry_get_serialized_key_max_size(
        struct NDDS_Type_Plugin *plugin,
        RTI_UINT32 current_alignment,
        void *param);

    NDDSUSERDllExport extern RTI_BOOL 
    nav_msgs_msg_Odometry_instance_to_keyhash(
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream, DDS_KeyHash_t *keyHash, const void *instance,
        void *param);
    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined(RTI_WIN64) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* OdometryPlugin_1402262145_h */

