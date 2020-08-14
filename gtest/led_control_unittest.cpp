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

TEST_F(LedControlUnitTest, Initialize_Finalize_LED) {
	MockLedDriver mock;
	// 1回呼ばれることを期待（※呼ぶ前に記述する必要がある）
	EXPECT_CALL(mock, LedDriver_Create(testing::_))   // "_"は値は任意でOK.
		.Times(1);
	EXPECT_CALL(mock, LedDriver_Destroy())
		.Times(1);
	SetdMockLedDriver(&mock);
	InitializeLED();
	FinalizeLED();
}
