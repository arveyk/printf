#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_hex - prints a numbers hex equivalent
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
	while(--r > 0)
	{
		rem = n % 16;
		q = n / 16;
		if (rem > 9)
		{
			if (c == 'x')
			{
				switch (rem)
				{
					case 10:
						con_arr[r] = 'a';
						break;
					case 11:
						con_arr[r] = 'b';
						break;
					case 12:
						con_arr[r] = 'c';
						break;
					case 13:
						con_arr[r] = 'd';
						break;
					case 14:
						con_arr[r] = 'e';
						break;
					case 15:
						con_arr[r] = 'f';
						break;
				}
		       }
			if (c == 'X')
			{
				switch (rem)
				{
					case 10:
						con_arr[r] = 'A';
						break;
					case 11:
						con_arr[r] = 'B';
						break;
					case 12:
						con_arr[r] = 'C';
						break;
					case 13:
						con_arr[r] = 'D';
						break;
					case 14:
						con_arr[r] = 'E';
						break;
					case 15:
						con_arr[r] = 'F';
						break;
				}
		       }

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
