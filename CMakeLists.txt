project(bwdi CXX C)

cmake_minimum_required(VERSION 2.6.2)

find_package(Boost REQUIRED)
include_directories("${Boost_INCLUDE_DIRS}")

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

add_subdirectory("hack")
add_subdirectory("driver")
add_subdirectory("client")
