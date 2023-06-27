#include "../main.h"
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
	char *str;
	float d;
	char c;

	count = 0;
	var_1 = 0;
	while (format[var_1] != '\0')
	{
		if (format[var_1] == '%')
		{
			switch (format[var_1 + 1])
			{
				case 'c':
					c = va_arg(ap, int);
					write(1, &c, 1);
					break;
				case 's':
					str = va_arg(ap, char *);
					count += print_str(str);
					c = va_arg(ap, int);
					break;
				case 'f':
					d = va_arg(ap, double);
					print_num(d);
					break;
				case 'd':
					i = va_arg(ap, int);
					count += print_num(i);
					break;
				case '%':
					count += write(1, '%', 2);
					break;
				case 'b':
					b = va_arg(ap, int);
					convert_num(2, b);
					break;
				case 'o':
					b = va_arg(ap, int);
					convert_num(8, b);
					break;
				case 'x':
					b = va_arg(ap, int);
					print_hex(x, b);
					break;
				case 'X':
					b = va_arg(ap, int);
					print_hex(x, b);
					break;
				case '':
				default:
					write(1, "%", 2);
					write(1, &c, 1);
			}
		}

		if (format[var_1] == '\\')
		{
			switch (format[var_1 + 1])
			{
				case 't':
					write(1, "\t", 2);
					break;
				case 'n':
					write(1, "\n", 2);
					break;
				case 'r':
					write(1, "\r", 2);
					break;
				case 'a':
					write(1, "\a", 2);
					break;
				case 'b':
					write(1, "\b", 2);
					break;
				case 'f':
					write(1, "\f", 2);
					break;
				case 'v':
					write(1, "\v", 2);
					break;
				default:
					write(1, "Error", 6);
					break;
			}

		}
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
