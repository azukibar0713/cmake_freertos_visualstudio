#include "mock-LedDriver.h"
// -----------------------
// アプリケーションコードはCなのでextern "C" をしないと未解決のシンボルとなる.
// -----------------------
extern "C" {
#include "LedDriver.h"
}

static MockLedDriver* pMock;
void SetdMockLedDriver(MockLedDriver* p) {
    pMock = p;
}

// -----------------------
// ここにMockしたいAPIを書く
//   - アプリケーションコードからアクセスされたらMockのAPIに繋げる.
// -----------------------
void LedDriver_Create(uint16_t* address) {
    pMock->LedDriver_Create(0);
}

void LedDriver_Destroy(void) {
    pMock->LedDriver_Destroy();
}
