#include <thread>
#include "gtest/gtest.h"
extern "C"
{
#include "test_freertos.h"
}

class FreeRtosUnitTest : public testing::Test {
protected:
	void SetUp() override {
		std::thread th_freertos(drive_freertos);
		th_freertos.detach();
	}
	void TearDown() override {
	}
};
//std::thread th_freertos;


#if 0
TEST_F(FreeRtosUnitTest, Sample1) {
	_sleep(5);
	EXPECT_EQ(1, 1);
}
#endif
