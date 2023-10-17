#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function Prototypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);

#endif /* MAIN_H */
