cmake_minimum_required(VERSION 3.0)
project (Tempest)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
set(CMAKE_CXX_STATNDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(Color SHARED src/color.cpp)
target_link_libraries(Color  ${SDL2_LIBRARIES})
