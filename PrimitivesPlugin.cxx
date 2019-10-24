

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primitives.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <string.h>

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "rti/topic/cdr/Serialization.hpp"

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "PrimitivesPlugin.hpp"

/* ----------------------------------------------------------------------------
*  Type PrimitiveStruct
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

PrimitiveStruct *
PrimitiveStructPluginSupport_create_data(void)
{
    try {
        PrimitiveStruct *sample = new PrimitiveStruct;    
        rti::topic::allocate_sample(*sample);
        return sample;
    } catch (...) {
        return NULL;
    }
}

void 
PrimitiveStructPluginSupport_destroy_data(
    PrimitiveStruct *sample) 
{
    delete sample;
}

RTIBool 
PrimitiveStructPluginSupport_copy_data(
    PrimitiveStruct *dst,
    const PrimitiveStruct *src)
{
    try {
        *dst = *src;
    } catch (...) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
PrimitiveStructPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void 
PrimitiveStructPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

    PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
PrimitiveStructPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    try {
        PRESTypePluginEndpointData epd = NULL;

        unsigned int serializedSampleMaxSize;

        if (top_level_registration) {} /* To avoid warnings */
        if (containerPluginContext) {} /* To avoid warnings */

        epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            PrimitiveStructPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            PrimitiveStructPluginSupport_destroy_data,
            NULL , NULL );

        if (epd == NULL) {
            return NULL;
        } 

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            serializedSampleMaxSize = PrimitiveStructPlugin_get_serialized_sample_max_size(
                epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

            PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

            if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                PrimitiveStructPlugin_get_serialized_sample_max_size, epd,
                (PRESTypePluginGetSerializedSampleSizeFunction)
                PrimitiveStructPlugin_get_serialized_sample_size,
                epd) == RTI_FALSE) {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }
        }

        return epd;
    } catch (...) {
        return NULL;
    }
}

void 
PrimitiveStructPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
PrimitiveStructPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *sample,
    void *handle)
{
    try {
        rti::topic::reset_sample(*sample);
    } catch(const std::exception& ex) {
        RTICdrLog_exception(
            "PrimitiveStructPlugin_return_sample",
            &RTI_LOG_ANY_FAILURE_s,
            "exception: ",
            ex.what());           
    }

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
PrimitiveStructPlugin_copy_sample(
    PRESTypePluginEndpointData,
    PrimitiveStruct *dst,
    const PrimitiveStruct *src)
{
    return PrimitiveStructPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
PrimitiveStructPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool 
PrimitiveStructPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const PrimitiveStruct *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;
        RTIBool retval = RTI_TRUE;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_sample) {

            if (!rti::topic::cdr::serialize(
                stream, &sample->theChar())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->thWchar())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theBool())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theFloat())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theShort())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theLong())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theDouble())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theOctet())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theUnsignedShort())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theUnsignedLong())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theLongLong())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theUnsignedLongLong())) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, &sample->theLongDouble())) {
                return RTI_FALSE;
            }

            if (sample->ThePointer().get() == NULL) {
                return RTI_FALSE;
            }

            if (!rti::topic::cdr::serialize(
                stream, sample->ThePointer().get())) {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return retval;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool 
PrimitiveStructPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if(deserialize_sample) {

        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theChar())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->thWchar())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theBool())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theFloat())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theShort())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theLong())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theDouble())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theOctet())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theUnsignedShort())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theUnsignedLong())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theLongLong())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theUnsignedLongLong())) {
            goto fin; 
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            &sample->theLongDouble())) {
            goto fin; 
        }
        if (!sample->ThePointer().get()) {
            dds::core::detail::make_locked(sample->ThePointer());
        }
        if (!rti::topic::cdr::deserialize(
            stream, 
            sample->ThePointer().get())) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool
PrimitiveStructPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const PrimitiveStruct *sample)
{
    try{
        struct RTICdrStream stream;
        struct PRESTypePluginDefaultEndpointData epd;
        RTIBool result;

        if (length == NULL) {
            return RTI_FALSE;
        }

        epd._maxSizeSerializedSample =
        PrimitiveStructPlugin_get_serialized_sample_max_size(
            NULL, RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 0);

        if (buffer == NULL) {
            *length = 
            PrimitiveStructPlugin_get_serialized_sample_size(
                (PRESTypePluginEndpointData)&epd,
                RTI_TRUE,
                RTICdrEncapsulation_getNativeCdrEncapsulationId(),
                0,
                sample);

            if (*length == 0) {
                return RTI_FALSE;
            }

            return RTI_TRUE;
        }    

        RTICdrStream_init(&stream);
        RTICdrStream_set(&stream, (char *)buffer, *length);

        result = PrimitiveStructPlugin_serialize(
            (PRESTypePluginEndpointData)&epd, sample, &stream, 
            RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 
            RTI_TRUE, NULL);  

        *length = RTICdrStream_getCurrentPositionOffset(&stream);
        return result;     
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool
PrimitiveStructPlugin_deserialize_from_cdr_buffer(
    PrimitiveStruct *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    rti::topic::reset_sample(*sample);
    return PrimitiveStructPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

RTIBool 
PrimitiveStructPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        const char *METHOD_NAME = "PrimitiveStructPlugin_deserialize";
        if (drop_sample) {} /* To avoid warnings */

        stream->_xTypesState.unassignable = RTI_FALSE;
        result= PrimitiveStructPlugin_deserialize_sample( 
            endpoint_data, (sample != NULL)?*sample:NULL,
            stream, deserialize_encapsulation, deserialize_sample, 
            endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }
        if (!result && stream->_xTypesState.unassignable ) {

            RTICdrLog_exception(
                METHOD_NAME, 
                &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
                "PrimitiveStruct");

        }

        return result;

    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool PrimitiveStructPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
    try    
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if (skip_sample) {

        if (!RTICdrStream_skipChar (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipWchar (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipBoolean (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipFloat (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipDouble (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipOctet (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipUnsignedShort (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipUnsignedLong (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLongLong (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipUnsignedLongLong (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLongDouble (stream)) {
            goto fin; 
        }
        if (!RTICdrStream_skipLong (stream)) {
            goto fin; 
        }
    }

    done = RTI_TRUE;
  fin:
    if (done != RTI_TRUE && 
    RTICdrStream_getRemainder(stream) >=
    RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
        return RTI_FALSE;   
    }
    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}
catch (...) {
    return RTI_FALSE;
}

unsigned int 
PrimitiveStructPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment +=RTICdrType_getCharMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getWcharMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getFloatMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getOctetMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getUnsignedShortMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getLongLongMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getLongLongMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getLongDoubleMaxSizeSerialized(
        current_alignment);

    current_alignment +=RTICdrType_getLongMaxSizeSerialized(
        current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
}

unsigned int 
PrimitiveStructPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PrimitiveStructPlugin_get_serialized_sample_max_size_ex(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return 0;
    }    
}

unsigned int 
PrimitiveStructPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {

        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;

        if (endpoint_data) {} /* To avoid warnings */ 

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
        }

        current_alignment +=RTICdrType_getCharMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getWcharMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getBooleanMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getFloatMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getShortMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getLongMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getDoubleMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getOctetMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getUnsignedShortMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getUnsignedLongMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getLongLongMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getLongLongMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getLongDoubleMaxSizeSerialized(
            current_alignment);
        current_alignment +=RTICdrType_getLongMaxSizeSerialized(
            current_alignment);

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return  current_alignment - initial_alignment;
    } catch (...) {
        return 0;
    }
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
PrimitiveStructPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const PrimitiveStruct * sample) 
{
    try {  
        unsigned int initial_alignment = current_alignment;

        unsigned int encapsulation_size = current_alignment;
        struct PRESTypePluginDefaultEndpointData epd;   

        if (sample==NULL) {
            return 0;
        }
        if (endpoint_data == NULL) {
            endpoint_data = (PRESTypePluginEndpointData) &epd;
            PRESTypePluginDefaultEndpointData_setBaseAlignment(
                endpoint_data,
                current_alignment);        
        }

        if (include_encapsulation) {

            if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
                return 1;
            }
            RTICdrStream_getEncapsulationSize(encapsulation_size);
            encapsulation_size -= current_alignment;
            current_alignment = 0;
            initial_alignment = 0;
            PRESTypePluginDefaultEndpointData_setBaseAlignment(
                endpoint_data,
                current_alignment);
        }

        current_alignment += RTICdrType_getCharMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getWcharMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getBooleanMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getFloatMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getShortMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getLongMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getOctetMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getUnsignedShortMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getLongLongMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getLongLongMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getLongDoubleMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        current_alignment += RTICdrType_getLongMaxSizeSerialized(
            PRESTypePluginDefaultEndpointData_getAlignment(
                endpoint_data, current_alignment));

        if (include_encapsulation) {
            current_alignment += encapsulation_size;
        }
        return current_alignment - initial_alignment;
    } catch (...) {
        return RTI_FALSE;
    }    
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
PrimitiveStructPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
PrimitiveStructPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const PrimitiveStruct *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;

        if(serialize_encapsulation) {
            if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }

        if(serialize_key) {

            if (!PrimitiveStructPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }

        }

        if(serialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool PrimitiveStructPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        char * position = NULL;

        if (endpoint_data) {} /* To avoid warnings */
        if (endpoint_plugin_qos) {} /* To avoid warnings */

        if(deserialize_encapsulation) {

            if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
                return RTI_FALSE;
            }

            position = RTICdrStream_resetAlignment(stream);
        }
        if (deserialize_key) {

            if (!PrimitiveStructPlugin_deserialize_sample(
                endpoint_data, sample, stream, 
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }

        if(deserialize_encapsulation) {
            RTICdrStream_restoreAlignment(stream,position);
        }

        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool PrimitiveStructPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        if (drop_sample) {} /* To avoid warnings */
        stream->_xTypesState.unassignable = RTI_FALSE;
        result= PrimitiveStructPlugin_deserialize_key_sample(
            endpoint_data, (sample != NULL)?*sample:NULL, stream,
            deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
        if (result) {
            if (stream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }

        return result;    
    } catch (...) {
        return RTI_FALSE;
    }     
}

unsigned int
PrimitiveStructPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (overflow) {} /* To avoid warnings */

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

    current_alignment += PrimitiveStructPlugin_get_serialized_sample_max_size_ex(
        endpoint_data, overflow,RTI_FALSE, encapsulation_id, current_alignment);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

unsigned int
PrimitiveStructPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PrimitiveStructPlugin_get_serialized_key_max_size_ex(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return RTI_FALSE;
    }    
}

RTIBool 
PrimitiveStructPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
    try    
{
    char * position = NULL;

    RTIBool done = RTI_FALSE;
    RTIBool error = RTI_FALSE;

    if (stream == NULL) {
        error = RTI_TRUE;
        goto fin;
    }
    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }
        position = RTICdrStream_resetAlignment(stream);
    }

    if (deserialize_key) {

        if (!PrimitiveStructPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }

    done = RTI_TRUE;
  fin:
    if(!error) {
        if (done != RTI_TRUE && 
        RTICdrStream_getRemainder(stream) >=
        RTI_CDR_PARAMETER_HEADER_ALIGNMENT) {
            return RTI_FALSE;   
        }
    } else {
        return RTI_FALSE;
    }       

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
} catch (...) {
    return RTI_FALSE;
} 

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *PrimitiveStructPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    PrimitiveStructPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    PrimitiveStructPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    PrimitiveStructPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    PrimitiveStructPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    PrimitiveStructPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    PrimitiveStructPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    PrimitiveStructPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    PrimitiveStructPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    PrimitiveStructPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    PrimitiveStructPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    PrimitiveStructPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    PrimitiveStructPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    PrimitiveStructPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    PrimitiveStructPlugin_get_key_kind;

    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL ;    
    plugin->deserializeKeyFnc = NULL;  
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;    
    plugin->typeCode = (struct RTICdrTypeCode *) 
    &rti::topic::dynamic_type<PrimitiveStruct>::get().native();

    plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    PrimitiveStructPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    PrimitiveStructPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    PrimitiveStructPlugin_get_serialized_sample_size;

    static const char * TYPE_NAME = "PrimitiveStruct";
    plugin->endpointTypeName = TYPE_NAME;

    return plugin;
}

void
PrimitiveStructPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 
