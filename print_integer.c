#include "main.h"

/**
* print_intger - Prints an intger.
* @args: The va_list of arguments.
*
* Return: count of characters typed
*/
int print_intger(va_list args)
{

	int n = va_arg(args, int);
	int copy, tenth, count = 0, size = 1;
	char digit;

	if (n < 0)
	{
		char minus = '-';

		count++;
		write(1, &minus, 1);
		copy = n * -1;
	}
	else
	{
		copy = n;
	}

	tenth = copy;

	while (tenth > 9)
	{
		tenth /= 10;
		size *= 10;
	}

	for ( ; size >= 1; size /= 10)
	{
		count++;
		digit = (char) (((copy / size) % 10) + '0');

		write(1, &digit, 1);
	}

	return (count);
}
