/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Odometry.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "Odometry.h"
#include "OdometryPlugin.h"

/*** SOURCE_BEGIN ***/
#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
std_msgs_msg_Time_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    std_msgs_msg_Time *sample = (std_msgs_msg_Time *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_long(
        stream, &sample->sec)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_unsigned_long(
        stream, &sample->nanosec)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_BOOL 
std_msgs_msg_Time_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    std_msgs_msg_Time *sample = (std_msgs_msg_Time *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_long(
        stream, &sample->sec)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_unsigned_long(
        stream, &sample->nanosec)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;

}

RTI_UINT32
std_msgs_msg_Time_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_long(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_unsigned_long(
        current_alignment);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
std_msgs_msg_Time_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return std_msgs_msg_Time_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
std_msgs_msg_Time_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return std_msgs_msg_Time_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
std_msgs_msg_Time_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return std_msgs_msg_Time_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
std_msgs_msg_Header_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    std_msgs_msg_Header *sample = (std_msgs_msg_Header *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!std_msgs_msg_Time_cdr_serialize(
        stream,
        &sample->stamp,
        param)) {
        return RTI_FALSE;
    }
    if (!CDR_Stream_serialize_string(
        stream, sample->frame_id, (255))) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
std_msgs_msg_Header_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    std_msgs_msg_Header *sample = (std_msgs_msg_Header *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!std_msgs_msg_Time_cdr_deserialize(
        stream,
        &sample->stamp,
        param)) {
        return RTI_FALSE;
    }
    if (!CDR_Stream_deserialize_string(
        stream, sample->frame_id, (255))) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
std_msgs_msg_Header_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += std_msgs_msg_Time_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += CDR_get_max_size_serialized_string(
        current_alignment, (255)+1);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
std_msgs_msg_Header_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return std_msgs_msg_Header_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
std_msgs_msg_Header_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return std_msgs_msg_Header_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
std_msgs_msg_Header_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return std_msgs_msg_Header_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_Point_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_Point *sample = (geometry_msgs_msg_Point *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_double(
        stream, &sample->x)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->y)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->z)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_Point_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_Point *sample = (geometry_msgs_msg_Point *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_double(
        stream, &sample->x)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->y)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->z)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_Point_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_Point_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_Point_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_Point_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_Point_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_Point_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_Point_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_PointPlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) geometry_msgs_msg_Point_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
geometry_msgs_msg_PointPlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* geometry_msgs_msg_Point_delete() is a void function
    which expects (sample != NULL). Since geometry_msgs_msg_PointPlugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    geometry_msgs_msg_Point_delete((geometry_msgs_msg_Point *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
geometry_msgs_msg_PointPlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return geometry_msgs_msg_Point_copy(
        (geometry_msgs_msg_Point *)dst,
        (const geometry_msgs_msg_Point *)src);
}
/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Point Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation geometry_msgs_msg_PointEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin geometry_msgs_msg_PointTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    geometry_msgs_msg_PointEncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    geometry_msgs_msg_Point_cdr_serialize,
    geometry_msgs_msg_Point_cdr_deserialize,
    geometry_msgs_msg_Point_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    geometry_msgs_msg_PointPlugin_create_sample,
    #ifndef RTI_CERT
    geometry_msgs_msg_PointPlugin_delete_sample,
    #else
    NULL,
    #endif
    geometry_msgs_msg_PointPlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Point Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
geometry_msgs_msg_PointTypePlugin_get(void) 
{ 
    return &geometry_msgs_msg_PointTypePlugin;
} 

const char*
geometry_msgs_msg_PointTypePlugin_get_default_type_name(void) 
{ 
    return geometry_msgs_msg_PointTYPENAME;
} 

NDDS_TypePluginKeyKind 
geometry_msgs_msg_Point_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_Quaternion_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_Quaternion *sample = (geometry_msgs_msg_Quaternion *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_double(
        stream, &sample->x)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->y)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->z)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->w)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_Quaternion_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_Quaternion *sample = (geometry_msgs_msg_Quaternion *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_double(
        stream, &sample->x)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->y)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->z)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->w)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_Quaternion_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_Quaternion_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_Quaternion_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_Quaternion_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_Quaternion_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_Quaternion_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_Quaternion_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_QuaternionPlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) geometry_msgs_msg_Quaternion_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
geometry_msgs_msg_QuaternionPlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* geometry_msgs_msg_Quaternion_delete() is a void function
    which expects (sample != NULL). Since geometry_msgs_msg_QuaternionPlugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    geometry_msgs_msg_Quaternion_delete((geometry_msgs_msg_Quaternion *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
geometry_msgs_msg_QuaternionPlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return geometry_msgs_msg_Quaternion_copy(
        (geometry_msgs_msg_Quaternion *)dst,
        (const geometry_msgs_msg_Quaternion *)src);
}
/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Quaternion Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation geometry_msgs_msg_QuaternionEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin geometry_msgs_msg_QuaternionTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    geometry_msgs_msg_QuaternionEncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    geometry_msgs_msg_Quaternion_cdr_serialize,
    geometry_msgs_msg_Quaternion_cdr_deserialize,
    geometry_msgs_msg_Quaternion_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    geometry_msgs_msg_QuaternionPlugin_create_sample,
    #ifndef RTI_CERT
    geometry_msgs_msg_QuaternionPlugin_delete_sample,
    #else
    NULL,
    #endif
    geometry_msgs_msg_QuaternionPlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Quaternion Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
geometry_msgs_msg_QuaternionTypePlugin_get(void) 
{ 
    return &geometry_msgs_msg_QuaternionTypePlugin;
} 

const char*
geometry_msgs_msg_QuaternionTypePlugin_get_default_type_name(void) 
{ 
    return geometry_msgs_msg_QuaternionTYPENAME;
} 

NDDS_TypePluginKeyKind 
geometry_msgs_msg_Quaternion_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_Vector3_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_Vector3 *sample = (geometry_msgs_msg_Vector3 *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_double(
        stream, &sample->x)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->y)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_serialize_double(
        stream, &sample->z)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_Vector3_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_Vector3 *sample = (geometry_msgs_msg_Vector3 *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_double(
        stream, &sample->x)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->y)) {
        return RTI_FALSE;
    }  
    if (!CDR_Stream_deserialize_double(
        stream, &sample->z)) {
        return RTI_FALSE;
    }  

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_Vector3_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    current_alignment += CDR_get_max_size_serialized_double(
        current_alignment);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_Vector3_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_Vector3_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_Vector3_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_Vector3_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_Vector3_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_Vector3_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_Vector3Plugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) geometry_msgs_msg_Vector3_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
geometry_msgs_msg_Vector3Plugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* geometry_msgs_msg_Vector3_delete() is a void function
    which expects (sample != NULL). Since geometry_msgs_msg_Vector3Plugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    geometry_msgs_msg_Vector3_delete((geometry_msgs_msg_Vector3 *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
geometry_msgs_msg_Vector3Plugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return geometry_msgs_msg_Vector3_copy(
        (geometry_msgs_msg_Vector3 *)dst,
        (const geometry_msgs_msg_Vector3 *)src);
}
/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Vector3 Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation geometry_msgs_msg_Vector3EncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin geometry_msgs_msg_Vector3TypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    geometry_msgs_msg_Vector3EncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    geometry_msgs_msg_Vector3_cdr_serialize,
    geometry_msgs_msg_Vector3_cdr_deserialize,
    geometry_msgs_msg_Vector3_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    geometry_msgs_msg_Vector3Plugin_create_sample,
    #ifndef RTI_CERT
    geometry_msgs_msg_Vector3Plugin_delete_sample,
    #else
    NULL,
    #endif
    geometry_msgs_msg_Vector3Plugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Vector3 Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
geometry_msgs_msg_Vector3TypePlugin_get(void) 
{ 
    return &geometry_msgs_msg_Vector3TypePlugin;
} 

const char*
geometry_msgs_msg_Vector3TypePlugin_get_default_type_name(void) 
{ 
    return geometry_msgs_msg_Vector3TYPENAME;
} 

NDDS_TypePluginKeyKind 
geometry_msgs_msg_Vector3_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_Pose_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_Pose *sample = (geometry_msgs_msg_Pose *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Point_cdr_serialize(
        stream,
        &sample->position,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_Quaternion_cdr_serialize(
        stream,
        &sample->orientation,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_Pose_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_Pose *sample = (geometry_msgs_msg_Pose *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Point_cdr_deserialize(
        stream,
        &sample->position,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_Quaternion_cdr_deserialize(
        stream,
        &sample->orientation,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_Pose_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += geometry_msgs_msg_Point_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += geometry_msgs_msg_Quaternion_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_Pose_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_Pose_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_Pose_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_Pose_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_Pose_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_Pose_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_PosePlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) geometry_msgs_msg_Pose_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
geometry_msgs_msg_PosePlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* geometry_msgs_msg_Pose_delete() is a void function
    which expects (sample != NULL). Since geometry_msgs_msg_PosePlugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    geometry_msgs_msg_Pose_delete((geometry_msgs_msg_Pose *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
geometry_msgs_msg_PosePlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return geometry_msgs_msg_Pose_copy(
        (geometry_msgs_msg_Pose *)dst,
        (const geometry_msgs_msg_Pose *)src);
}
/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Pose Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation geometry_msgs_msg_PoseEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin geometry_msgs_msg_PoseTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    geometry_msgs_msg_PoseEncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    geometry_msgs_msg_Pose_cdr_serialize,
    geometry_msgs_msg_Pose_cdr_deserialize,
    geometry_msgs_msg_Pose_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    geometry_msgs_msg_PosePlugin_create_sample,
    #ifndef RTI_CERT
    geometry_msgs_msg_PosePlugin_delete_sample,
    #else
    NULL,
    #endif
    geometry_msgs_msg_PosePlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Pose Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
geometry_msgs_msg_PoseTypePlugin_get(void) 
{ 
    return &geometry_msgs_msg_PoseTypePlugin;
} 

const char*
geometry_msgs_msg_PoseTypePlugin_get_default_type_name(void) 
{ 
    return geometry_msgs_msg_PoseTYPENAME;
} 

NDDS_TypePluginKeyKind 
geometry_msgs_msg_Pose_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_Twist_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_Twist *sample = (geometry_msgs_msg_Twist *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Vector3_cdr_serialize(
        stream,
        &sample->linear,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_Vector3_cdr_serialize(
        stream,
        &sample->angular,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_Twist_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_Twist *sample = (geometry_msgs_msg_Twist *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Vector3_cdr_deserialize(
        stream,
        &sample->linear,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_Vector3_cdr_deserialize(
        stream,
        &sample->angular,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_Twist_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += geometry_msgs_msg_Vector3_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += geometry_msgs_msg_Vector3_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_Twist_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_Twist_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_Twist_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_Twist_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_Twist_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_Twist_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_TwistPlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) geometry_msgs_msg_Twist_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
geometry_msgs_msg_TwistPlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* geometry_msgs_msg_Twist_delete() is a void function
    which expects (sample != NULL). Since geometry_msgs_msg_TwistPlugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    geometry_msgs_msg_Twist_delete((geometry_msgs_msg_Twist *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
geometry_msgs_msg_TwistPlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return geometry_msgs_msg_Twist_copy(
        (geometry_msgs_msg_Twist *)dst,
        (const geometry_msgs_msg_Twist *)src);
}
/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Twist Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation geometry_msgs_msg_TwistEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin geometry_msgs_msg_TwistTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    geometry_msgs_msg_TwistEncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    geometry_msgs_msg_Twist_cdr_serialize,
    geometry_msgs_msg_Twist_cdr_deserialize,
    geometry_msgs_msg_Twist_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    geometry_msgs_msg_TwistPlugin_create_sample,
    #ifndef RTI_CERT
    geometry_msgs_msg_TwistPlugin_delete_sample,
    #else
    NULL,
    #endif
    geometry_msgs_msg_TwistPlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_Twist Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
geometry_msgs_msg_TwistTypePlugin_get(void) 
{ 
    return &geometry_msgs_msg_TwistTypePlugin;
} 

const char*
geometry_msgs_msg_TwistTypePlugin_get_default_type_name(void) 
{ 
    return geometry_msgs_msg_TwistTYPENAME;
} 

NDDS_TypePluginKeyKind 
geometry_msgs_msg_Twist_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36 *sample = (geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36 *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_primitive_array(
        stream,
        (void*)*sample,
        (36),
        CDR_DOUBLE_TYPE)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36 *sample = (geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36 *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_primitive_array(
        stream,
        (void*)*sample,
        (36),
        CDR_DOUBLE_TYPE)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_primitive_array(
        current_alignment, (36), CDR_DOUBLE_TYPE);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_PoseWithCovariance_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_PoseWithCovariance *sample = (geometry_msgs_msg_PoseWithCovariance *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Pose_cdr_serialize(
        stream,
        &sample->pose,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_serialize(
        stream,
        &sample->covariance,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_PoseWithCovariance_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_PoseWithCovariance *sample = (geometry_msgs_msg_PoseWithCovariance *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Pose_cdr_deserialize(
        stream,
        &sample->pose,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_cdr_deserialize(
        stream,
        &sample->covariance,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_PoseWithCovariance_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += geometry_msgs_msg_Pose_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += geometry_msgs_msg_geometry_msgs__PoseWithCovariance__double_array_36_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_PoseWithCovariance_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_PoseWithCovariance_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_PoseWithCovariance_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_PoseWithCovariance_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_PoseWithCovariance_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_PoseWithCovariance_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_PoseWithCovariancePlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) geometry_msgs_msg_PoseWithCovariance_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
geometry_msgs_msg_PoseWithCovariancePlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* geometry_msgs_msg_PoseWithCovariance_delete() is a void function
    which expects (sample != NULL). Since geometry_msgs_msg_PoseWithCovariancePlugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    geometry_msgs_msg_PoseWithCovariance_delete((geometry_msgs_msg_PoseWithCovariance *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
geometry_msgs_msg_PoseWithCovariancePlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return geometry_msgs_msg_PoseWithCovariance_copy(
        (geometry_msgs_msg_PoseWithCovariance *)dst,
        (const geometry_msgs_msg_PoseWithCovariance *)src);
}
/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_PoseWithCovariance Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation geometry_msgs_msg_PoseWithCovarianceEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin geometry_msgs_msg_PoseWithCovarianceTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    geometry_msgs_msg_PoseWithCovarianceEncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    geometry_msgs_msg_PoseWithCovariance_cdr_serialize,
    geometry_msgs_msg_PoseWithCovariance_cdr_deserialize,
    geometry_msgs_msg_PoseWithCovariance_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    geometry_msgs_msg_PoseWithCovariancePlugin_create_sample,
    #ifndef RTI_CERT
    geometry_msgs_msg_PoseWithCovariancePlugin_delete_sample,
    #else
    NULL,
    #endif
    geometry_msgs_msg_PoseWithCovariancePlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_PoseWithCovariance Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
geometry_msgs_msg_PoseWithCovarianceTypePlugin_get(void) 
{ 
    return &geometry_msgs_msg_PoseWithCovarianceTypePlugin;
} 

const char*
geometry_msgs_msg_PoseWithCovarianceTypePlugin_get_default_type_name(void) 
{ 
    return geometry_msgs_msg_PoseWithCovarianceTYPENAME;
} 

NDDS_TypePluginKeyKind 
geometry_msgs_msg_PoseWithCovariance_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36 *sample = (geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36 *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_serialize_primitive_array(
        stream,
        (void*)*sample,
        (36),
        CDR_DOUBLE_TYPE)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36 *sample = (geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36 *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if (!CDR_Stream_deserialize_primitive_array(
        stream,
        (void*)*sample,
        (36),
        CDR_DOUBLE_TYPE)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += CDR_get_max_size_serialized_primitive_array(
        current_alignment, (36), CDR_DOUBLE_TYPE);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
geometry_msgs_msg_TwistWithCovariance_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    geometry_msgs_msg_TwistWithCovariance *sample = (geometry_msgs_msg_TwistWithCovariance *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Twist_cdr_serialize(
        stream,
        &sample->twist,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_serialize(
        stream,
        &sample->covariance,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
geometry_msgs_msg_TwistWithCovariance_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    geometry_msgs_msg_TwistWithCovariance *sample = (geometry_msgs_msg_TwistWithCovariance *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!geometry_msgs_msg_Twist_cdr_deserialize(
        stream,
        &sample->twist,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_cdr_deserialize(
        stream,
        &sample->covariance,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
geometry_msgs_msg_TwistWithCovariance_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += geometry_msgs_msg_Twist_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += geometry_msgs_msg_geometry_msgs__TwistWithCovariance__double_array_36_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_TwistWithCovariance_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return geometry_msgs_msg_TwistWithCovariance_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
geometry_msgs_msg_TwistWithCovariance_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return geometry_msgs_msg_TwistWithCovariance_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
geometry_msgs_msg_TwistWithCovariance_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return geometry_msgs_msg_TwistWithCovariance_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
geometry_msgs_msg_TwistWithCovariancePlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) geometry_msgs_msg_TwistWithCovariance_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
geometry_msgs_msg_TwistWithCovariancePlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* geometry_msgs_msg_TwistWithCovariance_delete() is a void function
    which expects (sample != NULL). Since geometry_msgs_msg_TwistWithCovariancePlugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    geometry_msgs_msg_TwistWithCovariance_delete((geometry_msgs_msg_TwistWithCovariance *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
geometry_msgs_msg_TwistWithCovariancePlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return geometry_msgs_msg_TwistWithCovariance_copy(
        (geometry_msgs_msg_TwistWithCovariance *)dst,
        (const geometry_msgs_msg_TwistWithCovariance *)src);
}
/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_TwistWithCovariance Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation geometry_msgs_msg_TwistWithCovarianceEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin geometry_msgs_msg_TwistWithCovarianceTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    geometry_msgs_msg_TwistWithCovarianceEncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    geometry_msgs_msg_TwistWithCovariance_cdr_serialize,
    geometry_msgs_msg_TwistWithCovariance_cdr_deserialize,
    geometry_msgs_msg_TwistWithCovariance_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    geometry_msgs_msg_TwistWithCovariancePlugin_create_sample,
    #ifndef RTI_CERT
    geometry_msgs_msg_TwistWithCovariancePlugin_delete_sample,
    #else
    NULL,
    #endif
    geometry_msgs_msg_TwistWithCovariancePlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type geometry_msgs_msg_TwistWithCovariance Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
geometry_msgs_msg_TwistWithCovarianceTypePlugin_get(void) 
{ 
    return &geometry_msgs_msg_TwistWithCovarianceTypePlugin;
} 

const char*
geometry_msgs_msg_TwistWithCovarianceTypePlugin_get_default_type_name(void) 
{ 
    return geometry_msgs_msg_TwistWithCovarianceTYPENAME;
} 

NDDS_TypePluginKeyKind 
geometry_msgs_msg_TwistWithCovariance_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
RTI_BOOL 
nav_msgs_msg_Odometry_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    nav_msgs_msg_Odometry *sample = (nav_msgs_msg_Odometry *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!std_msgs_msg_Header_cdr_serialize(
        stream,
        &sample->header,
        param)) {
        return RTI_FALSE;
    }
    if (!CDR_Stream_serialize_string(
        stream, sample->child_frame_id, (255))) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_PoseWithCovariance_cdr_serialize(
        stream,
        &sample->pose,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_TwistWithCovariance_cdr_serialize(
        stream,
        &sample->twist,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_BOOL 
nav_msgs_msg_Odometry_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    nav_msgs_msg_Odometry *sample = (nav_msgs_msg_Odometry *)void_sample;

    if ((stream == NULL) || (void_sample == NULL))
    {
        return RTI_FALSE;
    }

    UNUSED_ARG(param);

    if(!std_msgs_msg_Header_cdr_deserialize(
        stream,
        &sample->header,
        param)) {
        return RTI_FALSE;
    }
    if (!CDR_Stream_deserialize_string(
        stream, sample->child_frame_id, (255))) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_PoseWithCovariance_cdr_deserialize(
        stream,
        &sample->pose,
        param)) {
        return RTI_FALSE;
    }
    if(!geometry_msgs_msg_TwistWithCovariance_cdr_deserialize(
        stream,
        &sample->twist,
        param)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

RTI_UINT32
nav_msgs_msg_Odometry_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    RTI_UINT32 initial_alignment = current_alignment;

    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    current_alignment += std_msgs_msg_Header_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += CDR_get_max_size_serialized_string(
        current_alignment, (255)+1);

    current_alignment += geometry_msgs_msg_PoseWithCovariance_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    current_alignment += geometry_msgs_msg_TwistWithCovariance_get_serialized_sample_max_size(
        plugin, current_alignment, param);

    return  current_alignment - initial_alignment;
}
/* --------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
nav_msgs_msg_Odometry_cdr_serialize_key(
    struct CDR_Stream_t *stream, const void *void_sample, void *param)
{
    return nav_msgs_msg_Odometry_cdr_serialize(stream, void_sample, param);
}

RTI_BOOL
nav_msgs_msg_Odometry_cdr_deserialize_key(
    struct CDR_Stream_t *stream, void *void_sample, void *param)
{
    return nav_msgs_msg_Odometry_cdr_deserialize(stream, void_sample, param);
}

RTI_UINT32
nav_msgs_msg_Odometry_get_serialized_key_max_size(
    struct NDDS_Type_Plugin *plugin,
    RTI_UINT32 current_alignment,
    void *param)
{
    return nav_msgs_msg_Odometry_get_serialized_sample_max_size(plugin, current_alignment, param);
}

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
nav_msgs_msg_OdometryPlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    *sample = (void *) nav_msgs_msg_Odometry_create();
    return (sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
nav_msgs_msg_OdometryPlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    /* nav_msgs_msg_Odometry_delete() is a void function
    which expects (sample != NULL). Since nav_msgs_msg_OdometryPlugin_delete_sample
    is an internal function, sample is assumed to be a valid pointer */ 
    nav_msgs_msg_Odometry_delete((nav_msgs_msg_Odometry *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
nav_msgs_msg_OdometryPlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param)
{
    UNUSED_ARG(plugin);
    UNUSED_ARG(param);
    return nav_msgs_msg_Odometry_copy(
        (nav_msgs_msg_Odometry *)dst,
        (const nav_msgs_msg_Odometry *)src);
}
/* --------------------------------------------------------------------------
*  Type nav_msgs_msg_Odometry Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation nav_msgs_msg_OdometryEncapsulationKind[] =
{ {0,0} };

struct NDDS_Type_Plugin nav_msgs_msg_OdometryTypePlugin =
{
    {0, 0},                     /* NDDS_Type_PluginVersion */
    NULL,                       /* DDS_TypeCode_t* */
    nav_msgs_msg_OdometryEncapsulationKind,
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */
    nav_msgs_msg_Odometry_cdr_serialize,
    nav_msgs_msg_Odometry_cdr_deserialize,
    nav_msgs_msg_Odometry_get_serialized_sample_max_size,
    NULL, NULL, NULL,           /* key support functions*/
    nav_msgs_msg_OdometryPlugin_create_sample,
    #ifndef RTI_CERT
    nav_msgs_msg_OdometryPlugin_delete_sample,
    #else
    NULL,
    #endif
    nav_msgs_msg_OdometryPlugin_copy_sample,
    PluginHelper_get_key_kind,
    PluginHelper_instance_to_keyhash,
    NULL, NULL, NULL, NULL  /* endpoint wrappers not used in C */
};

/* --------------------------------------------------------------------------
*  Type nav_msgs_msg_Odometry Plugin Methods
* -------------------------------------------------------------------------- */

struct NDDS_Type_Plugin *
nav_msgs_msg_OdometryTypePlugin_get(void) 
{ 
    return &nav_msgs_msg_OdometryTypePlugin;
} 

const char*
nav_msgs_msg_OdometryTypePlugin_get_default_type_name(void) 
{ 
    return nav_msgs_msg_OdometryTYPENAME;
} 

NDDS_TypePluginKeyKind 
nav_msgs_msg_Odometry_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param)
{
    UNUSED_ARG(param);
    UNUSED_ARG(plugin);
    return NDDS_TYPEPLUGIN_NO_KEY;
}

