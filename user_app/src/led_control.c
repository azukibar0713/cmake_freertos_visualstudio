#include "led_control.h"
#include "LedDriver.h"

static uint16_t adrs = 0;
void InitializeLED() {
    LedDriver_Create(1);
}
void FinalizeLED() {
    LedDriver_Destroy();
}
