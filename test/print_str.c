#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

/**
 * print_string - prints a string
 * @str: string to be printed
 *
 * Return: Number of characters printed
 */
size_t print_str(char *str)
{

	size_t i = 0;
	size_t z = 0;
/*	char c = '\n';	*/


	while (str[i] != '\0')
	{
		z += write(1, &str[i], 1);
		i++;
	}
	write(1, &z, 1);

	return (z);
}
