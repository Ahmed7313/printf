#include "main.h"
#include <stddef.h>
#include <unistd.h>

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
		if (format[i] == '%')
		{
			handle_percent(format, &i, args, &count);
			continue;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);

	return ((count == 0) ? -1 : (int)count);
}

/**
 * handle_percent - Handles percent directives in a format string.
 * @format: The format string.
 * @i: Pointer to index where '%' was found.
 * @args: List of arguments.
 * @count: Pointer to character count.
 */
void handle_percent(const char *format, unsigned int *i,
			   va_list args, unsigned int *count)
{
	if (format[*i + 1] == '%')
	{
		write(1, "%", 1);
		(*count)++;
		*i += 2;
	}
	else if (format[*i + 1] == 'c' || format[*i + 1] == 's')
	{
		(*i)++;
		*count += (format[*i] == 'c') ? print_char(args) : print_str(args);
	}
	else
	{
		write(1, &format[*i], 2);
		*count += 2;
		*i += 2;
	}
}
