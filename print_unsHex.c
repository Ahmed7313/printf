#include "main.h"

/**
 * print_unsignedHex - prints an hex number.
 * @args: The va_list of arguments.
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * @sp: specfier to know if the hx in upper/lower case
 * Return: number of printed digits.
 */
int print_unsignedHex(va_list args, char *buffer, unsigned int *j, char sp)
{
	int i, count = 0;
	int *array;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp_num = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		array[i] = temp_num % 16;
		temp_num /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + (sp == 'X' ? 7 : 39);
		buffer[(*j)++] = (array[i] + '0');
	}
	free(array);
	return (count);
}
