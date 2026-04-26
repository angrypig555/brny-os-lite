#include "init.h"
#include "pico/stdlib.h"
#include "led_handler.h"

int init() {
    printf("(init) init started");
    init();
    printf("(init) led initialized");
    led_on();
}