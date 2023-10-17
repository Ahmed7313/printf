#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

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

/**
 * handle_format - Handles formatted characters.
 * @format: The format string.
 * @i: The current index.
 * @args: The argument list.
 * Return: The count of characters printed.
 */
unsigned int handle_format(const char *format, unsigned int *i, va_list args)
{
	unsigned int count = 0;

	(*i)++;
	if (format[*i] == 'c')
		count += print_char(args);
	else if (format[*i] == 's')
		count += print_str(args);
	else
	{
		write(1, &format[*i - 1], 2);
		count += 2;
	}
	return (count);
}

/**
 * handle_unformat - Handles unformatted characters.
 * @c: The character to print.
 * Return: Always 1.
 */
unsigned int handle_unformat(char c)
{
	write(1, &c, 1);
	return (1);
}
