project(bwdi CXX)

cmake_minimum_required(VERSION 2.6)

find_package(Boost REQUIRED)
include_directories("${Boost_INCLUDE_DIRS}")

add_subdirectory("hack")
add_subdirectory("driver")
add_subdirectory("client")
