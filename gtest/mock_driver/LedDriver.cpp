#include "gtest/gtest.h"
#include "gmock/gmock.h"
extern "C" {
#include "LedDriver.h"
}

// モッククラスの宣言  
class TestMock {
public:
    // MOCK_METHODn(関数名, 戻り値の型(引数1, 引数2, ...))  
    // nは引数の数  
    MOCK_METHOD1(LedDriver_Create, void(uint16_t* adrs));  //void LedDriver_Create(uint16_t* ledsAddress);
} *testMock;

static uint16_t address = 0;
// モック化したい関数を書く  
void LedDriver_Create(uint16_t* address) {
    testMock->LedDriver_Create(address);
}

