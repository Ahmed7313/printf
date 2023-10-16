#include "main.h"

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @... : The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, count = 0;
    va_list args;

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 'c' ||
                                 format[i + 1] == 's' || format[i + 1] == '%'))
        {
            switch (format[i + 1])
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_string(args);
                    break;
                case '%':
                    count += print_percent(args);
                    break;
            }
            i++;
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}