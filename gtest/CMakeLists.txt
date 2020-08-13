cmake_minimum_required(VERSION 3.1)

include_directories(./include)
include_directories(../user_app/include)
#include_directories(../FreeRTOS/Source/include)
#include_directories(../FreeRTOS/Source/portable/MemMang)
#include_directories(../FreeRTOS/Source/portable/MSVC-MingW)

include_directories($ENV{FREERTOS_CONFIG_DIR})
include_directories($ENV{FREERTOS_INCLUDE_DIR})
include_directories($ENV{FREERTOS_MEMMAG_DIR})
include_directories($ENV{FREERTOS_PORTABLE_DIR})

file(GLOB GTEST_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.[ch] ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ../user_app/driver/*.c) #  ${CMAKE_CURRENT_SOURCE_DIR}/mock_driver/*.cpp)

link_directories(./lib)

add_executable(GTEST ${GTEST_SOURCE_FILES})
#add_executable(GTEST test_sample1.cpp test_freertos.c freertos_unittest.cpp)

target_link_libraries(GTEST
 $<TARGET_OBJECTS:FREERTOS_OBJETCS>)

target_link_libraries(GTEST debug gtestd)
target_link_libraries(GTEST optimized gtest)
target_link_libraries(GTEST debug gmockd)
target_link_libraries(GTEST optimized gmock)

