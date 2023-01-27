cmake_minimum_required(VERSION 3.0.0)
project(vidDisplay)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(vidDisplay vidDisplay.cpp vidDisplay.h filter.cpp)

target_link_libraries(vidDisplay ${OpenCV_LIBS})

