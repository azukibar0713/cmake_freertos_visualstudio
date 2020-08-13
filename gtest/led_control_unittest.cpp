#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mock_driver/mock-LedDriver.h"
extern "C"
{
#include "led_control.h"
}

class LedControlUnitTest : public testing::Test {
protected:
	void SetUp() override {
	}
	void TearDown() override {
	}
};

TEST_F(LedControlUnitTest, InitializeLED) {
	MockLedDriver mock;
	// 値は何でも良いので1回呼ばれることを期待（※呼ぶ前に記述する必要がある）
	EXPECT_CALL(mock, LedDriver_Create(testing::_)) 
		.Times(1);
	SetdMockLedDriver(&mock);
	InitializeLED();
}

TEST_F(LedControlUnitTest, FinalizeLED) {
	MockLedDriver mock;
	// 1回呼ばれることを期待（※呼ぶ前に記述する必要がある）
	EXPECT_CALL(mock, LedDriver_Destroy())
		.Times(1);
	SetdMockLedDriver(&mock);
	FinalizeLED();
}
