

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primitives.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef PrimitivesPlugin_1782957785_h
#define PrimitivesPlugin_1782957785_h

#include "Primitives.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define PrimitiveStructPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define PrimitiveStructPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define PrimitiveStructPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define PrimitiveStructPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define PrimitiveStructPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PrimitiveStruct*
PrimitiveStructPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern PrimitiveStruct*
PrimitiveStructPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern PrimitiveStruct*
PrimitiveStructPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPluginSupport_copy_data(
    PrimitiveStruct *out,
    const PrimitiveStruct *in);

NDDSUSERDllExport extern void 
PrimitiveStructPluginSupport_destroy_data_w_params(
    PrimitiveStruct *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
PrimitiveStructPluginSupport_destroy_data_ex(
    PrimitiveStruct *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
PrimitiveStructPluginSupport_destroy_data(
    PrimitiveStruct *sample);

NDDSUSERDllExport extern void 
PrimitiveStructPluginSupport_print_data(
    const PrimitiveStruct *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
PrimitiveStructPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
PrimitiveStructPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
PrimitiveStructPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
PrimitiveStructPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
PrimitiveStructPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *out,
    const PrimitiveStruct *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const PrimitiveStruct *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
PrimitiveStructPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const PrimitiveStruct *sample); 

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
PrimitiveStructPlugin_deserialize_from_cdr_buffer(
    PrimitiveStruct *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
PrimitiveStructPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
PrimitiveStructPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
PrimitiveStructPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
PrimitiveStructPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
PrimitiveStructPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const PrimitiveStruct * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
PrimitiveStructPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
PrimitiveStructPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
PrimitiveStructPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const PrimitiveStruct *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
PrimitiveStructPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
PrimitiveStructPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    PrimitiveStruct *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
PrimitiveStructPlugin_new(void);

NDDSUSERDllExport extern void
PrimitiveStructPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* PrimitivesPlugin_1782957785_h */

