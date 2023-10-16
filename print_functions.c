#include "main.h"

/**
 * print_char - Prints a character.
 * @args: The va_list of arguments.
 * Return: 1 (the number of characters printed).
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);

    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Prints a string.
 * @args: The va_list of arguments.
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
    int count = 0;
    char *str = va_arg(args, char *);
    char *null_case = "(null)";

    if (str)
    {
        while (str[count])
        {
            write(1, &str[count], 1);
            count++;
        }
    }
    else
    {
        while (null_case[count])
        {
            write(1, &null_case[count], 1);
            count++;
        }
    }
    return (count);
}

/**
 * print_percent - Prints a percent symbol.
 * @args: The va_list of arguments (unused).
 * Return: 1 (the number of characters printed).
 */
int print_percent(va_list args __attribute__((unused)))
{
    char percent = '%';

    write(1, &percent, 1);
    return (1);
}
