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
	unsigned int i = 0, count = 0;
	va_list args;

	if (!format || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
				count += handle_format(format, &i, args);
			else
			{
				count += handle_unformat('%');
				count += handle_unformat(format[i]);
			}
		}
		else
			count += handle_unformat(format[i]);
		i++;
	}
	va_end(args);
	return ((count == 0) ? -1 : (int)count);
}
