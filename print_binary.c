#include "main.h"

/**
 * print_Binary - Prints binary represntation of a number.
 * @args: The va_list of arguments.
 *
 * Return: count of characters typed
 */
int print_Binary(va_list args)
{

	unsigned int number = va_arg(args, int);
	int count = 0;
	int c, k;
	char digit;

	for (c = 31; c >= 0; c--)
	{
		k = number >> c;

		if (k & 1)
		{
			count++;
			digit = '1';
			write(1, &digit, 1);
		}
		else if (count > 0)
		{
			count++;
			digit = '0';
			write(1, &digit, 1);
		}
	}

	if (count == 0)
	{
		count++;
		digit = '0';
		write(1, &digit, 1);
	}
	return (count);
}
