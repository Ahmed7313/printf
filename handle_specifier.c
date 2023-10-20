#include "main.h"
#include <stdio.h>  /* For debugging purposes */

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
	char temp;

	printf("Handling specifier: %c\n", c);  /* Debug print */

	switch (c)
	{
	case 'c':
		temp = (char)va_arg(args, int);
		count += write(1, &temp, 1);
		break;
	case 's':
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		count += write(1, str, strlen(str));
		break;
	case '%':
		temp = '%';
		count += write(1, &temp, 1);
		break;
	default:
		printf("Unknown specifier: %c\n", c);  /* Debug print */
		break;
	}

	return (count);
}
