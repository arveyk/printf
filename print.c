#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * _print - emulates what the std printf function does
 * @format: first string to be used
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{

	va_list ap;
	int var_1;
	int count;
	int i;
	int b;
	char *str = NULL;
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
					count += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(ap, char *);
					count += print_string(str);
					break;
				case '%':
					count += write(1, "%", 2);
					break;
				case 'd':
					i = va_arg(ap, int);
					print_num(i);
					break;
				case 'i':
					i = va_arg(ap, int);
					print_num(i);
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
					print_hex('x', b);
					break;
				case 'X':
					b = va_arg(ap, int);
					print_hex('X', b);
					break;
/*				case '':
				case 'p':
					print in hex
				case '+':
					i = va_arg(ap, int);
					if (i < 0)
					print_num;
					else 
					{
						write(1, "+", 2);
						print_num(i);
					}

				case ' ':
				case '#':
					i = va_arg(ap, int);
					print_num(i);
				case 'u':
					print unisigned
					
				case '':	*/
				default:
					write(1, "unknown characters", 19);
					break;
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
		
		write(1, &format[var_1], 1);
		}
		var_1++;
	}
	return (count);
}
