#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @... : The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;
	char temp;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' 
					|| format[i + 1] == 's'
				       	|| format[i + 1] == '%'))
		{
			count += handle_specifier(format[i + 1], args);
			i++;
		}
		else if (format[i] == '%' && !format[i + 1])
		{
			return (-1);
		}
		else
		{
			temp = format[i];
			count += write(1, &temp, 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
