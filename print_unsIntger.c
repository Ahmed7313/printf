#include "main.h"

/**
 * print_unsignedIntger - Prints an unsigned intger.
 * @args: The va_list of arguments.
 *
 * Return: count of characters typed
 */
int print_unsignedIntger(va_list args)
{
	unsigned int number, tmp_number;
	int count = 0, size = 1;
	char digit;

	number = va_arg(args, unsigned int);
	tmp_number = number;

	while (tmp_number > 9)
	{
		tmp_number /= 10;
		size *= 10;
	}

	for ( ; size >= 1; size /= 10)
	{
		count++;
		digit = (char) (((number / size) % 10) + '0');
		write(1, &digit, 1);
	}

	return (count);
}
