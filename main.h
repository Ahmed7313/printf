#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int handle_specifier(char c, va_list args);
char *int_to_str(int num);
int write_str(char *str);

#endif /* MAIN_H */
