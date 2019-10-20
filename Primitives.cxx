

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primitives.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "Primitives.hpp"
#include "PrimitivesPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- PrimitiveStruct: 

PrimitiveStruct::PrimitiveStruct() :
    m_theChar_ (0) ,
    m_theBool_ (false) ,
    m_theFloat_ (0.0f) ,
    m_theShort_ (0) ,
    m_theLong_ (0) ,
    m_theDouble_ (0.0)  {
}   

PrimitiveStruct::PrimitiveStruct (
    char theChar,
    bool theBool,
    float theFloat,
    int16_t theShort,
    int32_t theLong,
    double theDouble)
    :
        m_theChar_( theChar ),
        m_theBool_( theBool ),
        m_theFloat_( theFloat ),
        m_theShort_( theShort ),
        m_theLong_( theLong ),
        m_theDouble_( theDouble ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
PrimitiveStruct::PrimitiveStruct(PrimitiveStruct&& other_) OMG_NOEXCEPT  :m_theChar_ (std::move(other_.m_theChar_))
,
m_theBool_ (std::move(other_.m_theBool_))
,
m_theFloat_ (std::move(other_.m_theFloat_))
,
m_theShort_ (std::move(other_.m_theShort_))
,
m_theLong_ (std::move(other_.m_theLong_))
,
m_theDouble_ (std::move(other_.m_theDouble_))
{
} 

PrimitiveStruct& PrimitiveStruct::operator=(PrimitiveStruct&&  other_) OMG_NOEXCEPT {
    PrimitiveStruct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void PrimitiveStruct::swap(PrimitiveStruct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_theChar_, other_.m_theChar_);
    swap(m_theBool_, other_.m_theBool_);
    swap(m_theFloat_, other_.m_theFloat_);
    swap(m_theShort_, other_.m_theShort_);
    swap(m_theLong_, other_.m_theLong_);
    swap(m_theDouble_, other_.m_theDouble_);
}  

bool PrimitiveStruct::operator == (const PrimitiveStruct& other_) const {
    if (m_theChar_ != other_.m_theChar_) {
        return false;
    }
    if (m_theBool_ != other_.m_theBool_) {
        return false;
    }
    if (m_theFloat_ != other_.m_theFloat_) {
        return false;
    }
    if (m_theShort_ != other_.m_theShort_) {
        return false;
    }
    if (m_theLong_ != other_.m_theLong_) {
        return false;
    }
    if (m_theDouble_ != other_.m_theDouble_) {
        return false;
    }
    return true;
}
bool PrimitiveStruct::operator != (const PrimitiveStruct& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
char& PrimitiveStruct::theChar() OMG_NOEXCEPT {
    return m_theChar_;
}

const char& PrimitiveStruct::theChar() const OMG_NOEXCEPT {
    return m_theChar_;
}

void PrimitiveStruct::theChar(char value) {
    m_theChar_ = value;
}

bool& PrimitiveStruct::theBool() OMG_NOEXCEPT {
    return m_theBool_;
}

const bool& PrimitiveStruct::theBool() const OMG_NOEXCEPT {
    return m_theBool_;
}

void PrimitiveStruct::theBool(bool value) {
    m_theBool_ = value;
}

float& PrimitiveStruct::theFloat() OMG_NOEXCEPT {
    return m_theFloat_;
}

const float& PrimitiveStruct::theFloat() const OMG_NOEXCEPT {
    return m_theFloat_;
}

void PrimitiveStruct::theFloat(float value) {
    m_theFloat_ = value;
}

int16_t& PrimitiveStruct::theShort() OMG_NOEXCEPT {
    return m_theShort_;
}

const int16_t& PrimitiveStruct::theShort() const OMG_NOEXCEPT {
    return m_theShort_;
}

void PrimitiveStruct::theShort(int16_t value) {
    m_theShort_ = value;
}

int32_t& PrimitiveStruct::theLong() OMG_NOEXCEPT {
    return m_theLong_;
}

const int32_t& PrimitiveStruct::theLong() const OMG_NOEXCEPT {
    return m_theLong_;
}

void PrimitiveStruct::theLong(int32_t value) {
    m_theLong_ = value;
}

double& PrimitiveStruct::theDouble() OMG_NOEXCEPT {
    return m_theDouble_;
}

const double& PrimitiveStruct::theDouble() const OMG_NOEXCEPT {
    return m_theDouble_;
}

void PrimitiveStruct::theDouble(double value) {
    m_theDouble_ = value;
}

std::ostream& operator << (std::ostream& o,const PrimitiveStruct& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "theChar: '" << sample.theChar()<<", ";
    o << "theBool: " << sample.theBool()<<", ";
    o << "theFloat: " << std::setprecision(9) <<sample.theFloat()<<", ";
    o << "theShort: " << sample.theShort()<<", ";
    o << "theLong: " << sample.theLong()<<", ";
    o << "theDouble: " << std::setprecision(15) <<sample.theDouble() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<PrimitiveStruct> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member PrimitiveStruct_g_tc_members[6]=
                {

                    {
                        (char *)"theChar",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"theBool",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"theFloat",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"theShort",/* Member name */
                        {
                            3,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"theLong",/* Member name */
                        {
                            4,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"theDouble",/* Member name */
                        {
                            5,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode PrimitiveStruct_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"PrimitiveStruct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        PrimitiveStruct_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for PrimitiveStruct*/

                if (is_initialized) {
                    return &PrimitiveStruct_g_tc;
                }

                PrimitiveStruct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

                PrimitiveStruct_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                PrimitiveStruct_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                PrimitiveStruct_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                PrimitiveStruct_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                PrimitiveStruct_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                is_initialized = RTI_TRUE;

                return &PrimitiveStruct_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<PrimitiveStruct>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<PrimitiveStruct>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<PrimitiveStruct>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                PrimitiveStructPlugin_new,
                PrimitiveStructPlugin_delete);
        }

        std::vector<char>& topic_type_support<PrimitiveStruct>::to_cdr_buffer(
            std::vector<char>& buffer, const PrimitiveStruct& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = PrimitiveStructPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = PrimitiveStructPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<PrimitiveStruct>::from_cdr_buffer(PrimitiveStruct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = PrimitiveStructPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create PrimitiveStruct from cdr buffer");
        }

        void topic_type_support<PrimitiveStruct>::reset_sample(PrimitiveStruct& sample) 
        {
            rti::topic::reset_sample(sample.theChar());
            rti::topic::reset_sample(sample.theBool());
            rti::topic::reset_sample(sample.theFloat());
            rti::topic::reset_sample(sample.theShort());
            rti::topic::reset_sample(sample.theLong());
            rti::topic::reset_sample(sample.theDouble());
        }

        void topic_type_support<PrimitiveStruct>::allocate_sample(PrimitiveStruct& sample, int, int) 
        {
        }

    }
}  

