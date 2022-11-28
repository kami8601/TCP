cmake_minimum_required(VERSION 3.0.2)

project(main)

set(OpenCV_DIR /home/syx/local)

include_directories(include/)

aux_source_directory(src SRC_LIST)


find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS -pthread)
message(STATUS "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

add_executable(main ${SRC_LIST})
target_link_libraries(main ${OpenCV_LIBS})