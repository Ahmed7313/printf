#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * handle_d - Handles the 'd' specifier.
 * @num: The integer to print.
 * Return: The number of characters printed.
 */
int handle_d(int num)
{
	char *str = itoa(num);
	int count;

	count = write(1, str, strlen(str));
	free(str);
	return (count);
}

/**
 * handle_i - Handles the 'i' specifier.
 * @num: The integer to print.
 * Return: The number of characters printed.
 */
int handle_i(int num)
{
	char *str = itoa(num);
	int count;

	count = write(1, str, strlen(str));
	free(str);
	return (count);
}

/**
 * handle_specifier - Handles specifiers.
 * @c: The specifier.
 * @args: The argument list.
 * Return: The number of characters printed.
 */
int handle_specifier(char c, va_list args)
{
	int count = 0;
	char temp;

	switch (c)
	{
	case 'c':
		temp = (char)va_arg(args, int);
		count += write(1, &temp, 1);
		break;
	case 's':
		count += handle_s(va_arg(args, char *));
		break;
	case '%':
		temp = '%';
		count += write(1, &temp, 1);
		break;
	case 'd':
		count += handle_d(va_arg(args, int));
		break;
	case 'i':
		count += handle_i(va_arg(args, int));
		break;
	default:
		temp = c;
		count += write(1, &temp, 1);
		break;
	}
	return (count);
}
