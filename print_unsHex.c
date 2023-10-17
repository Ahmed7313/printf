#include "main.h"

/**
 * print_unsignedHex - Prints an unsigned hex.
 * @args: The va_list of arguments.
 *
 * Return: count of characters typed
 */
int print_unsignedHex(va_list args)
{
	unsigned int number, tmp_number;
	int count = 0, size = -1;
	int tmpArr[128];
	char digit;

	number = va_arg(args, unsigned int);
	tmp_number = number;

	while (tmp_number > 16)
	{
		size++;
		tmpArr[size] = tmp_number % 16;
		tmp_number /= 16;
	}

	if (tmp_number >= 0 && tmp_number <= 15)
	{
		size++;
		tmpArr[size] = tmp_number;
	}
	for (; size >= 0; size--)
	{
		count++;
		digit = (char) tmpArr[size];
		write(1, &digit, 1);
	}

	return (count);
}
