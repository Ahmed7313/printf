#include "main.h"
#include <stdarg.h>
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
		if (format[i] == '%' && format[i + 1] == '\0') /* Add this condition */
		{
			return (-1);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			count++;
			i += 2;
			continue;
		}
		else if (format[i] == '%' &&
			 (format[i + 1] == 'c' || format[i + 1] == 's'))
		{
			i++;
			count += (format[i] == 'c') ? print_char(args) : print_str(args);
		}
		else if (format[i] == '%' &&
			 format[i + 1] != 'c' && format[i + 1] != 's' &&
			 format[i + 1] != '%')
		{
			write(1, &format[i], 2);
			count += 2;
			i += 2;
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
