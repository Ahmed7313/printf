#include "main.h"
#include <stdarg.h>

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
<<<<<<< HEAD
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'))
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_str(args);
		}
		else if (format[i] == '%' && (format[i + 1] != 'c' && format[i + 1] != 's'))
		{
			write(1, "invalid", 7);
			return (-1);
=======
		if (format[i] == '%' &&
		    (format[i + 1] == 'c' || format[i + 1] == 's' ||
		     format[i + 1] == '%' || format[i + 1] == 'd' ||
			 format[i + 1] == 'i' || format[i + 1] == 'b'))
		{
			switch (format[i + 1])
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += print_percent(args);
					break;
				case 'i':
				case 'd':
					count += print_intger(args);
					break;
				case 'b':
					count += print_Binary(args);
					break;
				default:
					return (-1);
			}
			i += 2;
>>>>>>> a295d327ad74284d6aceb8398601c907616b26da
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);

	if (count == 0)
		return (-1);

	return (count);
}
