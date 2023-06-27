#include "../main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - emulates what the std printf function does
 * @format: first string to be used
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int var_1;
	int count;
	char *str;
	char c;

	count = 0;
	var_1 = 0;
	while (format[var_1] != '\0')
	{
		if (format[var_1] == '%')
		{
			switch (format[var_1 + 1])
			{
				case 's':
					str = va_arg(ap, char *);
					print_str(str);
					break;
				case '%':
					count += write(1, " ", 2);
					break;
				default:
					c = va_arg(ap, int);
					write(1, "%", 2);
					write(1, &c, 1);
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
					c = va_arg(ap, int);
					write(1, "\\", 1);
					write(1, &c, 1);
					break;
			}

		}
		count += write(1, &format[var_1], 1);
		var_1++;
	}
	return (count);
}
