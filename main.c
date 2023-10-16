#include "main.h"
#include <stdio.h>
#include "printf.c"

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	int len;

	len = _printf("Char: %c, String: %s%%\n", 'A', "I am a string");
	_printf("Length: %d\n", len);
	len = _printf("Random stuff %c String: %s%%\n", 'B', "Another string");
	_printf("Length: %d\n", len);
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	return (0);
}
