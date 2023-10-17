#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/* Function Prototypes */
int _printf(const char *format, ...);
unsigned int handle_format(const char *format, unsigned int *i,
	va_list args, char *buffer, unsigned int *j);
unsigned int handle_unformat(char c);
int print_char(va_list args, char *buffer, unsigned int *j);
int print_str(va_list args, char *buffer, unsigned int *j);
int print_string(va_list args);
int print_percent(va_list args);
int print_intger(va_list args, char *buffer, unsigned int *j);
int print_Binary(va_list args, char *buffer, unsigned int *j);
int print_unsignedIntger(va_list args, char *buffer, unsigned int *j);
int print_unsignedOct(va_list args, char *buffer, unsigned int *j);
int print_unsignedHex(va_list args, char *buffer, unsigned int *j, char sp);
int print_rot13(va_list args, char *buffer, unsigned int *j);
#endif /* MAIN_H */
