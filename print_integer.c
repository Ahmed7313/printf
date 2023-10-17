#include "main.h"

/**
 * writeDigit- write the digit
 * @digit: the digit to write
 */
void writeDigit(char digit)
{
	write(1, &digit, 1);
}

/**
 * printInt- helper recursion function
 * @number: input number
 */
void printInt(int number)
{
	unsigned int n = number;

	if (n / 10)
		printInt(n / 10);

	writeDigit('0' + n % 10);
}

/**
 * print_intger - print integer for specifier i , d
 * @args: argument to print
 *
 * Return: number of characters printed
 */
int print_intger(va_list args)
{
	unsigned int n = va_arg(args, int);
	int count = 1, num = n;

	if (num < 0)
	{
		writeDigit('-');
		num *= -1;
		n = num;
		count += 1;
	}

	while (n > 9)
	{
		n /= 10;
		count++;
	}

	printInt(num);
	return (count);
}
