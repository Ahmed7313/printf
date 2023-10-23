#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen - Calculate the length of a string.
 * @s: The string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * int_to_str - Convert an integer to a string.
 * @num: The integer.
 * Return: The converted string.
 */
char *int_to_str(int num)
{
	char *str;
	int i = 0, temp = num, len = 0;

	while (temp != 0)
	{
		len++;
		temp /= 10;
	}

	str = malloc(len + 1);
	if (!str)
		return (NULL);

	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1 - i] = (num % 10) + '0';
		num /= 10;
		i++;
	}

	return (str);
}

/**
 * write_str - Write a string to stdout.
 * @str: The string.
 * Return: The number of characters written.
 */
int write_str(char *str)
{
	return (write(1, str, _strlen(str)));
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
	char *str;
	char ch;

	switch (c)
	{
	case 'c':
		ch = (char)va_arg(args, int);
		count += write(1, &ch, 1);
		break;
	case 's':
		str = va_arg(args, char *);
		if (str)
			count += write_str(str);
		break;
	case 'd':
	case 'i':
		str = int_to_str(va_arg(args, int));
		if (str)
		{
			count += write_str(str);
			free(str);
		}
		break;
	case '%':
		count += write(1, &c, 1);
		break;
	default:
		break;
	}
	return (count);
}
