#include "main.h"

/**
 * print_num_rec - prints an integer recursively
 * @n: Integer
 */

void print_num_rec(int n)
{
	unsigned int num = n;
	char digit;

	if (num / 10)
		print_num_rec(num / 10);

	digit = '0' + num % 10;
	write(1, &digit, 1);
}

/**
 * print_intger - prints an integer
 * @vl: Integer
 * Return: int
 */

int print_intger(va_list vl)
{
	unsigned int n = va_arg(vl, int);
	int count = 1, num = n;
	char digit;

	if (num < 0)
	{
		digit = '-';
		write(1, &digit, 1);
		num *= -1;
		n = num;
		count += 1;
	}

	while (n > 9)
		n /= 10,
			count++;

	print_num_rec(num);
	return (count);
}
