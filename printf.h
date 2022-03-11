#ifndef PRINT_H
#define PRINT_H

/* Libraries */
#include <stdarg.h>

/* Functions */
int _stdout(char);
int _printf(char * format, ...);
int print_string(va_list);
int print_int(va_list);
int print_char(va_list);
int power(int a, int b);

/* Struct */
typedef struct printf
{
	char *s;
	int (*f)(va_list);
} print_f;

#endif