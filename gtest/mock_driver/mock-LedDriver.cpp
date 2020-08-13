#include "mock-LedDriver.h"

// �A�v���P�[�V�����R�[�h��C�Ȃ̂�extern "C" �����Ȃ��Ɩ������̃V���{���ƂȂ�.
extern "C" {
#include "LedDriver.h"
}

static uint16_t address = 0;
// ���b�N���������֐�������  

void LedDriver_Create(uint16_t* address) {
    pMock->LedDriver_Create(address);
}

void LedDriver_Destroy(void) { pMock->LedDriver_Destroy(); }


void SetLedMock(MockLedDriver* p) {
    pMock = p;
}

