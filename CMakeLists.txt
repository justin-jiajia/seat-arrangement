cmake_minimum_required(VERSION 3.0.0)
project(seat-arrangement VERSION 0.1.0)

include(CTest)
enable_testing()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(OpenCV 4.6.0 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(seat-arrangement main.cpp)

target_link_libraries(seat-arrangement ${OpenCV_LIBS})
