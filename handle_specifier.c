#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
	case 'i':
		count += handle_di(va_arg(args, int));
		break;
	default:
		temp = c;
		count += write(1, &temp, 1);
		break;
	}
	return (count);
}

/**
 * handle_s - Handles 's' specifier.
 * @str: The string.
 * Return: The number of characters printed.
 */
int handle_s(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (write(1, str, strlen(str)));
}

/**
 * handle_di - Handles 'd' and 'i' specifiers.
 * @num: The number.
 * Return: The number of characters printed.
 */
int handle_di(int num)
{
	char *int_str = itoa(num);
	int count = 0;

	if (int_str != NULL)
	{
		count += write(1, int_str, strlen(int_str));
		free(int_str);
	}
	return (count);
}
