/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Odometry.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "OdometrySupport.h"

/*** SOURCE_BEGIN ***/

/* =========================================================================== */

/* Requires */
#define TTYPENAME   geometry_msgs_msg_PointTYPENAME

/* 
geometry_msgs_msg_PointDataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter geometry_msgs_msg_PointDataWriter
#define TData       geometry_msgs_msg_Point

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
geometry_msgs_msg_PointDataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader geometry_msgs_msg_PointDataReader
#define TDataSeq    geometry_msgs_msg_PointSeq
#define TData       geometry_msgs_msg_Point
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
geometry_msgs_msg_PointTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_PointTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        geometry_msgs_msg_PointTypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
geometry_msgs_msg_PointTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_PointTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (geometry_msgs_msg_PointTypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
geometry_msgs_msg_PointTypeSupport_get_type_name(void)
{
    return geometry_msgs_msg_PointTYPENAME;
}
geometry_msgs_msg_Point *
geometry_msgs_msg_PointTypeSupport_create_data(void)
{
    geometry_msgs_msg_Point *data = NULL;

    data = geometry_msgs_msg_Point_create();

    return data;
}

#ifndef RTI_CERT
void
geometry_msgs_msg_PointTypeSupport_delete_data(
    geometry_msgs_msg_Point *data)
{
    geometry_msgs_msg_Point_delete(data);
}
#endif

#undef TTYPENAME

/* =========================================================================== */

/* Requires */
#define TTYPENAME   geometry_msgs_msg_QuaternionTYPENAME

/* 
geometry_msgs_msg_QuaternionDataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter geometry_msgs_msg_QuaternionDataWriter
#define TData       geometry_msgs_msg_Quaternion

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
geometry_msgs_msg_QuaternionDataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader geometry_msgs_msg_QuaternionDataReader
#define TDataSeq    geometry_msgs_msg_QuaternionSeq
#define TData       geometry_msgs_msg_Quaternion
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
geometry_msgs_msg_QuaternionTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_QuaternionTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        geometry_msgs_msg_QuaternionTypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
geometry_msgs_msg_QuaternionTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_QuaternionTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (geometry_msgs_msg_QuaternionTypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
geometry_msgs_msg_QuaternionTypeSupport_get_type_name(void)
{
    return geometry_msgs_msg_QuaternionTYPENAME;
}
geometry_msgs_msg_Quaternion *
geometry_msgs_msg_QuaternionTypeSupport_create_data(void)
{
    geometry_msgs_msg_Quaternion *data = NULL;

    data = geometry_msgs_msg_Quaternion_create();

    return data;
}

#ifndef RTI_CERT
void
geometry_msgs_msg_QuaternionTypeSupport_delete_data(
    geometry_msgs_msg_Quaternion *data)
{
    geometry_msgs_msg_Quaternion_delete(data);
}
#endif

#undef TTYPENAME

/* =========================================================================== */

/* Requires */
#define TTYPENAME   geometry_msgs_msg_Vector3TYPENAME

/* 
geometry_msgs_msg_Vector3DataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter geometry_msgs_msg_Vector3DataWriter
#define TData       geometry_msgs_msg_Vector3

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
geometry_msgs_msg_Vector3DataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader geometry_msgs_msg_Vector3DataReader
#define TDataSeq    geometry_msgs_msg_Vector3Seq
#define TData       geometry_msgs_msg_Vector3
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
geometry_msgs_msg_Vector3TypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_Vector3TypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        geometry_msgs_msg_Vector3TypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
geometry_msgs_msg_Vector3TypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_Vector3TypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (geometry_msgs_msg_Vector3TypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
geometry_msgs_msg_Vector3TypeSupport_get_type_name(void)
{
    return geometry_msgs_msg_Vector3TYPENAME;
}
geometry_msgs_msg_Vector3 *
geometry_msgs_msg_Vector3TypeSupport_create_data(void)
{
    geometry_msgs_msg_Vector3 *data = NULL;

    data = geometry_msgs_msg_Vector3_create();

    return data;
}

#ifndef RTI_CERT
void
geometry_msgs_msg_Vector3TypeSupport_delete_data(
    geometry_msgs_msg_Vector3 *data)
{
    geometry_msgs_msg_Vector3_delete(data);
}
#endif

#undef TTYPENAME

/* =========================================================================== */

/* Requires */
#define TTYPENAME   geometry_msgs_msg_PoseTYPENAME

/* 
geometry_msgs_msg_PoseDataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter geometry_msgs_msg_PoseDataWriter
#define TData       geometry_msgs_msg_Pose

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
geometry_msgs_msg_PoseDataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader geometry_msgs_msg_PoseDataReader
#define TDataSeq    geometry_msgs_msg_PoseSeq
#define TData       geometry_msgs_msg_Pose
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
geometry_msgs_msg_PoseTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_PoseTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        geometry_msgs_msg_PoseTypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
geometry_msgs_msg_PoseTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_PoseTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (geometry_msgs_msg_PoseTypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
geometry_msgs_msg_PoseTypeSupport_get_type_name(void)
{
    return geometry_msgs_msg_PoseTYPENAME;
}
geometry_msgs_msg_Pose *
geometry_msgs_msg_PoseTypeSupport_create_data(void)
{
    geometry_msgs_msg_Pose *data = NULL;

    data = geometry_msgs_msg_Pose_create();

    return data;
}

#ifndef RTI_CERT
void
geometry_msgs_msg_PoseTypeSupport_delete_data(
    geometry_msgs_msg_Pose *data)
{
    geometry_msgs_msg_Pose_delete(data);
}
#endif

#undef TTYPENAME

/* =========================================================================== */

/* Requires */
#define TTYPENAME   geometry_msgs_msg_TwistTYPENAME

/* 
geometry_msgs_msg_TwistDataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter geometry_msgs_msg_TwistDataWriter
#define TData       geometry_msgs_msg_Twist

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
geometry_msgs_msg_TwistDataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader geometry_msgs_msg_TwistDataReader
#define TDataSeq    geometry_msgs_msg_TwistSeq
#define TData       geometry_msgs_msg_Twist
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
geometry_msgs_msg_TwistTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_TwistTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        geometry_msgs_msg_TwistTypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
geometry_msgs_msg_TwistTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_TwistTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (geometry_msgs_msg_TwistTypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
geometry_msgs_msg_TwistTypeSupport_get_type_name(void)
{
    return geometry_msgs_msg_TwistTYPENAME;
}
geometry_msgs_msg_Twist *
geometry_msgs_msg_TwistTypeSupport_create_data(void)
{
    geometry_msgs_msg_Twist *data = NULL;

    data = geometry_msgs_msg_Twist_create();

    return data;
}

#ifndef RTI_CERT
void
geometry_msgs_msg_TwistTypeSupport_delete_data(
    geometry_msgs_msg_Twist *data)
{
    geometry_msgs_msg_Twist_delete(data);
}
#endif

#undef TTYPENAME

/* =========================================================================== */

/* Requires */
#define TTYPENAME   geometry_msgs_msg_PoseWithCovarianceTYPENAME

/* 
geometry_msgs_msg_PoseWithCovarianceDataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter geometry_msgs_msg_PoseWithCovarianceDataWriter
#define TData       geometry_msgs_msg_PoseWithCovariance

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
geometry_msgs_msg_PoseWithCovarianceDataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader geometry_msgs_msg_PoseWithCovarianceDataReader
#define TDataSeq    geometry_msgs_msg_PoseWithCovarianceSeq
#define TData       geometry_msgs_msg_PoseWithCovariance
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
geometry_msgs_msg_PoseWithCovarianceTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_PoseWithCovarianceTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        geometry_msgs_msg_PoseWithCovarianceTypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
geometry_msgs_msg_PoseWithCovarianceTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_PoseWithCovarianceTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (geometry_msgs_msg_PoseWithCovarianceTypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
geometry_msgs_msg_PoseWithCovarianceTypeSupport_get_type_name(void)
{
    return geometry_msgs_msg_PoseWithCovarianceTYPENAME;
}
geometry_msgs_msg_PoseWithCovariance *
geometry_msgs_msg_PoseWithCovarianceTypeSupport_create_data(void)
{
    geometry_msgs_msg_PoseWithCovariance *data = NULL;

    data = geometry_msgs_msg_PoseWithCovariance_create();

    return data;
}

#ifndef RTI_CERT
void
geometry_msgs_msg_PoseWithCovarianceTypeSupport_delete_data(
    geometry_msgs_msg_PoseWithCovariance *data)
{
    geometry_msgs_msg_PoseWithCovariance_delete(data);
}
#endif

#undef TTYPENAME

/* =========================================================================== */

/* Requires */
#define TTYPENAME   geometry_msgs_msg_TwistWithCovarianceTYPENAME

/* 
geometry_msgs_msg_TwistWithCovarianceDataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter geometry_msgs_msg_TwistWithCovarianceDataWriter
#define TData       geometry_msgs_msg_TwistWithCovariance

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
geometry_msgs_msg_TwistWithCovarianceDataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader geometry_msgs_msg_TwistWithCovarianceDataReader
#define TDataSeq    geometry_msgs_msg_TwistWithCovarianceSeq
#define TData       geometry_msgs_msg_TwistWithCovariance
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
geometry_msgs_msg_TwistWithCovarianceTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_TwistWithCovarianceTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        geometry_msgs_msg_TwistWithCovarianceTypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
geometry_msgs_msg_TwistWithCovarianceTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = geometry_msgs_msg_TwistWithCovarianceTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (geometry_msgs_msg_TwistWithCovarianceTypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
geometry_msgs_msg_TwistWithCovarianceTypeSupport_get_type_name(void)
{
    return geometry_msgs_msg_TwistWithCovarianceTYPENAME;
}
geometry_msgs_msg_TwistWithCovariance *
geometry_msgs_msg_TwistWithCovarianceTypeSupport_create_data(void)
{
    geometry_msgs_msg_TwistWithCovariance *data = NULL;

    data = geometry_msgs_msg_TwistWithCovariance_create();

    return data;
}

#ifndef RTI_CERT
void
geometry_msgs_msg_TwistWithCovarianceTypeSupport_delete_data(
    geometry_msgs_msg_TwistWithCovariance *data)
{
    geometry_msgs_msg_TwistWithCovariance_delete(data);
}
#endif

#undef TTYPENAME

/* =========================================================================== */

/* Requires */
#define TTYPENAME   nav_msgs_msg_OdometryTYPENAME

/* 
nav_msgs_msg_OdometryDataWriter (DDS_DataWriter)   
*/

/* Defines */
#define TDataWriter nav_msgs_msg_OdometryDataWriter
#define TData       nav_msgs_msg_Odometry

#include "dds_c/dds_c_tdatawriter_gen.h"

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
nav_msgs_msg_OdometryDataReader (DDS_DataReader)   
*/

/* Defines */
#define TDataReader nav_msgs_msg_OdometryDataReader
#define TDataSeq    nav_msgs_msg_OdometrySeq
#define TData       nav_msgs_msg_Odometry
#include "dds_c/dds_c_tdatareader_gen.h"
#undef TDataReader
#undef TDataSeq
#undef TData

DDS_ReturnCode_t
nav_msgs_msg_OdometryTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = nav_msgs_msg_OdometryTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    retcode = DDS_DomainParticipant_register_type(
        participant,
        type_name,
        nav_msgs_msg_OdometryTypePlugin_get());

    if (retcode != DDS_RETCODE_OK)
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}

#ifndef RTI_CERT
DDS_ReturnCode_t
nav_msgs_msg_OdometryTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name)
{
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

    if (participant == NULL) 
    {
        goto done;
    }

    if (type_name == NULL) 
    {
        type_name = nav_msgs_msg_OdometryTypePlugin_get_default_type_name();
        if (type_name == NULL)
        {
            goto done;
        }
    }

    if (nav_msgs_msg_OdometryTypePlugin_get() !=
    DDS_DomainParticipant_unregister_type(participant,type_name))
    {
        goto done;
    }

    retcode = DDS_RETCODE_OK;

    done:

    return retcode;
}
#endif
const char*
nav_msgs_msg_OdometryTypeSupport_get_type_name(void)
{
    return nav_msgs_msg_OdometryTYPENAME;
}
nav_msgs_msg_Odometry *
nav_msgs_msg_OdometryTypeSupport_create_data(void)
{
    nav_msgs_msg_Odometry *data = NULL;

    data = nav_msgs_msg_Odometry_create();

    return data;
}

#ifndef RTI_CERT
void
nav_msgs_msg_OdometryTypeSupport_delete_data(
    nav_msgs_msg_Odometry *data)
{
    nav_msgs_msg_Odometry_delete(data);
}
#endif

#undef TTYPENAME

