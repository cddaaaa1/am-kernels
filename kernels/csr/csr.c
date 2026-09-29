#include <am.h>
#include <klib.h>

#define GPIO_SEG 0x20001008u

int main(const char *args) {
    volatile uint32_t *seg = (volatile uint32_t *)GPIO_SEG;
    uint32_t mv, ma;
    asm volatile ("csrr %0, mvendorid" : "=r"(mv));
    asm volatile ("csrr %0, marchid"   : "=r"(ma));
    printf("mvendorid = %08x (%c%c%c%c)\n", mv,
           mv >> 24 & 0xff, mv >> 16 & 0xff, mv >> 8 & 0xff, mv & 0xff);
    printf("marchid   = %08x (%u)\n", ma, ma);

    uint32_t c0, c1, ch;
    asm volatile ("csrr %0, mcycle"  : "=r"(c0));
    asm volatile ("csrr %0, mcycleh" : "=r"(ch));
    for (volatile int i = 0; i < 10000; i ++);
    asm volatile ("csrr %0, mcycle"  : "=r"(c1));
    printf("mcycle = %u -> %u (delta %u), mcycleh = %u\n", c0, c1, c1 - c0, ch);

    *seg = ma;
    halt(0);
}