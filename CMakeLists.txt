cmake_minimum_required(VERSION 3.5)
project(GenericProtobufExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Protobuf 包
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(include)

# 生成 Protobuf C++ 文件
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS generic.proto)

# 定义共享库 kvstore
add_library(kvstore SHARED
        src/KVStore.cpp
        src/LRUCache.cpp
        ${PROTO_SRCS} # 包含生成的 Protobuf 源文件
)

# 链接 Protobuf 到共享库
target_link_libraries(kvstore ${Protobuf_LIBRARIES})

# 主程序
add_executable(${PROJECT_NAME} Test/TestSerial.cpp include/serialize.h include/KVStore.h)
target_link_libraries(${PROJECT_NAME} kvstore pthread)

# 测试程序 TestMemoery
add_executable(Main main.cpp include/KVStore.h)
target_link_libraries(Main kvstore pthread)


add_executable(TestWrite Test/testWrite.cpp include/LRUCache.h)
target_link_libraries(TestWrite kvstore pthread)
