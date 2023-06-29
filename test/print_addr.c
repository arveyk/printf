#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

/**
 * print_addr - prints a string
 * @str: pointer to be printed
 *
 * Return: Number of characters printed
 */
size_t print_addr(char *str)
{

	size_t i = 0;
	size_t z = 0;


	while (str)
	{
		z += write(1, &str, 1);
		i++;
	}
	return (i);
}
