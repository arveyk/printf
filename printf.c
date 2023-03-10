#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * convert - converts numbers to ocatal or hex
 * @num: number to be converted to octal or hex
 * @bass: the base to be used
 *
 * Return: pointer to converted number
 */
char *convert(unsigned int num, int bass);

/**
 * _printf - emulates the standard printf function
 * @format: contains all info needed
 *
 * Return: number of characters printed less the null byte
 */

int _printf(const char *format, ...)
{

	char *s = NULL;
	char *run;
	int x;
	int count = 0;

	va_list lizts;

	va_start(lizts, format);
	for (run = (char *)format; *run != '\0'; run++)
	{

		while (*run != '%' && *run != '\0')
		{
			write(1, &run, 1);
			run++;
			count++;
		}
		run++;
		switch (*run)
		{

			case 'c':
				x = va_arg(lizts, int);
				write(1, &x, 1);
				break;
			case 'd':
				x = va_arg(lizts, int);
				if (x < 0)
				{

					x = -x;
					putchar('-');
				}
				convert(x, 10);
				write(1, &x, 1);
				break;
			case 'o':
				x = va_arg(lizts, unsigned int);
				convert(x, 10);
				write(1, &x, 1);
				break;
			case 's':
				s = va_arg(lizts, char *);
				write(1, s, 1);
				break;
			case 'x':
				x = va_arg(lizts, unsigned int);
				convert(x, 16);
				write(1, &x, 1);
				break;
		}
		count++;
	}
	va_end(lizts);

	return (count);
}

/**
 * convert - converts numbers to ocatal or hex
 * @num: number to be converted to octal or hex
 * @bass: the base to be used
 *
 * Return: number of characters printed less the null byte
 */
char *convert(unsigned int num, int bass)
{

	static const char rep[] = "0123456789ABCDEF";
	static char buff[50];
	char *ppt;

	ppt = &buff[49];
	*ppt = '\0';

	do {
		*--ppt = rep[num % bass];
		num /= bass;
	} while (num != 0);

	return (ppt);

}
