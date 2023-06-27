#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_hex - prints a numbers hex equivalent
 * @c: indicator
 * @n: the number to be convierted and printed
 *
 * Return: Nothing yet
 */
size_t print_hex(char c, int n)
{

	int r;
	int rem, q;
	char flip = '0';
	char con_arr[32];
	int give = 0;

	r = 0;
	while (r < 32)
	{
		con_arr[r] = 0;
		r++;
	}
	while (--r > 0)
	{
		rem = n % 16;
		q = n / 16;
		if (c == 'x')
		{
			if (rem == 10)
				con_arr[r] = 'a';
			else if(rem == 10)
				con_arr[r] = 'b';
			else if (rem == 10)
				con_arr[r] = 'c';
			else if (rem == 10)
				con_arr[r] = 'd';
			else if (rem == 10)
				con_arr[r] = 'e';
			else
				con_arr[r] = 'f';
		}
		con_arr[r] = rem + '0';
		n = q;
	}
	while (r++ < 32)
	{
		if (con_arr[r] != '0')
			flip = '1';
		if (flip == '1')
			give += write(1, &(con_arr[r]), 1);
	}
	return (give);
}
