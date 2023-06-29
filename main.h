#ifndef MAIN_H
#define MAIN_H

#define BUF 1024
#include <stddef.h>

int _printf(const char *format, ...);

size_t print_hex(char c, int n);
size_t print_num(int n);
size_t print_bin(int n);
size_t print_oct(int n);

size_t print_str(const char *str);
size_t print_string(const char *str);
size_t convert_num(int base, int num);

size_t print_addr(char *str);

#endif
