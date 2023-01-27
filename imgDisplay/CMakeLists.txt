cmake_minimum_required(VERSION 3.0.0)
project(imgDisplay)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(imgDisplay imgDisplay.cpp)

target_link_libraries(imgDisplay ${OpenCV_LIBS})

include(CTest)
include(CPack)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_BUILD_TYPE Debug)