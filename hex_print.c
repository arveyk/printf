#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_hex - prints a numbers hex equivalent
 * @n: the number to be convierted and printed
 * @c: indicates the case of letters in the printed adder
 *
 * Return: Nothing yet
 */
size_t print_hex(char c, int n)
{

	int r;
	size_t give;
	int rem, q;
	char flip = '0';
	char con_arr[32];

	r = 0;
	give = 0;
	while (r < 32)
	{
		con_arr[r] = 0;
		r++;
	}
	while (--r > 0)
	{
		rem = n % 16;
		q = n / 16;
		if (rem > 9)
		{
			if (c == 'x')
				con_arr[r] = (rem % 10) + 'a';
			else if (c == 'X')
				con_arr[r] = (rem % 10) + 'A';
		}
		else
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
