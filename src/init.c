#include "init.h"
#include "pico/stdlib.h"
#include "led_handler.h"
#include "console.h"
#include "sensors.h"
#include "bsh.h"

int init() {
    print("(init) init started\n");
    print("(init) performing self test\n");
    print("(init) you should see the number 1 below\n");
    printi(1);
    print("\n(init) you should see the float 1.23 below\n");
    print_f(1.23f, 2);
    print("\n(init) self test done\n");
    init_led();
    print("(init) led initialized\n");
    led_on();
    vsys_init();
    print("(init) voltage sensor initialized\n");
    float voltage_start = vsys_voltage();
    if (voltage_start <= 4.00f) {
        print("(fail) voltage under acceptable level, shutting down to prevent damage\n");
        print_f(voltage_start, 2);
        return -1;
    }
    print("(init) finished, launching user program\n");
    shell();
    return 0;
}