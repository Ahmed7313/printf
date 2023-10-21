#include <stdlib.h>
#include "main.h"

/**
 * itoa - Convert integer to string
 * @n: The integer
 * Return: Pointer to the resulting string. NULL if allocation fails.
 */
char *itoa(int n)
{
	char *str = malloc(12);
	int i = 0, sign = n;
	int start, end;
	char temp;

	if (str == NULL)
		return (NULL);

	if (sign < 0)
		n = -n;

	do {
		str[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		str[i++] = '-';

	str[i] = '\0';

	start = 0;
	end = i - 1;

	for (; start < end; start++, end--)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}

	return (str);
}
