#include "pico/stdlib.h"

void print_console_byte(char c) {
    putchar_raw(c);
}

void print(const char *str) {
    while (*str) {
        print_console_byte(*str++);
    }
}

void printi(int val) {
    if (val == 0) {
        print_console_byte('0');
        return;
    }
    if (val < 0) {
        print_console_byte('-');
        val = -val;
    }
    char buffer[11];
    int i = 0;

    while (val > 0) {
        buffer[i++] = (val % 10) + '0';
        val /= 10;
    }

    while (i > 0) {
        print_console_byte(buffer[--i]);
    }
}

void print_f(float val, int precision) {
    if (val < 0) {
        print_console_byte('-');
        val = -val;
    }
    int int_part = (int)val;
    printi(int_part);
    print_console_byte('.');
    float fract_part = val - (float)int_part;

    for (int i = 0; i < precision; i++) {
        fract_part *= 10;
        int digit = (int)fract_part;
        print_console_byte(digit + '0');
        fract_part -= digit;
    }
}
