// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: generic.proto

#include "generic.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr GenericMessage::GenericMessage(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : _oneof_case_{}{}
struct GenericMessageDefaultTypeInternal {
  constexpr GenericMessageDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~GenericMessageDefaultTypeInternal() {}
  union {
    GenericMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT GenericMessageDefaultTypeInternal _GenericMessage_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_generic_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_generic_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_generic_2eproto = nullptr;

const uint32_t TableStruct_generic_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::GenericMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::GenericMessage, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::GenericMessage, value_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::GenericMessage)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_GenericMessage_default_instance_),
};

const char descriptor_table_protodef_generic_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rgeneric.proto\"\271\001\n\016GenericMessage\022\023\n\tin"
  "t_value\030\001 \001(\005H\000\022\025\n\013float_value\030\002 \001(\002H\000\022\026"
  "\n\014string_value\030\003 \001(\tH\000\022\025\n\013bytes_value\030\004 "
  "\001(\014H\000\022\024\n\nbool_value\030\005 \001(\010H\000\022\026\n\014double_va"
  "lue\030\006 \001(\001H\000\022\025\n\013int64_value\030\007 \001(\003H\000B\007\n\005va"
  "lueb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_generic_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_generic_2eproto = {
  false, false, 211, descriptor_table_protodef_generic_2eproto, "generic.proto", 
  &descriptor_table_generic_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_generic_2eproto::offsets,
  file_level_metadata_generic_2eproto, file_level_enum_descriptors_generic_2eproto, file_level_service_descriptors_generic_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_generic_2eproto_getter() {
  return &descriptor_table_generic_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_generic_2eproto(&descriptor_table_generic_2eproto);

// ===================================================================

class GenericMessage::_Internal {
 public:
};

GenericMessage::GenericMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:GenericMessage)
}
GenericMessage::GenericMessage(const GenericMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  clear_has_value();
  switch (from.value_case()) {
    case kIntValue: {
      _internal_set_int_value(from._internal_int_value());
      break;
    }
    case kFloatValue: {
      _internal_set_float_value(from._internal_float_value());
      break;
    }
    case kStringValue: {
      _internal_set_string_value(from._internal_string_value());
      break;
    }
    case kBytesValue: {
      _internal_set_bytes_value(from._internal_bytes_value());
      break;
    }
    case kBoolValue: {
      _internal_set_bool_value(from._internal_bool_value());
      break;
    }
    case kDoubleValue: {
      _internal_set_double_value(from._internal_double_value());
      break;
    }
    case kInt64Value: {
      _internal_set_int64_value(from._internal_int64_value());
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:GenericMessage)
}

inline void GenericMessage::SharedCtor() {
clear_has_value();
}

GenericMessage::~GenericMessage() {
  // @@protoc_insertion_point(destructor:GenericMessage)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void GenericMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (has_value()) {
    clear_value();
  }
}

void GenericMessage::ArenaDtor(void* object) {
  GenericMessage* _this = reinterpret_cast< GenericMessage* >(object);
  (void)_this;
}
void GenericMessage::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GenericMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void GenericMessage::clear_value() {
// @@protoc_insertion_point(one_of_clear_start:GenericMessage)
  switch (value_case()) {
    case kIntValue: {
      // No need to clear
      break;
    }
    case kFloatValue: {
      // No need to clear
      break;
    }
    case kStringValue: {
      value_.string_value_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
      break;
    }
    case kBytesValue: {
      value_.bytes_value_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
      break;
    }
    case kBoolValue: {
      // No need to clear
      break;
    }
    case kDoubleValue: {
      // No need to clear
      break;
    }
    case kInt64Value: {
      // No need to clear
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = VALUE_NOT_SET;
}


void GenericMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:GenericMessage)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clear_value();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GenericMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 int_value = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _internal_set_int_value(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // float float_value = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 21)) {
          _internal_set_float_value(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr));
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // string string_value = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_string_value();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "GenericMessage.string_value"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes bytes_value = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_bytes_value();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool bool_value = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _internal_set_bool_value(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double double_value = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 49)) {
          _internal_set_double_value(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      // int64 int64_value = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 56)) {
          _internal_set_int64_value(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* GenericMessage::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:GenericMessage)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 int_value = 1;
  if (_internal_has_int_value()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_int_value(), target);
  }

  // float float_value = 2;
  if (_internal_has_float_value()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_float_value(), target);
  }

  // string string_value = 3;
  if (_internal_has_string_value()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_string_value().data(), static_cast<int>(this->_internal_string_value().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "GenericMessage.string_value");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_string_value(), target);
  }

  // bytes bytes_value = 4;
  if (_internal_has_bytes_value()) {
    target = stream->WriteBytesMaybeAliased(
        4, this->_internal_bytes_value(), target);
  }

  // bool bool_value = 5;
  if (_internal_has_bool_value()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal_bool_value(), target);
  }

  // double double_value = 6;
  if (_internal_has_double_value()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(6, this->_internal_double_value(), target);
  }

  // int64 int64_value = 7;
  if (_internal_has_int64_value()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(7, this->_internal_int64_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GenericMessage)
  return target;
}

size_t GenericMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GenericMessage)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  switch (value_case()) {
    // int32 int_value = 1;
    case kIntValue: {
      total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_int_value());
      break;
    }
    // float float_value = 2;
    case kFloatValue: {
      total_size += 1 + 4;
      break;
    }
    // string string_value = 3;
    case kStringValue: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_string_value());
      break;
    }
    // bytes bytes_value = 4;
    case kBytesValue: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_bytes_value());
      break;
    }
    // bool bool_value = 5;
    case kBoolValue: {
      total_size += 1 + 1;
      break;
    }
    // double double_value = 6;
    case kDoubleValue: {
      total_size += 1 + 8;
      break;
    }
    // int64 int64_value = 7;
    case kInt64Value: {
      total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64SizePlusOne(this->_internal_int64_value());
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GenericMessage::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    GenericMessage::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GenericMessage::GetClassData() const { return &_class_data_; }

void GenericMessage::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<GenericMessage *>(to)->MergeFrom(
      static_cast<const GenericMessage &>(from));
}


void GenericMessage::MergeFrom(const GenericMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GenericMessage)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  switch (from.value_case()) {
    case kIntValue: {
      _internal_set_int_value(from._internal_int_value());
      break;
    }
    case kFloatValue: {
      _internal_set_float_value(from._internal_float_value());
      break;
    }
    case kStringValue: {
      _internal_set_string_value(from._internal_string_value());
      break;
    }
    case kBytesValue: {
      _internal_set_bytes_value(from._internal_bytes_value());
      break;
    }
    case kBoolValue: {
      _internal_set_bool_value(from._internal_bool_value());
      break;
    }
    case kDoubleValue: {
      _internal_set_double_value(from._internal_double_value());
      break;
    }
    case kInt64Value: {
      _internal_set_int64_value(from._internal_int64_value());
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GenericMessage::CopyFrom(const GenericMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GenericMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GenericMessage::IsInitialized() const {
  return true;
}

void GenericMessage::InternalSwap(GenericMessage* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(value_, other->value_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata GenericMessage::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_generic_2eproto_getter, &descriptor_table_generic_2eproto_once,
      file_level_metadata_generic_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::GenericMessage* Arena::CreateMaybeMessage< ::GenericMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::GenericMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
