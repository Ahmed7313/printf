#include "main.h"

/**
 * print_Binary - Prints binary represntation of a number.
 * @args: The va_list of arguments.
 * @buffer: The output buffer.
 * @j: The current buffer index.
 *
 * Return: count of characters typed
 */
int print_Binary(va_list args, char *buffer, unsigned int *j)
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
			buffer[(*j)++] = digit;
		}
		else if (count > 0)
		{
			count++;
			digit = '0';
			buffer[(*j)++] = digit;
		}
	}

	if (count == 0)
	{
		count++;
		digit = '0';
		buffer[(*j)++] = digit;
	}
	return (count);
}
