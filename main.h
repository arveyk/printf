#ifndef MAIN_H
#define MAIN_H

#define BUF 1024

int _printf(const char *format, ...);

void print_hex(char c, int n);
void print_num(int n);
void print_bin(int n);
void print_oct(int n);

void print_str(char *str);
int print_string(char *str);
void convert_num(int base, int num);

#endif
