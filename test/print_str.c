#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "../main.h"

/**
 * print_string - prints a string
 * @str: string to be printed
 *
 * Return: Number of characters printed
 */
size_t print_str(const char *const str)
{

	size_t i = 0;
	size_t z = 0;
	char *ptr = (char *)str;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		z += write(1, &ptr[i], 1);
	}	
	return (z);
}
