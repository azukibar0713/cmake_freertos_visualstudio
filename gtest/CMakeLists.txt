cmake_minimum_required(VERSION 3.1)

# lib•ûŽ®.
include_directories(./include)
#include_directories(../src)
#include_directories(../FreeRTOS/Source/include)
#include_directories(../FreeRTOS/Source/portable/MemMang)
#include_directories(../FreeRTOS/Source/portable/MSVC-MingW)

include_directories($ENV{FREERTOS_CONFIG_DIR})
include_directories($ENV{FREERTOS_INCLUDE_DIR})
include_directories($ENV{FREERTOS_MEMMAG_DIR})
include_directories($ENV{FREERTOS_PORTABLE_DIR})

link_directories(./lib)
add_executable(TestSample1 test_sample1.cpp test_freertos.c freertos_unittest.cpp)

target_link_libraries(TestSample1
 $<TARGET_OBJECTS:freertos>)
target_link_libraries(TestSample1 debug gtestd)
target_link_libraries(TestSample1 optimized gtest)

