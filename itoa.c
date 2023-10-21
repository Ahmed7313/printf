#include <stdlib.h>

/**
 * itoa - Convert integer to string
 * @n: The integer
 * Return: Pointer to the resulting string. NULL if allocation fails.
 */
char *itoa(int n)
{
	char *str = malloc(12);
	int i = 0, sign = n;

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

	for (int start = 0, end = i - 1; start < end; start++, end--)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}

	return (str);
}
