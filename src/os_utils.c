#include "pico/stdlib.h"
#include "led_handler.h"

void poweroff() {
    __asm volatile ("cpsid i");
    led_off();
    while (true) {
        __asm volatile ("wfi");
    }
}