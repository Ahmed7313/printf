#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * handle_format - Handles format specifiers and returns character count.
 * @format: The format string.
 * @i: Pointer to index where '%' was found.
 * @args: List of arguments.
 * Return: Number of printed characters.
 */
unsigned int handle_format(const char *format, unsigned int *i, va_list args)
{
	unsigned int count = 0;

	if (format[*i + 1] == '%')
	{
		write(1, "%", 1);
		count++;
		*i += 2;
	}
	else if (format[*i + 1] == 'c' || format[*i + 1] == 's')
	{
		(*i)++;
		count += (format[*i] == 'c') ? print_char(args) : print_str(args);
	}
	else
	{
		write(1, &format[*i], 2);
		count += 2;
		*i += 2;
	}
	return (count);
}

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @... : The values to format and print.
 * Return: The number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%')
			count += handle_format(format, &i, args);
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return ((count == 0) ? -1 : (int)count);
}
