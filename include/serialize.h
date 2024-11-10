// GenericMessageSerialization.h

#ifndef GENERIC_MESSAGE_SERIALIZATION_H
#define GENERIC_MESSAGE_SERIALIZATION_H
#include <variant>
#include <iostream>
#include <string>
#include <stdexcept>
#include <type_traits>
#include "../generic.pb.h"  // 假设这个是生成的 Protocol Buffer 文件

// 创建消息数据，根据不同的数据类型设置相应的字段值
template <typename T>
GenericMessage createMessageData(const T& data) {
    GenericMessage message;
    if (std::is_same<T, int>::value) {
        message.set_int_value((int) data);
    } else if (std::is_same<T, float>::value) {
        message.set_float_value(data);
    } else if (std::is_same<T, bool>::value) {
        message.set_bool_value(data);
    } else if (std::is_same<T, double>::value) {
        message.set_double_value(data);
    } else if (std::is_same<T, int64_t>::value) {
        message.set_int64_value(data);
    } else {
        throw std::invalid_argument("Unsupported data type");
    }
    return message;
}

// 序列化函数：将 GenericMessage 对象序列化为字符串
std::string serializeMessage(const GenericMessage& message) {
    std::string serializedData;
    if (!message.SerializeToString(&serializedData)) {
        throw std::runtime_error("Serialization failed");
    }
    return serializedData;
}

// 反序列化函数：将字符串反序列化为 GenericMessage 对象
GenericMessage deserializeMessage(const std::string& serializedData) {
    GenericMessage message;
    if (!message.ParseFromString(serializedData)) {
        throw std::runtime_error("Failed to parse data");
    }
    return message;
}

int GetMessageInt(GenericMessage message){
    if (message.has_int_value()) {
        return message.int_value();
    }
    return 0;
}


// 定义可能的类型
using MessageValue = std::variant<int, float, std::string, bool, double, int64_t>;

// 类型检测：返回反序列化后的 GenericMessage 中的值
MessageValue getMessageValue(const GenericMessage& message) {
    if (message.has_int_value()) {
        return message.int_value();
    } else if (message.has_float_value()) {
        return message.float_value();
    }  else if (message.has_bool_value()) {
        return message.bool_value();
    } else if (message.has_double_value()) {
        return message.double_value();
    } else if (message.has_int64_value()) {
        return message.int64_value();
    } else if(message.has_string_value()){
        return message.string_value();
    } else {
        throw std::runtime_error("No value set in the message");
    }
}
// 辅助函数：根据返回的 MessageValue 的类型进行处理
void printMessageValue(const MessageValue& value) {
    std::visit([](auto&& arg) {
        std::cout << "Deserialized value: " << arg << std::endl;
    }, value);
}

#endif // GENERIC_MESSAGE_SERIALIZATION_H
