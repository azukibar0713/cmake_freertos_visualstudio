#include "test_sample1.h"

#include <cstdio>
#include <thread>
#include <cstdio>
#include <cstdint>
#include "gtest/gtest.h"
#include "freertos_unittest.cpp"


TEST(FactorialTest, HandlesZeroInput) {
    EXPECT_EQ(1, 1);
}

TEST_F(FreeRtosUnitTest, Sample1) {
    _sleep(100);
    EXPECT_EQ(1, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret =  RUN_ALL_TESTS();
    return ret;
}



