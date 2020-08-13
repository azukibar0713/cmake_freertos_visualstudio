#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockLedDriver {
public:
    MOCK_METHOD1(LedDriver_Create, void(uint16_t* adrs));
    MOCK_METHOD0(LedDriver_Destroy, void(void));
};

void SetdMockLedDriver(MockLedDriver* p);
