// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: generic.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_generic_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_generic_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_generic_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_generic_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_generic_2eproto;
class GenericMessage;
struct GenericMessageDefaultTypeInternal;
extern GenericMessageDefaultTypeInternal _GenericMessage_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::GenericMessage* Arena::CreateMaybeMessage<::GenericMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class GenericMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:GenericMessage) */ {
 public:
  inline GenericMessage() : GenericMessage(nullptr) {}
  ~GenericMessage() override;
  explicit constexpr GenericMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GenericMessage(const GenericMessage& from);
  GenericMessage(GenericMessage&& from) noexcept
    : GenericMessage() {
    *this = ::std::move(from);
  }

  inline GenericMessage& operator=(const GenericMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline GenericMessage& operator=(GenericMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const GenericMessage& default_instance() {
    return *internal_default_instance();
  }
  enum ValueCase {
    kIntValue = 1,
    kFloatValue = 2,
    kStringValue = 3,
    kBytesValue = 4,
    kBoolValue = 5,
    kDoubleValue = 6,
    kInt64Value = 7,
    VALUE_NOT_SET = 0,
  };

  static inline const GenericMessage* internal_default_instance() {
    return reinterpret_cast<const GenericMessage*>(
               &_GenericMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GenericMessage& a, GenericMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(GenericMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GenericMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GenericMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<GenericMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const GenericMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const GenericMessage& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GenericMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "GenericMessage";
  }
  protected:
  explicit GenericMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIntValueFieldNumber = 1,
    kFloatValueFieldNumber = 2,
    kStringValueFieldNumber = 3,
    kBytesValueFieldNumber = 4,
    kBoolValueFieldNumber = 5,
    kDoubleValueFieldNumber = 6,
    kInt64ValueFieldNumber = 7,
  };
  // int32 int_value = 1;
  bool has_int_value() const;
  private:
  bool _internal_has_int_value() const;
  public:
  void clear_int_value();
  int32_t int_value() const;
  void set_int_value(int32_t value);
  private:
  int32_t _internal_int_value() const;
  void _internal_set_int_value(int32_t value);
  public:

  // float float_value = 2;
  bool has_float_value() const;
  private:
  bool _internal_has_float_value() const;
  public:
  void clear_float_value();
  float float_value() const;
  void set_float_value(float value);
  private:
  float _internal_float_value() const;
  void _internal_set_float_value(float value);
  public:

  // string string_value = 3;
  bool has_string_value() const;
  private:
  bool _internal_has_string_value() const;
  public:
  void clear_string_value();
  const std::string& string_value() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_string_value(ArgT0&& arg0, ArgT... args);
  std::string* mutable_string_value();
  PROTOBUF_NODISCARD std::string* release_string_value();
  void set_allocated_string_value(std::string* string_value);
  private:
  const std::string& _internal_string_value() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_string_value(const std::string& value);
  std::string* _internal_mutable_string_value();
  public:

  // bytes bytes_value = 4;
  bool has_bytes_value() const;
  private:
  bool _internal_has_bytes_value() const;
  public:
  void clear_bytes_value();
  const std::string& bytes_value() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_bytes_value(ArgT0&& arg0, ArgT... args);
  std::string* mutable_bytes_value();
  PROTOBUF_NODISCARD std::string* release_bytes_value();
  void set_allocated_bytes_value(std::string* bytes_value);
  private:
  const std::string& _internal_bytes_value() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_bytes_value(const std::string& value);
  std::string* _internal_mutable_bytes_value();
  public:

  // bool bool_value = 5;
  bool has_bool_value() const;
  private:
  bool _internal_has_bool_value() const;
  public:
  void clear_bool_value();
  bool bool_value() const;
  void set_bool_value(bool value);
  private:
  bool _internal_bool_value() const;
  void _internal_set_bool_value(bool value);
  public:

  // double double_value = 6;
  bool has_double_value() const;
  private:
  bool _internal_has_double_value() const;
  public:
  void clear_double_value();
  double double_value() const;
  void set_double_value(double value);
  private:
  double _internal_double_value() const;
  void _internal_set_double_value(double value);
  public:

  // int64 int64_value = 7;
  bool has_int64_value() const;
  private:
  bool _internal_has_int64_value() const;
  public:
  void clear_int64_value();
  int64_t int64_value() const;
  void set_int64_value(int64_t value);
  private:
  int64_t _internal_int64_value() const;
  void _internal_set_int64_value(int64_t value);
  public:

  void clear_value();
  ValueCase value_case() const;
  // @@protoc_insertion_point(class_scope:GenericMessage)
 private:
  class _Internal;
  void set_has_int_value();
  void set_has_float_value();
  void set_has_string_value();
  void set_has_bytes_value();
  void set_has_bool_value();
  void set_has_double_value();
  void set_has_int64_value();

  inline bool has_value() const;
  inline void clear_has_value();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  union ValueUnion {
    constexpr ValueUnion() : _constinit_{} {}
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
    int32_t int_value_;
    float float_value_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr string_value_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr bytes_value_;
    bool bool_value_;
    double double_value_;
    int64_t int64_value_;
  } value_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  uint32_t _oneof_case_[1];

  friend struct ::TableStruct_generic_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GenericMessage

// int32 int_value = 1;
inline bool GenericMessage::_internal_has_int_value() const {
  return value_case() == kIntValue;
}
inline bool GenericMessage::has_int_value() const {
  return _internal_has_int_value();
}
inline void GenericMessage::set_has_int_value() {
  _oneof_case_[0] = kIntValue;
}
inline void GenericMessage::clear_int_value() {
  if (_internal_has_int_value()) {
    value_.int_value_ = 0;
    clear_has_value();
  }
}
inline int32_t GenericMessage::_internal_int_value() const {
  if (_internal_has_int_value()) {
    return value_.int_value_;
  }
  return 0;
}
inline void GenericMessage::_internal_set_int_value(int32_t value) {
  if (!_internal_has_int_value()) {
    clear_value();
    set_has_int_value();
  }
  value_.int_value_ = value;
}
inline int32_t GenericMessage::int_value() const {
  // @@protoc_insertion_point(field_get:GenericMessage.int_value)
  return _internal_int_value();
}
inline void GenericMessage::set_int_value(int32_t value) {
  _internal_set_int_value(value);
  // @@protoc_insertion_point(field_set:GenericMessage.int_value)
}

// float float_value = 2;
inline bool GenericMessage::_internal_has_float_value() const {
  return value_case() == kFloatValue;
}
inline bool GenericMessage::has_float_value() const {
  return _internal_has_float_value();
}
inline void GenericMessage::set_has_float_value() {
  _oneof_case_[0] = kFloatValue;
}
inline void GenericMessage::clear_float_value() {
  if (_internal_has_float_value()) {
    value_.float_value_ = 0;
    clear_has_value();
  }
}
inline float GenericMessage::_internal_float_value() const {
  if (_internal_has_float_value()) {
    return value_.float_value_;
  }
  return 0;
}
inline void GenericMessage::_internal_set_float_value(float value) {
  if (!_internal_has_float_value()) {
    clear_value();
    set_has_float_value();
  }
  value_.float_value_ = value;
}
inline float GenericMessage::float_value() const {
  // @@protoc_insertion_point(field_get:GenericMessage.float_value)
  return _internal_float_value();
}
inline void GenericMessage::set_float_value(float value) {
  _internal_set_float_value(value);
  // @@protoc_insertion_point(field_set:GenericMessage.float_value)
}

// string string_value = 3;
inline bool GenericMessage::_internal_has_string_value() const {
  return value_case() == kStringValue;
}
inline bool GenericMessage::has_string_value() const {
  return _internal_has_string_value();
}
inline void GenericMessage::set_has_string_value() {
  _oneof_case_[0] = kStringValue;
}
inline void GenericMessage::clear_string_value() {
  if (_internal_has_string_value()) {
    value_.string_value_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
    clear_has_value();
  }
}
inline const std::string& GenericMessage::string_value() const {
  // @@protoc_insertion_point(field_get:GenericMessage.string_value)
  return _internal_string_value();
}
template <typename ArgT0, typename... ArgT>
inline void GenericMessage::set_string_value(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_string_value()) {
    clear_value();
    set_has_string_value();
    value_.string_value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.string_value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:GenericMessage.string_value)
}
inline std::string* GenericMessage::mutable_string_value() {
  std::string* _s = _internal_mutable_string_value();
  // @@protoc_insertion_point(field_mutable:GenericMessage.string_value)
  return _s;
}
inline const std::string& GenericMessage::_internal_string_value() const {
  if (_internal_has_string_value()) {
    return value_.string_value_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void GenericMessage::_internal_set_string_value(const std::string& value) {
  if (!_internal_has_string_value()) {
    clear_value();
    set_has_string_value();
    value_.string_value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.string_value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* GenericMessage::_internal_mutable_string_value() {
  if (!_internal_has_string_value()) {
    clear_value();
    set_has_string_value();
    value_.string_value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return value_.string_value_.Mutable(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* GenericMessage::release_string_value() {
  // @@protoc_insertion_point(field_release:GenericMessage.string_value)
  if (_internal_has_string_value()) {
    clear_has_value();
    return value_.string_value_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
  } else {
    return nullptr;
  }
}
inline void GenericMessage::set_allocated_string_value(std::string* string_value) {
  if (has_value()) {
    clear_value();
  }
  if (string_value != nullptr) {
    set_has_string_value();
    value_.string_value_.UnsafeSetDefault(string_value);
    ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaForAllocation();
    if (arena != nullptr) {
      arena->Own(string_value);
    }
  }
  // @@protoc_insertion_point(field_set_allocated:GenericMessage.string_value)
}

// bytes bytes_value = 4;
inline bool GenericMessage::_internal_has_bytes_value() const {
  return value_case() == kBytesValue;
}
inline bool GenericMessage::has_bytes_value() const {
  return _internal_has_bytes_value();
}
inline void GenericMessage::set_has_bytes_value() {
  _oneof_case_[0] = kBytesValue;
}
inline void GenericMessage::clear_bytes_value() {
  if (_internal_has_bytes_value()) {
    value_.bytes_value_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
    clear_has_value();
  }
}
inline const std::string& GenericMessage::bytes_value() const {
  // @@protoc_insertion_point(field_get:GenericMessage.bytes_value)
  return _internal_bytes_value();
}
template <typename ArgT0, typename... ArgT>
inline void GenericMessage::set_bytes_value(ArgT0&& arg0, ArgT... args) {
  if (!_internal_has_bytes_value()) {
    clear_value();
    set_has_bytes_value();
    value_.bytes_value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.bytes_value_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:GenericMessage.bytes_value)
}
inline std::string* GenericMessage::mutable_bytes_value() {
  std::string* _s = _internal_mutable_bytes_value();
  // @@protoc_insertion_point(field_mutable:GenericMessage.bytes_value)
  return _s;
}
inline const std::string& GenericMessage::_internal_bytes_value() const {
  if (_internal_has_bytes_value()) {
    return value_.bytes_value_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void GenericMessage::_internal_set_bytes_value(const std::string& value) {
  if (!_internal_has_bytes_value()) {
    clear_value();
    set_has_bytes_value();
    value_.bytes_value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.bytes_value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* GenericMessage::_internal_mutable_bytes_value() {
  if (!_internal_has_bytes_value()) {
    clear_value();
    set_has_bytes_value();
    value_.bytes_value_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return value_.bytes_value_.Mutable(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* GenericMessage::release_bytes_value() {
  // @@protoc_insertion_point(field_release:GenericMessage.bytes_value)
  if (_internal_has_bytes_value()) {
    clear_has_value();
    return value_.bytes_value_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
  } else {
    return nullptr;
  }
}
inline void GenericMessage::set_allocated_bytes_value(std::string* bytes_value) {
  if (has_value()) {
    clear_value();
  }
  if (bytes_value != nullptr) {
    set_has_bytes_value();
    value_.bytes_value_.UnsafeSetDefault(bytes_value);
    ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaForAllocation();
    if (arena != nullptr) {
      arena->Own(bytes_value);
    }
  }
  // @@protoc_insertion_point(field_set_allocated:GenericMessage.bytes_value)
}

// bool bool_value = 5;
inline bool GenericMessage::_internal_has_bool_value() const {
  return value_case() == kBoolValue;
}
inline bool GenericMessage::has_bool_value() const {
  return _internal_has_bool_value();
}
inline void GenericMessage::set_has_bool_value() {
  _oneof_case_[0] = kBoolValue;
}
inline void GenericMessage::clear_bool_value() {
  if (_internal_has_bool_value()) {
    value_.bool_value_ = false;
    clear_has_value();
  }
}
inline bool GenericMessage::_internal_bool_value() const {
  if (_internal_has_bool_value()) {
    return value_.bool_value_;
  }
  return false;
}
inline void GenericMessage::_internal_set_bool_value(bool value) {
  if (!_internal_has_bool_value()) {
    clear_value();
    set_has_bool_value();
  }
  value_.bool_value_ = value;
}
inline bool GenericMessage::bool_value() const {
  // @@protoc_insertion_point(field_get:GenericMessage.bool_value)
  return _internal_bool_value();
}
inline void GenericMessage::set_bool_value(bool value) {
  _internal_set_bool_value(value);
  // @@protoc_insertion_point(field_set:GenericMessage.bool_value)
}

// double double_value = 6;
inline bool GenericMessage::_internal_has_double_value() const {
  return value_case() == kDoubleValue;
}
inline bool GenericMessage::has_double_value() const {
  return _internal_has_double_value();
}
inline void GenericMessage::set_has_double_value() {
  _oneof_case_[0] = kDoubleValue;
}
inline void GenericMessage::clear_double_value() {
  if (_internal_has_double_value()) {
    value_.double_value_ = 0;
    clear_has_value();
  }
}
inline double GenericMessage::_internal_double_value() const {
  if (_internal_has_double_value()) {
    return value_.double_value_;
  }
  return 0;
}
inline void GenericMessage::_internal_set_double_value(double value) {
  if (!_internal_has_double_value()) {
    clear_value();
    set_has_double_value();
  }
  value_.double_value_ = value;
}
inline double GenericMessage::double_value() const {
  // @@protoc_insertion_point(field_get:GenericMessage.double_value)
  return _internal_double_value();
}
inline void GenericMessage::set_double_value(double value) {
  _internal_set_double_value(value);
  // @@protoc_insertion_point(field_set:GenericMessage.double_value)
}

// int64 int64_value = 7;
inline bool GenericMessage::_internal_has_int64_value() const {
  return value_case() == kInt64Value;
}
inline bool GenericMessage::has_int64_value() const {
  return _internal_has_int64_value();
}
inline void GenericMessage::set_has_int64_value() {
  _oneof_case_[0] = kInt64Value;
}
inline void GenericMessage::clear_int64_value() {
  if (_internal_has_int64_value()) {
    value_.int64_value_ = int64_t{0};
    clear_has_value();
  }
}
inline int64_t GenericMessage::_internal_int64_value() const {
  if (_internal_has_int64_value()) {
    return value_.int64_value_;
  }
  return int64_t{0};
}
inline void GenericMessage::_internal_set_int64_value(int64_t value) {
  if (!_internal_has_int64_value()) {
    clear_value();
    set_has_int64_value();
  }
  value_.int64_value_ = value;
}
inline int64_t GenericMessage::int64_value() const {
  // @@protoc_insertion_point(field_get:GenericMessage.int64_value)
  return _internal_int64_value();
}
inline void GenericMessage::set_int64_value(int64_t value) {
  _internal_set_int64_value(value);
  // @@protoc_insertion_point(field_set:GenericMessage.int64_value)
}

inline bool GenericMessage::has_value() const {
  return value_case() != VALUE_NOT_SET;
}
inline void GenericMessage::clear_has_value() {
  _oneof_case_[0] = VALUE_NOT_SET;
}
inline GenericMessage::ValueCase GenericMessage::value_case() const {
  return GenericMessage::ValueCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_generic_2eproto
