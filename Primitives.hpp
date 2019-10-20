

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primitives.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef Primitives_1782957785_hpp
#define Primitives_1782957785_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport PrimitiveStruct {

  public:
    PrimitiveStruct();

    PrimitiveStruct(
        char theChar,
        bool theBool,
        float theFloat,
        int16_t theShort,
        int32_t theLong,
        double theDouble);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    PrimitiveStruct (PrimitiveStruct&&) = default;
    PrimitiveStruct& operator=(PrimitiveStruct&&) = default;
    PrimitiveStruct& operator=(const PrimitiveStruct&) = default;
    PrimitiveStruct(const PrimitiveStruct&) = default;
    #else
    PrimitiveStruct(PrimitiveStruct&& other_) OMG_NOEXCEPT;  
    PrimitiveStruct& operator=(PrimitiveStruct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    char& theChar() OMG_NOEXCEPT; 
    const char& theChar() const OMG_NOEXCEPT;
    void theChar(char value);

    bool& theBool() OMG_NOEXCEPT; 
    const bool& theBool() const OMG_NOEXCEPT;
    void theBool(bool value);

    float& theFloat() OMG_NOEXCEPT; 
    const float& theFloat() const OMG_NOEXCEPT;
    void theFloat(float value);

    int16_t& theShort() OMG_NOEXCEPT; 
    const int16_t& theShort() const OMG_NOEXCEPT;
    void theShort(int16_t value);

    int32_t& theLong() OMG_NOEXCEPT; 
    const int32_t& theLong() const OMG_NOEXCEPT;
    void theLong(int32_t value);

    double& theDouble() OMG_NOEXCEPT; 
    const double& theDouble() const OMG_NOEXCEPT;
    void theDouble(double value);

    bool operator == (const PrimitiveStruct& other_) const;
    bool operator != (const PrimitiveStruct& other_) const;

    void swap(PrimitiveStruct& other_) OMG_NOEXCEPT ;

  private:

    char m_theChar_;
    bool m_theBool_;
    float m_theFloat_;
    int16_t m_theShort_;
    int32_t m_theLong_;
    double m_theDouble_;

};

inline void swap(PrimitiveStruct& a, PrimitiveStruct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PrimitiveStruct& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<PrimitiveStruct> {
            NDDSUSERDllExport static std::string value() {
                return "PrimitiveStruct";
            }
        };

        template<>
        struct is_topic_type<PrimitiveStruct> : public dds::core::true_type {};

        template<>
        struct topic_type_support<PrimitiveStruct> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const PrimitiveStruct& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(PrimitiveStruct& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(PrimitiveStruct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PrimitiveStruct& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<PrimitiveStruct> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<PrimitiveStruct> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // Primitives_1782957785_hpp

