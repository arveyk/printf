#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
	int s;
	int rem, q;
	char flip = '0';
	char *con_arr;
	size_t give = 0;

	r = 0;
	con_arr = malloc(sizeof(char) * 64);
	if (!con_arr)
		return (0);
	if (n < 0)
	{
		write(1, "-", 2);
		n *= -1;
	}
	s = r = 64;
	while (--r > 0)
		con_arr[r] = '0';
	r = s;
	while (--r > 0)
	{
		rem = n % base;
		q = n / base;
		con_arr[r] = rem + '0';
		n = q;
	}
	r = 0;
	while (r < s)
	{
		if (con_arr[r] - '0' > 0)
			flip = '1';
		if (flip == '1')
			give +=	write(1, &(con_arr[r]), 1);
		r++;
	}
	--give;
	free(con_arr);
	return (give);
}
