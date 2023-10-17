#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/* Function Prototypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_intger(va_list args);
int print_Binary(va_list args);

#endif /* MAIN_H */
