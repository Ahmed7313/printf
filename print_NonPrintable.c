#include "main.h"

/**
 * print_S - Writes a string to buffer, replacing non-printable characters
 * @args: The string
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: Number of chars written
 */
int print_S(va_list args, char *buffer, unsigned int *j)
{
	int count = 0;
	char *str = va_arg(args, char *);
	char hex[5];
	char hex_chars[] = "0123456789ABCDEF";

	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			buffer[(*j)++] = '\\';
			buffer[(*j)++] = 'x';

			hex[0] = hex_chars[(*str >> 4) & 0xF];
			hex[1] = hex_chars[*str & 0xF];
			buffer[(*j)++] = hex[0];
			buffer[(*j)++] = hex[1];
			count += 4;
		}
		else
		{
			buffer[(*j)++] = *str;
			count++;
		}
		str++;
	}
	return (count);
}
