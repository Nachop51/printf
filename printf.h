#ifndef PRINT_H
#define PRINT_H

/* Libraries */
#include <stdarg.h>
#include <stdlib.h>

/* Struct */
struct print
{
	char *s;
	int (*f)(va_list);
};
typedef struct print print_f;

/* Functions */
int _stdout(char);
int _printf(const char * format, ...);
int print_aux(const char *format, print_f print[], va_list args);
int print_string(va_list);
int print_int(va_list);
int print_percentage(va_list);
int print_unsigned_int(va_list);
int print_binary(va_list);
int print_char(va_list);
int print_octal(va_list);
int print_hexadecimal(va_list);
int print_heXadecimal(va_list);
int print_reversed(va_list);
int print_rot13(va_list);
int power(int a, int b);

#endif