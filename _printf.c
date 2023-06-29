#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

size_t print_str(const char *const str);

/**
 * _printf - emulates what the std printf function does
 * @format: first string to be used
 *
 * Return: Number of characters printed
 */
int _printf(const char * const format, ...)
{

	va_list ap;
	int var_1;
	int count;
	char *str = NULL;
/*	char *addr = NULL;	*/
	char c;
	int b;
	int i;
	int e;
	float d;

	count = 0;
	var_1 = 0;
	while (format[var_1] != '\0')
	{
		if (format[var_1] == '%')
		{
			var_1++;
			switch (format[var_1])
			{
				case 'i':
					i = va_arg(ap, int);
					count += print_num(i);
					break;
				case 'c':
					c = va_arg(ap, int);
					count += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(ap, char *);
					count += print_str(str);
					break;
				case 'f':
					d = va_arg(ap, double);
					count += print_num(d);
					break;
				case 'd':
					e = va_arg(ap, int);
					count += print_num(e);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				case 'b':
					b = va_arg(ap, int);
					count += convert_num(2, b);
					break;
				case 'o':
					b = va_arg(ap, int);
					count += convert_num(8, b);
					break;
				case 'x':
					b = va_arg(ap, int);
					count += print_hex('x', b);
					break;
				case 'X':
					b = va_arg(ap, int);
					count += print_hex('X', b);
					break;
/*
 *				case 'p':
					addr = va_arg(ap, char *);
					print_addr(addr);
					break;
					*/
				default:
					write(1, "%", 1);
					write(1, &format[var_1], 1);
					count += 2;
			}
		}

		else if (format[var_1] == '\\')
		{
			switch (format[var_1 + 1])
			{
				case 't':
					count += write(1, "\t", 2);
					break;
				case 'n':
					count += write(1, "\n", 2);
					break;
				case 'r':
					count += write(1, "\r", 2);
					break;
				case 'a':
					count += write(1, "\a", 2);
					break;
				case 'b':
					count += write(1, "\b", 2);
					break;
				case 'f':
					count += write(1, "\f", 2);
					break;
				case 'v':
					count += write(1, "\v", 2);
					break;
				default:
					c = va_arg(ap, int);
					count += write(1, &c, 1);
					break;
			}

		}
		else
			count += write(1, &format[var_1], 1);
		var_1++;
	}
	return (count);
}

/**
 * print_str - prints a string
 * @str: string to be printed
 *
 * Return: Number of characters printed
 */
size_t print_str(const char *const str)
{

	size_t i = 0;
	size_t z = 0;
	char *ptr;

	if (str == NULL)
		return (0);
	ptr = (char *)str;
	while (ptr[i] != '\0')
		z += write(1, &ptr[i], 1);
	return (z);
}
