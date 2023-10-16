#include "main.h"

/**
 * print_char - Prints a character.
 * @args: A list of arguments.
 * Return: 1.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a string.
 * @args: A list of arguments.
 * Return: The length of the string.
 */
int print_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);
	char *s = str;

	if (str == NULL)
		return (0);

	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}

/**
 * print_percent - Prints a percent symbol.
 * @args: A list of arguments.
 * Return: 1.
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
