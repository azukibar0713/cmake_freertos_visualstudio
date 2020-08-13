#pragma once
//#include "mock-LedDriver.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


// �A�v���P�[�V�����R�[�h��C�Ȃ̂�extern "C" �����Ȃ��Ɩ������̃V���{���ƂȂ�.
//extern "C" {
//#include "LedDriver.h"
//}

class MockLedDriver {
public:
    MOCK_METHOD1(LedDriver_Create, void(uint16_t* adrs));
    MOCK_METHOD0(LedDriver_Destroy, void(void));
};
//} *MockLedDriver;

// ���b�N���������֐�������  

static MockLedDriver* pMock;
void SetLedMock(MockLedDriver* p);
//void LedDriver_Create(uint16_t* address);








