#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @... : The values to format and print.
 * Return: The number of characters printed or -1 on error.
 */
int _printf(const char *format, ...)
{
	char buffer[1024];
	unsigned int i = 0, j = 0, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (j >= 1023)
		{
			write(1, buffer, j);
			j = 0;
		}

		if (format[i] == '%' && format[i + 1] == '%')
		{
			buffer[j++] = '%';
			i += 2;
		}
		else if (format[i] == '%')
		{
			count += handle_format(format, &i, args, buffer, &j);
			i++;
		}
		else
		{
			buffer[j++] = format[i++];
		}
	}

	if (j > 0)
	{
		write(1, buffer, j);
	}

	va_end(args);
	return ((count == 0) ? -1 : (int)count);
}
