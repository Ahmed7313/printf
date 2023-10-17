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

	if (format[*i + 1] == 'c')
		count += print_char(args);
	else if (format[*i + 1] == 's')
		count += print_str(args);
	else if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
		count += print_intger(args);
	else if (format[*i + 1] == 'b')
		count += print_Binary(args);
	else if (format[*i + 1] == 'u')
		count += print_unsignedIntger(args);
	else if (format[*i + 1] == 'o')
		count += print_unsignedOctal(args);
	else if (format[*i + 1] == 'x')
		count += print_unsignedHex(args);
	else
	{
		write(1, &format[*i], 2);
		count += 2;
	}
	(*i)++;
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
