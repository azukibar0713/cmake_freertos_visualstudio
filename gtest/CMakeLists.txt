cmake_minimum_required(VERSION 3.1)

# lib•ûŽ®.
include_directories(./include)


message("FREERTOS_INCLUDE_DIR: ${FREERTOS_INCLUDE_DIR}")

#include_directories(${FREERTOS_INCLUDE_DIR})
#include_directories($ENV{FREERTOS_INCLUDE_DIR})
#include_directories(F:/git-work/cmake_freertos_visualstudio_gtest_2/src/ F:/git-work/cmake_freertos_visualstudio_gtest_2/FreeRTOS/Source/include/ F:/git-work/cmake_freertos_visualstudio_gtest_2/FreeRTOS/Source/portable/MemMag F:/git-work/cmake_freertos_visualstudio_gtest_2/FreeRTOS/Source/portable/MSVC-MingW)


#include_directories(../src)
#include_directories(../FreeRTOS/Source/include)
#include_directories(../FreeRTOS/Source/portable/MemMang)
#include_directories(../FreeRTOS/Source/portable/MSVC-MingW)

#include_directories(../src ../FreeRTOS/Source/include ../FreeRTOS/Source/portable/MemMang ../FreeRTOS/Source/portable/MSVC-MingW)

include_directories($ENV{FREERTOS_CONFIG_DIR})
include_directories($ENV{FREERTOS_INCLUDE_DIR})
include_directories($ENV{FREERTOS_MEMMAG_DIR})
include_directories($ENV{FREERTOS_PORTABLE_DIR})



link_directories(./lib)
add_executable(TestSample1 test_sample1.cpp test_freertos.c)
#add_executable(TestSample1 ${GTEST_SRC_FILES})
#target_link_libraries(TestSample1 gtestd)
#target_link_libraries(TestSample1
# $<TARGET_OBJECTS:freertos>
# gtestd)

target_link_libraries(TestSample1
 $<TARGET_OBJECTS:freertos>)
target_link_libraries(TestSample1 debug gtestd)
target_link_libraries(TestSample1 optimized gtest)



