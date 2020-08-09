cmake_minimum_required(VERSION 3.10)

# lib方式.
include_directories(./googletest/include/)
link_directories(./)
add_executable(TestSample1 test_sample1.cpp)
target_link_libraries(TestSample1 gtestd)
target_link_libraries(TestSample1
 $<TARGET_OBJECTS:freertos>
# $<TARGET_OBJECTS:src> 
 gtestd)



#include(GoogleTest)
#add_executable(TestSample1 test_sample1.cpp)
#target_link_libraries(TestSample1 Sample1 GTest::GTest GTest::Main)
#target_link_libraries(TestSample1 gtest_main gtest)
#
#enable_testing()
#set(GTEST_ROOT "../googletest/" CACHE PATH "../googletest/googletest/")
#find_package(GTest REQUIRED)

#find_package(GTest REQUIRED)
#include(GoogleTest)

#add_executable(TestSample1 test_sample1.cpp)
#target_link_libraries(TestSample1 gtest_main pthread)
#target_link_libraries(TestSample1 Sample1 GTest::GTest GTest::Main)
#include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

# Google Testの各テストケースごとにCTestのテストを作成する
#gtest_add_tests(TARGET TestSample1)

# CTestのテストをひとつだけ作成する
#add_test(NAME AllTests COMMAND TestSample1)
