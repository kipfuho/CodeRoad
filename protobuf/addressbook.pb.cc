// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: addressbook.proto
// Protobuf C++ Version: 5.27.2

#include "addressbook.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace tutorial {

inline constexpr Person_PhoneNumber::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        number_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        type_{static_cast< ::tutorial::Person_PhoneType >(2)} {}

template <typename>
PROTOBUF_CONSTEXPR Person_PhoneNumber::Person_PhoneNumber(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct Person_PhoneNumberDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Person_PhoneNumberDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~Person_PhoneNumberDefaultTypeInternal() {}
  union {
    Person_PhoneNumber _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Person_PhoneNumberDefaultTypeInternal _Person_PhoneNumber_default_instance_;

inline constexpr Person::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        phones_{},
        name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        email_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        id_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Person::Person(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct PersonDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PersonDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;

inline constexpr AddressBook::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : people_{},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR AddressBook::AddressBook(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct AddressBookDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AddressBookDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AddressBookDefaultTypeInternal() {}
  union {
    AddressBook _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AddressBookDefaultTypeInternal _AddressBook_default_instance_;
}  // namespace tutorial
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_addressbook_2eproto[1];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_addressbook_2eproto = nullptr;
const ::uint32_t
    TableStruct_addressbook_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, _impl_.number_),
        PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, _impl_.type_),
        0,
        1,
        PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::tutorial::Person, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.name_),
        PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.id_),
        PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.email_),
        PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.phones_),
        0,
        2,
        1,
        ~0u,
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::tutorial::AddressBook, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::tutorial::AddressBook, _impl_.people_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 10, -1, sizeof(::tutorial::Person_PhoneNumber)},
        {12, 24, -1, sizeof(::tutorial::Person)},
        {28, -1, -1, sizeof(::tutorial::AddressBook)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::tutorial::_Person_PhoneNumber_default_instance_._instance,
    &::tutorial::_Person_default_instance_._instance,
    &::tutorial::_AddressBook_default_instance_._instance,
};
const char descriptor_table_protodef_addressbook_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\021addressbook.proto\022\010tutorial\"\243\002\n\006Person"
    "\022\014\n\004name\030\001 \001(\t\022\n\n\002id\030\002 \001(\005\022\r\n\005email\030\003 \001("
    "\t\022,\n\006phones\030\004 \003(\0132\034.tutorial.Person.Phon"
    "eNumber\032X\n\013PhoneNumber\022\016\n\006number\030\001 \001(\t\0229"
    "\n\004type\030\002 \001(\0162\032.tutorial.Person.PhoneType"
    ":\017PHONE_TYPE_HOME\"h\n\tPhoneType\022\032\n\026PHONE_"
    "TYPE_UNSPECIFIED\020\000\022\025\n\021PHONE_TYPE_MOBILE\020"
    "\001\022\023\n\017PHONE_TYPE_HOME\020\002\022\023\n\017PHONE_TYPE_WOR"
    "K\020\003\"/\n\013AddressBook\022 \n\006people\030\001 \003(\0132\020.tut"
    "orial.Person"
};
static ::absl::once_flag descriptor_table_addressbook_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_addressbook_2eproto = {
    false,
    false,
    372,
    descriptor_table_protodef_addressbook_2eproto,
    "addressbook.proto",
    &descriptor_table_addressbook_2eproto_once,
    nullptr,
    0,
    3,
    schemas,
    file_default_instances,
    TableStruct_addressbook_2eproto::offsets,
    file_level_enum_descriptors_addressbook_2eproto,
    file_level_service_descriptors_addressbook_2eproto,
};
namespace tutorial {
const ::google::protobuf::EnumDescriptor* Person_PhoneType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_addressbook_2eproto);
  return file_level_enum_descriptors_addressbook_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t Person_PhoneType_internal_data_[] = {
    262144u, 0u, };
bool Person_PhoneType_IsValid(int value) {
  return 0 <= value && value <= 3;
}
#if (__cplusplus < 201703) && \
  (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

constexpr Person_PhoneType Person::PHONE_TYPE_UNSPECIFIED;
constexpr Person_PhoneType Person::PHONE_TYPE_MOBILE;
constexpr Person_PhoneType Person::PHONE_TYPE_HOME;
constexpr Person_PhoneType Person::PHONE_TYPE_WORK;
constexpr Person_PhoneType Person::PhoneType_MIN;
constexpr Person_PhoneType Person::PhoneType_MAX;
constexpr int Person::PhoneType_ARRAYSIZE;

#endif  // (__cplusplus < 201703) &&
        // (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
// ===================================================================

class Person_PhoneNumber::_Internal {
 public:
  using HasBits =
      decltype(std::declval<Person_PhoneNumber>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(Person_PhoneNumber, _impl_._has_bits_);
};

Person_PhoneNumber::Person_PhoneNumber(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tutorial.Person.PhoneNumber)
}
inline PROTOBUF_NDEBUG_INLINE Person_PhoneNumber::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::tutorial::Person_PhoneNumber& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        number_(arena, from.number_) {}

Person_PhoneNumber::Person_PhoneNumber(
    ::google::protobuf::Arena* arena,
    const Person_PhoneNumber& from)
    : ::google::protobuf::Message(arena) {
  Person_PhoneNumber* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  _impl_.type_ = from._impl_.type_;

  // @@protoc_insertion_point(copy_constructor:tutorial.Person.PhoneNumber)
}
inline PROTOBUF_NDEBUG_INLINE Person_PhoneNumber::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        number_(arena),
        type_{static_cast< ::tutorial::Person_PhoneType >(2)} {}

inline void Person_PhoneNumber::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Person_PhoneNumber::~Person_PhoneNumber() {
  // @@protoc_insertion_point(destructor:tutorial.Person.PhoneNumber)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Person_PhoneNumber::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.number_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Person_PhoneNumber::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(Person_PhoneNumber, _impl_._cached_size_),
              false,
          },
          &Person_PhoneNumber::MergeImpl,
          &Person_PhoneNumber::kDescriptorMethods,
          &descriptor_table_addressbook_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 1, 42, 2> Person_PhoneNumber::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Person_PhoneNumber, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_Person_PhoneNumber_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::tutorial::Person_PhoneNumber>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // optional .tutorial.Person.PhoneType type = 2 [default = PHONE_TYPE_HOME];
    {::_pbi::TcParser::FastEr0S1,
     {16, 1, 3, PROTOBUF_FIELD_OFFSET(Person_PhoneNumber, _impl_.type_)}},
    // optional string number = 1;
    {::_pbi::TcParser::FastSS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(Person_PhoneNumber, _impl_.number_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional string number = 1;
    {PROTOBUF_FIELD_OFFSET(Person_PhoneNumber, _impl_.number_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional .tutorial.Person.PhoneType type = 2 [default = PHONE_TYPE_HOME];
    {PROTOBUF_FIELD_OFFSET(Person_PhoneNumber, _impl_.type_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kEnumRange)},
  }}, {{
    {0, 4},
  }}, {{
    "\33\6\0\0\0\0\0\0"
    "tutorial.Person.PhoneNumber"
    "number"
  }},
};

PROTOBUF_NOINLINE void Person_PhoneNumber::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.Person.PhoneNumber)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.number_.ClearNonDefaultToEmpty();
    }
    _impl_.type_ = 2;
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Person_PhoneNumber::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.Person.PhoneNumber)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional string number = 1;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_number();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "tutorial.Person.PhoneNumber.number");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // optional .tutorial.Person.PhoneType type = 2 [default = PHONE_TYPE_HOME];
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        2, this->_internal_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.Person.PhoneNumber)
  return target;
}

::size_t Person_PhoneNumber::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.Person.PhoneNumber)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string number = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_number());
    }

    // optional .tutorial.Person.PhoneType type = 2 [default = PHONE_TYPE_HOME];
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
                    ::_pbi::WireFormatLite::EnumSize(this->_internal_type());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Person_PhoneNumber::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Person_PhoneNumber*>(&to_msg);
  auto& from = static_cast<const Person_PhoneNumber&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.Person.PhoneNumber)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_number(from._internal_number());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_impl_.type_ = from._impl_.type_;
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Person_PhoneNumber::CopyFrom(const Person_PhoneNumber& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.Person.PhoneNumber)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Person_PhoneNumber::InternalSwap(Person_PhoneNumber* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.number_, &other->_impl_.number_, arena);
  swap(_impl_.type_, other->_impl_.type_);
}

::google::protobuf::Metadata Person_PhoneNumber::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class Person::_Internal {
 public:
  using HasBits =
      decltype(std::declval<Person>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(Person, _impl_._has_bits_);
};

Person::Person(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tutorial.Person)
}
inline PROTOBUF_NDEBUG_INLINE Person::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::tutorial::Person& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        phones_{visibility, arena, from.phones_},
        name_(arena, from.name_),
        email_(arena, from.email_) {}

Person::Person(
    ::google::protobuf::Arena* arena,
    const Person& from)
    : ::google::protobuf::Message(arena) {
  Person* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  _impl_.id_ = from._impl_.id_;

  // @@protoc_insertion_point(copy_constructor:tutorial.Person)
}
inline PROTOBUF_NDEBUG_INLINE Person::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        phones_{visibility, arena},
        name_(arena),
        email_(arena) {}

inline void Person::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.id_ = {};
}
Person::~Person() {
  // @@protoc_insertion_point(destructor:tutorial.Person)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Person::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.name_.Destroy();
  _impl_.email_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Person::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(Person, _impl_._cached_size_),
              false,
          },
          &Person::MergeImpl,
          &Person::kDescriptorMethods,
          &descriptor_table_addressbook_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 1, 33, 2> Person::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Person, _impl_._has_bits_),
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_Person_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::tutorial::Person>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .tutorial.Person.PhoneNumber phones = 4;
    {::_pbi::TcParser::FastMtR1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.phones_)}},
    // optional string name = 1;
    {::_pbi::TcParser::FastSS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.name_)}},
    // optional int32 id = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Person, _impl_.id_), 2>(),
     {16, 2, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.id_)}},
    // optional string email = 3;
    {::_pbi::TcParser::FastSS1,
     {26, 1, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.email_)}},
  }}, {{
    65535, 65535
  }}, {{
    // optional string name = 1;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.name_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional int32 id = 2;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.id_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional string email = 3;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.email_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // repeated .tutorial.Person.PhoneNumber phones = 4;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.phones_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::tutorial::Person_PhoneNumber>()},
  }}, {{
    "\17\4\0\5\0\0\0\0"
    "tutorial.Person"
    "name"
    "email"
  }},
};

PROTOBUF_NOINLINE void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.Person)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.phones_.Clear();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      _impl_.email_.ClearNonDefaultToEmpty();
    }
  }
  _impl_.id_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Person::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.Person)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional string name = 1;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_name();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "tutorial.Person.name");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // optional int32 id = 2;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<2>(
            stream, this->_internal_id(), target);
  }

  // optional string email = 3;
  if (cached_has_bits & 0x00000002u) {
    const std::string& _s = this->_internal_email();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "tutorial.Person.email");
    target = stream->WriteStringMaybeAliased(3, _s, target);
  }

  // repeated .tutorial.Person.PhoneNumber phones = 4;
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_phones_size());
       i < n; i++) {
    const auto& repfield = this->_internal_phones().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            4, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.Person)
  return target;
}

::size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.Person)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // repeated .tutorial.Person.PhoneNumber phones = 4;
  total_size += 1UL * this->_internal_phones_size();
  for (const auto& msg : this->_internal_phones()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional string name = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_name());
    }

    // optional string email = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_email());
    }

    // optional int32 id = 2;
    if (cached_has_bits & 0x00000004u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_id());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Person::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Person*>(&to_msg);
  auto& from = static_cast<const Person&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.Person)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_phones()->MergeFrom(
      from._internal_phones());
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_name(from._internal_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_set_email(from._internal_email());
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.id_ = from._impl_.id_;
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Person::InternalSwap(Person* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.phones_.InternalSwap(&other->_impl_.phones_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.name_, &other->_impl_.name_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.email_, &other->_impl_.email_, arena);
        swap(_impl_.id_, other->_impl_.id_);
}

::google::protobuf::Metadata Person::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class AddressBook::_Internal {
 public:
};

AddressBook::AddressBook(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tutorial.AddressBook)
}
inline PROTOBUF_NDEBUG_INLINE AddressBook::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::tutorial::AddressBook& from_msg)
      : people_{visibility, arena, from.people_},
        _cached_size_{0} {}

AddressBook::AddressBook(
    ::google::protobuf::Arena* arena,
    const AddressBook& from)
    : ::google::protobuf::Message(arena) {
  AddressBook* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:tutorial.AddressBook)
}
inline PROTOBUF_NDEBUG_INLINE AddressBook::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : people_{visibility, arena},
        _cached_size_{0} {}

inline void AddressBook::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
AddressBook::~AddressBook() {
  // @@protoc_insertion_point(destructor:tutorial.AddressBook)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void AddressBook::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
AddressBook::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(AddressBook, _impl_._cached_size_),
              false,
          },
          &AddressBook::MergeImpl,
          &AddressBook::kDescriptorMethods,
          &descriptor_table_addressbook_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 1, 0, 2> AddressBook::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_AddressBook_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::tutorial::AddressBook>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .tutorial.Person people = 1;
    {::_pbi::TcParser::FastMtR1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(AddressBook, _impl_.people_)}},
  }}, {{
    65535, 65535
  }}, {{
    // repeated .tutorial.Person people = 1;
    {PROTOBUF_FIELD_OFFSET(AddressBook, _impl_.people_), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::tutorial::Person>()},
  }}, {{
  }},
};

PROTOBUF_NOINLINE void AddressBook::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.AddressBook)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.people_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* AddressBook::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.AddressBook)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // repeated .tutorial.Person people = 1;
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_people_size());
       i < n; i++) {
    const auto& repfield = this->_internal_people().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            1, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.AddressBook)
  return target;
}

::size_t AddressBook::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.AddressBook)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // repeated .tutorial.Person people = 1;
  total_size += 1UL * this->_internal_people_size();
  for (const auto& msg : this->_internal_people()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void AddressBook::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<AddressBook*>(&to_msg);
  auto& from = static_cast<const AddressBook&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.AddressBook)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_people()->MergeFrom(
      from._internal_people());
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void AddressBook::CopyFrom(const AddressBook& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.AddressBook)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void AddressBook::InternalSwap(AddressBook* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.people_.InternalSwap(&other->_impl_.people_);
}

::google::protobuf::Metadata AddressBook::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace tutorial
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_addressbook_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
