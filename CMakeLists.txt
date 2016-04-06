cmake_minimum_required(VERSION 3.3)
project(CPViewer)

find_package(VTK REQUIRED)
find_package(Qt5Widgets REQUIRED QUIET)

include(${VTK_USE_FILE})
file(GLOB HEADER_FILES *.h)
file(GLOB SOURCE_FILES *.cpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(CPViewer ${HEADER_FILES} ${SOURCE_FILES} EasyImageSlice.cpp EasyImageSlice.h)
qt5_use_modules(CPViewer Core Gui)
target_link_libraries(CPViewer ${VTK_LIBRARIES})