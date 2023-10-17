#include "main.h"

/**
 * print_unsignedOctal - Prints an unsigned octal.
 * @args: The va_list of arguments.
 *
 * Return: count of characters typed
 */
int print_unsignedOctal(va_list args)
{
	unsigned int number, tmp_number;
	int count = 0, size = -1;
	int j;
	int tmpArr[128];
	char digit;

	number = va_arg(args, unsigned int);
	tmp_number = number;

	while (tmp_number > 8)
	{
		size++;
		tmpArr[size] = tmp_number % 8;
		tmp_number /= 8;
	}

	if (tmp_number >= 0 && tmp_number <= 7)
	{
		size++;
		tmpArr[size] = tmp_number;
	}
	for (j = size - 1; size >= 0; size--)
	{
		count++;
		digit = (char)((tmpArr[size]) + '0');
		write(1, &digit, 1);
	}

	return (count);
}
