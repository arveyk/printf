#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_num - converts a number to different base
 * @n: the number to be printed
 *
 * Return: returns number of characters printed
 */
size_t print_num(int n)
{

	int r;
	unsigned int give;
	int rem, q;
	char flip = '0';
	int con_arr[32];

	r = 0;
	give = 0;
	while (r < 32)
	{
		con_arr[r] = 0;
		r++;
	}
	while (--r > 0)
	{
		rem = n % 10;
		q = n / 10;
		con_arr[r] = rem + '0';
		n = q;
	}
	while (r++ < 32)
	{
		if (con_arr[r] - '0' > 0)
			flip = '1';
		if (flip == '1')
			give += write(1, &(con_arr[r]), 1);
	}
	return (give);
}
