#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}

/**
 * int_to_str - Converts an integer to a string.
 * @num: The integer.
 * Return: The converted string.
 */
char *int_to_str(int num)
{
	char *str;
	int temp, digits = 0;

	temp = num;
	while (temp)
	{
		digits++;
		temp /= 10;
	}

	str = malloc(digits + 1);
	if (!str)
		return (NULL);

	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = (num % 10) + '0';
		num /= 10;
	}

	return (str);
}

/**
 * write_str - Writes a string to stdout.
 * @str: The string.
 * Return: The number of characters written.
 */
int write_str(char *str)
{
	return (write(1, str, str_len(str)));
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
		write(1, &ch, 1);
		count++;
		break;
	case 's':
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		count += write(1, str, _strlen(str));
		break;
	case 'd':
	case 'i':
		str = int_to_str(va_arg(args, int));
		if (str)
		{
			count += write(1, str, _strlen(str));
			free(str);
		}
		break;
	case '%':
		write(1, &c, 1);
		count++;
		break;
	default:
		break;
	}
	return (count);
}
