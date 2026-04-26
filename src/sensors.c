#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

void vsys_init() {
    adc_init();
    adc_gpio_init(29);
}

float vsys_voltage() {
    adc_select_input(3);
    uint16_t raw = adc_read();
    const float conv_factor = 3.3f / (1 << 12);
    return raw * conv_factor * 3;
}