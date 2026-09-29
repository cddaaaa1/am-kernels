#include <am.h>
#include <klib-macros.h>

#define GPIO_BASE 0x20001000u
#define GPIO_LED  (GPIO_BASE + 0x0)
#define GPIO_SW   (GPIO_BASE + 0x4)

// 密码：拨码开关 SW15..SW0 摆成这个值即可解锁（不能为 0）
#define PASSWORD 0x1234u

int main(const char *args) {
  volatile uint32_t *led = (volatile uint32_t *)GPIO_LED;
  volatile uint32_t *sw  = (volatile uint32_t *)GPIO_SW;

  *led = 0;

  while ((*sw & 0xffffu) != PASSWORD) ;   // 一直查询拨码开关，直到与密码一致
  *led = 0xffff;                          // 解锁：16 个 LED 全亮
  while (1) ;
  return 0;
}
