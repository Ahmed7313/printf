#include "main.h"

/**
 * _print_rev_recursion - prints a string, followed by a new line.
 * @s: first n bytes of the memory area
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: Number of chars written
*/
int _print_rev_recursion(char *s, char *buffer, unsigned int *j)
{
	int count = 1;

	if (*s == '\0')
	{
		return (0);
	}
	count += _print_rev_recursion(s + 1, buffer, j);
	buffer[(*j)++] = *s;
	return (count);
}

/**
 * print_rev - Writes a string to buffer in reverse
 * @args: The string
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: Number of chars written
 */
int print_rev(va_list args, char *buffer, unsigned int *j)
{
	int count = 0;
	char *str = va_arg(args, char *);

	str = str == NULL ? "(null)" : str;
	count = _print_rev_recursion(str, buffer, j);
	return (count);
}
