#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * convert_num - converts a number to different base
 * @n: the number to be convierted
 * @base: basis of coversion
 *
 * Return: returns the number of characters printed
 */
size_t convert_num(int base, int n)
{

	int r;
	int rem, q;
	char flip = '0';
	int con_arr[32];
	int give = 0;

	r = 0;
	while (r < 32)
	{
		con_arr[r] = 0;
		r++;
	}
	while (--r > 0)
	{
		rem = n % base;
		q = n / base;
		con_arr[r] = rem + '0';
		n = q;
	}
	while (r++ < 32)
	{
		if (con_arr[r] != '0')
			flip = '1';
		if (flip == '1')
			give +=	write(1, &(con_arr[r]), 1);
	}
	return (give);
}
