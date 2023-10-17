#include "main.h"
#include <unistd.h>

/**
 * print_char - Writes a character to stdout
 * @args: The character
 * Return: 1 on success
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_str - Writes a string to stdout
 * @args: The string
 * Return: Number of chars written
 */
int print_str(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	str = str == NULL ? "(null)" : str;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
