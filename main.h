#ifndef MAIN_H
#define MAIN_H

#define BUF 1024
#include <stddef.h>

int _printf(const char *format, ...);

void print_hex(char c, int n);
void print_num(int n);
void print_bin(int n);
void print_oct(int n);

size_t print_str(const char *const str);
int print_string(const char *const str);
void convert_num(int base, int num);

#endif
