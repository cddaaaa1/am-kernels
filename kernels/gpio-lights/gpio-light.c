#include <am.h>
#include <klib-macros.h>

static void delay(void) {
  for (volatile int i = 0; i < 1000; i++) ;
}

int main(const char *args) {
  volatile uint32_t *led = (volatile uint32_t *)0x20001000u;
  for (uint32_t v = 1; ; v <<= 1) {
    if (v == 0x10000) v = 1;   // 移完 16 位回到第 0 位
    *led = v;
    delay();
  }
  return 0;
}
