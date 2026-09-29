#include <am.h>
#include <klib-macros.h>

#define GPIO_SEG 0x20001008u

// 报名号（8 位十六进制）；例：123456789 = 0x075BCD15
#define REGNO 0x12345678u

int main(const char *args) {
  volatile uint32_t *seg = (volatile uint32_t *)GPIO_SEG;

  *seg = REGNO;
  while (1) ;
  return 0;
}
