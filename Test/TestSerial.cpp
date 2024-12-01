
#include "serialize.h"
#include <typeinfo>

int main() {
    int data = 278;
    GenericMessage message;
    message = createMessageData(data);
    std::string serializedData = serializeMessage(message);
    GenericMessage deserializedMessage = deserializeMessage(serializedData);
    auto value = getMessageValue(deserializedMessage);
    printMessageValue(value);
    return 0;
}