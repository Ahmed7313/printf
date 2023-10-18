#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * ...
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned int i = 0, j = 0, count = 0;
    char *buffer = malloc(1024);
    size_t buffer_size = 1024;

    if (buffer == NULL)
    {
        return (-1);
    }

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && (format[i + 1] == '\0' || !is_valid_specifier(format[i + 1])))
            return (-1);

        if (format[i] == '%' && format[i + 1] != '\0')
        {
            count += handle_format(format, &i, args, buffer, &j);
        }
        else
        {
            buffer[j++] = format[i];
            count++;
        }

        if (j >= buffer_size - 1)
        {
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
        }
        i++;
    }

    write(1, buffer, j);
    free(buffer);
    va_end(args);

    return (count);
}
