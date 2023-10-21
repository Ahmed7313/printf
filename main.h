#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* Function Prototypes */
int _printf(const char *format, ...);
int handle_specifier(char c, va_list args);
char *itoa(int n);
int handle_s(char *str);
int handle_di(int num);
#endif /* MAIN_H */
