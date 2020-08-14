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
	// 1��Ă΂�邱�Ƃ����ҁi���ĂԑO�ɋL�q����K�v������j
	EXPECT_CALL(mock, LedDriver_Create(testing::_))   // "_"�͒l�͔C�ӂ�OK.
		.Times(1);
	EXPECT_CALL(mock, LedDriver_Destroy())
		.Times(1);
	SetdMockLedDriver(&mock);
	InitializeLED();
	FinalizeLED();
}
