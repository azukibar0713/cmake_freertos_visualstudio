cmake_minimum_required(VERSION 3.1)
#project(gtest_project C CXX)

include_directories(./include)
include_directories(../user_app/include)
#include_directories(../FreeRTOS/Source/include)
#include_directories(../FreeRTOS/Source/portable/MemMang)
#include_directories(../FreeRTOS/Source/portable/MSVC-MingW)

include_directories($ENV{FREERTOS_CONFIG_DIR})
include_directories($ENV{FREERTOS_INCLUDE_DIR})
include_directories($ENV{FREERTOS_MEMMAG_DIR})
include_directories($ENV{FREERTOS_PORTABLE_DIR})

file(GLOB GTEST_SOURCE_FILES ./*.[ch] ./*.cpp ${DRIVER_FILES})
message(${GTEST_SOURCE_FILES})

link_directories(./lib)

add_executable(GTEST ${GTEST_SOURCE_FILES})
#add_library(FREERTOS_OBJETCS OBJECT ${FREERTOS_SOURCE_FILES})

target_link_libraries(GTEST
  $<TARGET_OBJECTS:FREERTOS>
  $<TARGET_OBJECTS:USER_APP>
 )

target_link_libraries(GTEST debug gtestd)
target_link_libraries(GTEST optimized gtest)
target_link_libraries(GTEST debug gmockd)
target_link_libraries(GTEST optimized gmock)

