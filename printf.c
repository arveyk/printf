#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - emulates the standard printf function
 * @ format: contains all info needed
 *
 * Return: number of characters printed less the null byte
 */
char *convert(unsigned int num, int bass);

int _printf(const char *format, ...)
{

	char *s = NULL;
	char *run;
	int x;

	va_list lizts;

	va_start(lizts, format);
	for (run = (char *)format; *run != '\0'; run++)
	{

		while (*run != '%' && *run != '\0')
		{
			write(1, &run, 1);
			run++;
		}
		run++;
		switch (*run)
		{

			case 'c': x = va_arg(lizts, int);
				  write(1, &x, 1);
				  break;
			case 'd': x = va_arg(lizts, int);
				  if (x < 0)
				  {

					x = -x;
					putchar('-');
				  }
				  convert(x, 10);
				  write(1, &x, 1);
				  break;
			case 'o': x = va_arg(lizts, unsigned int);
				  convert(x, 10);
				  write(1, &x, 1);
				  break;
			case 's': s = va_arg(lizts, char *);
				  write(1, s, 1);
				  break;
			case 'x': x = va_arg(lizts, unsigned int);
				  convert(x, 16);
				  write(1, &x, 1);
				  break;
		}
	}
	va_end(lizts);

	return (x);
}

char *convert(unsigned int num, int bass)
{

	static char rep[] = "0123456789ABCDEF";
	static char buff[50];
	char *ppt;

	ppt = &buff[49];
	*ppt = '\0';

	do
	{

		*--ppt = rep[num%bass];
		num /= bass;
	}while(num != 0);

	return (ppt);

}
