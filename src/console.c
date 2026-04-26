#include "pico/stdlib.h"
#include "pico/stdio.h"
#include <stdio.h>

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

char read_byte() {
    int c;
    do {
        c = getchar_timeout_us(0);
    } while (c == PICO_ERROR_TIMEOUT);
    return (char)c;
}

char* read_str(char *buffer, int max_len) {
    int index = 0;
    while (index < max_len - 1) {
        char c = read_byte();
        if (c == '\r' || c == '\n') {
            break;
        }

        if (c == 8 || c == 127) {
            if (index > 0) {
                index--;
                print("\b \b");
            }
            continue;
        }

        if (c >= 32 && c <= 126) {
            buffer[index++] = c;
            print_console_byte(c);
        }
    }
    buffer[index] = '\0';
    print("\r\n");
    return buffer;
}

int str_match(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}