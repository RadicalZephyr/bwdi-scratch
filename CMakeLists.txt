project(bwdi CXX C)

cmake_minimum_required(VERSION 2.6.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/Packages/")

find_package(Boost REQUIRED)
include_directories("${Boost_INCLUDE_DIRS}")

find_package(POCO REQUIRED)
include_directories("${POCO_INCLUDE_DIRS}")

find_package(Protobuf REQUIRED)
#   include_directories(${PROTOBUF_INCLUDE_DIRS})
#   PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS foo.proto)
#   add_executable(bar bar.cc ${PROTO_SRCS} ${PROTO_HDRS})
#   target_link_libraries(bar ${PROTOBUF_LIBRARIES})

add_subdirectory("gmock")

enable_testing()

add_subdirectory("hack")
add_subdirectory("driver")
add_subdirectory("client")
