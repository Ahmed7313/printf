#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* Function Prototypes */
int _printf(const char *format, ...);
int handle_specifier(char c, va_list args);
int handle_d(int num);
int handle_i(int num);
int handle_s(char *str);
#endif /* MAIN_H */
