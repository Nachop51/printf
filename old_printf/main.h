#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Struct */
/**
 * struct print - Main structure that takes a char and a function
 * @s: name or way to compare the function
 * @f: pointer to a function
 */
struct print
{
	char *s;
	int (*f)(va_list);
};
typedef struct print print_f;

/* Functions */
int _stdout(char);
int _printf(const char *format, ...);
int print_aux(const char *format, print_f print[], va_list args);
int print_string(va_list);
int print_String(va_list);
int print_pointer(va_list);
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
int power(int, int);
int print_hexadecimal_aux(unsigned long int);
int print_heXadecimaln(unsigned int n);

#endif
