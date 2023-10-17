#include "main.h"

/**
 * print_unsignedOct - prints an octal number.
 * @args: The va_list of arguments.
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: number of printed digits.
 */
int print_unsignedOct(va_list args, char *buffer, unsigned int *j)
{
	int i, count = 0;
	int *array;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp_num = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		array[i] = temp_num % 8;
		temp_num /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		buffer[(*j)++] = (array[i] + '0');
	}
	free(array);
	return (count);
}
