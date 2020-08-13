#include "mock-LedDriver.h"
// -----------------------
// �A�v���P�[�V�����R�[�h��C�Ȃ̂�extern "C" �����Ȃ��Ɩ������̃V���{���ƂȂ�.
// -----------------------
extern "C" {
#include "LedDriver.h"
}

static MockLedDriver* pMock;
void SetdMockLedDriver(MockLedDriver* p) {
    pMock = p;
}

// -----------------------
// ������Mock������API������
//   - �A�v���P�[�V�����R�[�h����A�N�Z�X���ꂽ��Mock��API�Ɍq����.
// -----------------------
void LedDriver_Create(uint16_t* address) {
    pMock->LedDriver_Create(0);
}

void LedDriver_Destroy(void) {
    pMock->LedDriver_Destroy();
}
