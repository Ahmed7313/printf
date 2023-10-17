#include "main.h"

/**
 * rot13 - encodes a string using rot13.
* @args: The va_list of arguments.
 * @buffer: The output buffer.
 * @j: The current buffer index.
 * Return: pointer to encoded string.
*/
int rot13(va_list args, char *buffer, unsigned int *j)
{
	int index;
	int letterIndex;
	int count = 0;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13Code[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(args, char *);

	for (index = 0; str[index] != '\0'; index++)
	{
		for (letterIndex = 0; letterIndex < 52; letterIndex++)
		{
			if (str[index] == letters[letterIndex])
			{
				buffer[(*j)++] = rot13Code[letterIndex];
				break;
			}
		}
	}
	return (str);
}
