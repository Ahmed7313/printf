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
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		count += print_int(args, buffer, j);
	/* Add more conditions here for other format specifiers */
	else
	{
		buffer[(*j)++] = format[*i];
		count += 1;
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

/**
 * is_valid_specifier - Checks if a character is a valid format specifier.
 * @c: The character to check.
 * Return: 1 if valid, 0 otherwise.
 */
int is_valid_specifier(char c)
{
	char valid_specifiers[] = "csidbuoxX";
	int i;

	for (i = 0; valid_specifiers[i]; i++)
	{
		if (c == valid_specifiers[i])
			return (1);
	}
	return (0);
}
