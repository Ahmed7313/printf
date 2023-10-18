#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_int - Writes an integer to buffer
 * @args: The integer
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: Number of chars written
 */
int print_int(va_list args, char *buffer, unsigned int *j)
{
	int n = va_arg(args, int);
	int count = 0;
	char str[12]; /* Buffer to hold the maximum integer */
	char *p = &str[11];

	*p = '\0';
	if (n < 0)
	{
		buffer[(*j)++] = '-';
		n = -n;
		count++;
	}
	do {
		*--p = '0' + (n % 10);
		n /= 10;
	} while (n);

	while (*p)
	{
		buffer[(*j)++] = *p++;
		count++;
	}
	return (count);
}
