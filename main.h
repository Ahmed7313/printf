#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* Function Prototypes */
int _printf(const char *format, ...);
int handle_specifier(char c, va_list args);

#endif /* MAIN_H */
