#include <stdio.h>
#include "main.h"

/**
 * main - Entry point, tests the _printf function.
 *
 * Return: Always 0.
 */
int main(void)
{
    int len1, len2;

    /* Testing character specifier */
    len1 = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');
    _printf("Lengths -> _printf: %d, printf: %d\n", len1, len2);

    /* Testing string specifier */
    len1 = _printf("String:[%s]\n", "I am a string!");
    len2 = printf("String:[%s]\n", "I am a string!");
    _printf("Lengths -> _printf: %d, printf: %d\n", len1, len2);

    /* Testing percent specifier */
    len1 = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Lengths -> _printf: %d, printf: %d\n", len1, len2);

    /* Testing null string */
    len1 = _printf("Null String:[%s]\n", NULL);
    len2 = printf("Null String:[%s]\n", NULL);
    _printf("Lengths -> _printf: %d, printf: %d\n", len1, len2);

    return (0);
}
