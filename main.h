#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/* Macros */

#define BUFFER_SIZE 1024

/* Define the flags to easily check them using bitwise operators */

#define FLAG_MINUS 1
#define FLAG_ZERO 2
#define FLAG_PLUS 4
#define FLAG_SPACE 8
#define FLAG_HASH 16

#define LENGTH_H 1
#define LENGTH_L 2

/* Define bases */

#define BASE_10 "0123456789"
#define BASE_16 "0123456789abcdef"
#define BASE_16_UPPER "0123456789ABCDEF"

#define UNSIGNED 1
#define SIGNED 0

#define UPPER 1
#define LOWER 0

/**
 * struct modifiers - Struct modifiers
 * @flags: The flags
 * @width: The width
 * @precision: The precision
 * @length: The length
 *
 * Description: Struct modifiers
 */
typedef struct modifiers
{
	char flags;
	int width;
	int precision;
	char length;
} mod_t;

/**
 * struct buffer - Struct buffer
 * @buf: The buffer
 * @i: The index
 * @counter: The counter
 * @mod: The modifiers
 */
typedef struct buffer
{
	char buf[BUFFER_SIZE];
	int i;
	int counter;
	mod_t mod;
} buffer_t;

/**
 * struct print - Struct print
 *
 * @type: The operator
 * @f: The function associated
 */
typedef struct print
{
	char type;
	void (*f)(buffer_t *, va_list);
} print_t;

/* buffer.c */

void init_buffer(buffer_t *buffer);
void flush_buffer(buffer_t *buffer);
int write_buffer(buffer_t *buffer, char c);
int write_buffer_str_n(buffer_t *buffer, char *str, int n);
int write_buffer_int(buffer_t *buffer, int n);

/* printf.c */

int _printf(const char *format, ...);
int _printf_helper(const char *format, print_t p[], buffer_t *, va_list args);
int to_format(const char *format, print_t p[], buffer_t *buffer, va_list args);
void (*eval_specifier(char specifier, print_t p[]))(buffer_t *, va_list);
int evaluate_modifiers(buffer_t *buffer, const char *format, int len);

/* strings.c */

int _stdout(char c);
int _strlen(char *s);
int _is_alpha(char c);
int _atoi(const char *s);
int number_length(long n, int base_len, int is_u, int precision);

/* Format functions */

void p_str(buffer_t *buffer, va_list args);
void p_char(buffer_t *buffer, va_list args);
void p_int(buffer_t *buffer, va_list args);
void p_percent(buffer_t *buffer, va_list args);
void p_u_int(buffer_t *buffer, va_list args);
void p_binary(buffer_t *buffer, va_list args);
void p_octal(buffer_t *buffer, va_list args);
void p_hex(buffer_t *buffer, va_list args);
void p_hex_upper(buffer_t *buffer, va_list args);
void p_pointer(buffer_t *buffer, va_list args);
void p_reverse(buffer_t *buffer, va_list args);
void p_string_ascii(buffer_t *buffer, va_list args);
void p_rot13(buffer_t *buffer, va_list args);

/* print_base.c */

void print_base(unsigned int n, char *base, int base_len, buffer_t *buffer);
void print_base_long(unsigned long n, char *base,
					 int base_len, buffer_t *buffer);
void print_base_short(unsigned short int n, char *base,
					  int base_len, buffer_t *buffer);
void print_symbol(long n, buffer_t *buffer, int is_u);
void print_string(char *str, buffer_t *buffer, char is_ch);

/* modifiers.c */

void reset_modifiers(buffer_t *buffer);
int is_flag(const char *format, buffer_t *buffer);
int calculate_width(const char *format, buffer_t *buffer, va_list args);
int calculate_precision(const char *format, buffer_t *buffer, va_list args);
int is_length(char c, buffer_t *buffer);

/* more_modifiers.c */

void print_width(buffer_t *buffer, int length);
void print_precision(buffer_t *buffer, int length);
int has_sign(long int n, buffer_t *buffer, int is_u);
void format_number(long num, int base, buffer_t *buffer, int upper, int is_u);
void print_number(unsigned long n, int base_len, buffer_t *buffer, int upper);

#endif /* PRINTF_H */
