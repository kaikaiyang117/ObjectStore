cmake_minimum_required(VERSION 3.5)
project(GenericProtobufExample)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Protobuf包
find_package(Protobuf REQUIRED)

# 包含Protobuf头文件目录
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(Test)
include_directories(include)

# 生成Protobuf编译的C++文件
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS generic.proto)

add_executable(${PROJECT_NAME} main.cpp ${PROTO_SRCS} ${PROTO_HDRS}
        include/serialize.h)

target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})

add_executable(TestMemoery Test/Memoery.cpp ${PROTO_SRCS} ${PROTO_HDRS}
        include/serialize.h
        src/LRUCache.cpp
        include/LRUCache.h
        src/LRUCache.cpp)
target_link_libraries(TestMemoery ${PROTOBUF_LIBRARIES})

add_executable(TestWrite Test/testWrite.cpp
        include/LRUCache.h
        src/LRUCache.cpp)