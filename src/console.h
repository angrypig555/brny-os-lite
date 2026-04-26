#pragma once

void print_console_byte(char c);
void print(const char *str);
void print_f(float val, int precision);
void printi(int val);

char read_byte();
char read_str(char *buffer, int max_len);

int str_match(const char *s1, const char *s2);