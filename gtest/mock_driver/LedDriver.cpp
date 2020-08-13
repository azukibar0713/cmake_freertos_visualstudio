#include "gtest/gtest.h"
#include "gmock/gmock.h"
extern "C" {
#include "LedDriver.h"
}

// ���b�N�N���X�̐錾  
class TestMock {
public:
    // MOCK_METHODn(�֐���, �߂�l�̌^(����1, ����2, ...))  
    // n�͈����̐�  
    MOCK_METHOD1(LedDriver_Create, void(uint16_t* adrs));  //void LedDriver_Create(uint16_t* ledsAddress);
} *testMock;

static uint16_t address = 0;
// ���b�N���������֐�������  
void LedDriver_Create(uint16_t* address) {
    testMock->LedDriver_Create(address);
}

