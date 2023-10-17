#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * print_char - Writes a character to buffer
 * @args: The character
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: 1 on success
 */
int print_char(va_list args, char *buffer, unsigned int *j)
{
	char c = va_arg(args, int);

	buffer[(*j)++] = c;
	return (1);
}

/**
 * print_str - Writes a string to buffer
 * @args: The string
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: Number of chars written
 */
int print_str(va_list args, char *buffer, unsigned int *j)
{
	int count = 0;
	char *str = va_arg(args, char *);

	str = str == NULL ? "(null)" : str;
	while (*str)
	{
		buffer[(*j)++] = *str++;
		count++;
	}
	return (count);
}

/**
 * handle_format - Handles formatted characters.
 * @format: The format string.
 * @i: The current index.
 * @args: The argument list.
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: The count of characters printed.
 */
unsigned int handle_format(const char *format, unsigned int *i,
va_list args, char *buffer, unsigned int *j)
{
	unsigned int count = 0;

	if (format[*i + 1] == 'c')
		count += print_char(args, buffer, j);
	else if (format[*i + 1] == 's')
		count += print_str(args, buffer, j);
	else if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
		count += print_intger(args, buffer, j);
	else if (format[*i + 1] == 'b')
		count += print_Binary(args, buffer, j);
	else if (format[*i + 1] == 'u')
		count += print_unsignedIntger(args, buffer, j);
	else if (format[*i + 1] == 'o')
		count += print_unsignedOct(args, buffer, j);
	else if (format[*i + 1] == 'x' || format[*i + 1] == 'X')
		count += print_unsignedHex(args, buffer, j, format[*i + 1]);
	else if (format[*i + 1] == 'R')
		count += print_rot13(args, buffer, j);
	else
	{
		buffer[(*j)++] = format[*i];
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
