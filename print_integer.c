#include "main.h"

/**
 * print_intger - print integer for specifier i , d
 * @args: argument to print
 *
 * Return: number of characters printed
 */
int print_intger(va_list args)
{
	int n = va_arg(args, int);
	int num, last, exp = 1;
	char digit;
	int i = 1;

	if (n < 0)
	{
		digit = '-';
		write(1, &digit, 1);
		n = -n;
		i++;
	}

	last = n % 10;
	n = n / 10;
	num = n;

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = (num / exp + '0');
			write(1, &digit, 1);
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	digit = (last + '0');
	write(1, &digit, 1);
	return (i);
}
