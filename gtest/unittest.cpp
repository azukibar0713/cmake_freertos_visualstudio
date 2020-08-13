#include <thread>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mock_driver/mock-LedDriver.h"
extern "C"
{
#include "test_freertos.h"
#include "led_control.h"
}

using ::testing::AtLeast;
using ::testing::Pointee;



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

TEST_F(FreeRtosUnitTest, Sample1) {
	MockLedDriver mock;
	EXPECT_CALL(mock, LedDriver_Create(testing::_))
		.Times(1);
	SetLedMock(&mock);
	InitializeLED();
}

TEST_F(FreeRtosUnitTest, Sample2) {
	MockLedDriver mock;
	EXPECT_CALL(mock, LedDriver_Destroy())
		.Times(1);
	SetLedMock(&mock);
	FinalizeLED();

}


#if 0
TEST_F(FreeRtosUnitTest, Sample1) {
	_sleep(5);
	EXPECT_EQ(1, 1);
}
#endif

