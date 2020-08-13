#include "mock-LedDriver.h"

// アプリケーションコードはCなのでextern "C" をしないと未解決のシンボルとなる.
extern "C" {
#include "LedDriver.h"
}

static uint16_t address = 0;
// モック化したい関数を書く  

void LedDriver_Create(uint16_t* address) {
    pMock->LedDriver_Create(address);
}

void LedDriver_Destroy(void) { pMock->LedDriver_Destroy(); }


void SetLedMock(MockLedDriver* p) {
    pMock = p;
}

