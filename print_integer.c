#include "main.h"

/**
 * writeDigit- write the digit
 * @digit: the digit to write
 * @buffer: The output buffer.
 * @j: The current buffer index.
 */
void writeDigit(char digit, char *buffer, unsigned int *j)
{
	buffer[(*j)++] = digit;
}

/**
 * printInt- helper recursion function
 * @number: input number
 * @buffer: The output buffer.
 * @j: The current buffer index.
 */
void printInt(int number, char *buffer, unsigned int *j)
{
	unsigned int n = number;

	if (n / 10)
		printInt(n / 10, buffer, j);

	writeDigit('0' + n % 10, buffer, j);
}

/**
 * print_intger - print integer for specifier i , d
 * @args: argument to print
 * @buffer: The output buffer.
 * @j: The current buffer index.
 *
 * Return: number of characters printed
 */
int print_intger(va_list args, char *buffer, unsigned int *j)
{
	unsigned int n = va_arg(args, int);
	int count = 1, num = n;

	if (num < 0)
	{
		writeDigit('-', buffer, j);
		num *= -1;
		n = num;
		count += 1;
	}

	while (n > 9)
	{
		n /= 10;
		count++;
	}

	printInt(num, buffer, j);
	return (count);
}
