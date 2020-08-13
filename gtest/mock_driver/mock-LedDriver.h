#pragma once
//#include "mock-LedDriver.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


// アプリケーションコードはCなのでextern "C" をしないと未解決のシンボルとなる.
//extern "C" {
//#include "LedDriver.h"
//}

class MockLedDriver {
public:
    MOCK_METHOD1(LedDriver_Create, void(uint16_t* adrs));
    MOCK_METHOD0(LedDriver_Destroy, void(void));
};
//} *MockLedDriver;

// モック化したい関数を書く  

static MockLedDriver* pMock;
void SetLedMock(MockLedDriver* p);
//void LedDriver_Create(uint16_t* address);








