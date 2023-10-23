#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, count = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'd' ||
			format[i + 1] == 'i' || format[i + 1] == 'c' ||
			format[i + 1] == 's' || format[i + 1] == '%'))
		{
			count += handle_specifier(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
