#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;
	_printf("Test cases for %%u\n");
	len = printf(" printf:\t%u\n", 0);
	len2 = _printf("_printf:\t%u\n", 0);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%u\n", 1);
	len2 = _printf("_printf:\t%u\n", 1);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%u\n", 2147483647);
	len2 = _printf("_printf:\t%u\n", 2147483647);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%u\n", 2147483648);
	len2 = _printf("_printf:\t%u\n", 2147483648);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%u\n", 2147483649);
	len2 = _printf("_printf:\t%u\n", 2147483649);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%u\n", 4294967294);
	len2 = _printf("_printf:\t%u\n", 4294967294);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%u\n", 4294967295);
	len2 = _printf("_printf:\t%u\n", 4294967295);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);

	_printf("Test cases for %%d\n");
	len = printf(" printf:\t%d\n", 0);
	len2 = _printf("_printf:\t%d\n", 0);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%d\n", 1);
	len2 = _printf("_printf:\t%d\n", 1);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%d\n", -1);
	len2 = _printf("_printf:\t%d\n", -1);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%d\n", 2147483647);
	len2 = _printf("_printf:\t%d\n", 2147483647);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%d\n", -2147483648);
	len2 = _printf("_printf:\t%d\n", -2147483648);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	/* This cases fails */
	len = printf(" printf:\t%d\n", 2147483648);
	len2 = _printf("_printf:\t%d\n", 2147483648);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%d\n", 2147483649);
	len2 = _printf("_printf:\t%d\n", 2147483649);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t-2147483647\n");
	len2 = _printf("_printf:\t%d\n", -2147483647);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);

	_printf("Test cases for %%o\n");
	printf("Expected: 0\n");
	_printf("Actual: %o\n", 0);
	printf("Expected: 1\n");
	_printf("Actual: %o\n", 1);
	printf("Expected: 37777777777\n");
	_printf("Actual: %o\n", 4294967295);
	printf("Expected: 17777777777\n");
	_printf("Actual: %o\n", 2147483647);
	printf("Expected: 20000000000\n");
	_printf("Actual: %o\n", 2147483648);
	printf("Expected: 20000000001\n");
	_printf("Actual: %o\n", 2147483649);
	printf("Expected: 37777777776\n");
	_printf("Actual: %o\n", 4294967294);
	printf("Expected: 37777777777\n");
	_printf("Actual: %o\n", 4294967295);

	_printf("Test cases for %%x\n");
	printf("Expected: 0\n");
	_printf("Actual: %x\n", 0);
	printf("Expected: 1\n");
	_printf("Actual: %x\n", 1);
	printf("Expected: ffffffff\n");
	_printf("Actual: %x\n", 4294967295);
	printf("Expected: 7fffffff\n");
	_printf("Actual: %x\n", 2147483647);
	printf("Expected: 80000000\n");
	_printf("Actual: %x\n", 2147483648);
	printf("Expected: 80000001\n");
	_printf("Actual: %x\n", 2147483649);

	_printf("Test cases for %%X\n");
	printf("Expected: 0\n");
	_printf("Actual: %X\n", 0);
	printf("Expected: 1\n");
	_printf("Actual: %X\n", 1);
	printf("Expected: %X\n", 4294967295);
	_printf("Actual: %X\n", 4294967295);
	printf("Expected: 7FFFFFFF\n");
	_printf("Actual: %X\n", 2147483647);
	printf("Expected: 80000000\n");
	_printf("Actual: %X\n", 2147483648);
	printf("Expected: 80000001\n");

	_printf("Test cases for %%p\n");
	printf("Expected: (nil)\n");
	_printf("Actual: %p\n", NULL);
	printf("Expected: %p\n", &printf);
	_printf("Actual: %p\n", &printf);
	printf("Expected: %p\n", &main);
	_printf("Actual: %p\n", &main);

	_printf("Test cases for %%r\n");
	_printf("Expected: !dlroW ,olleH\n");
	_printf("Actual: %r\n", "Hello, World!");
	_printf("Expected: Hello, World!\n");
	_printf("Actual: %r\n", "!dlroW ,olleH");

	_printf("Test cases for %%R\n");
	_printf("Expected: Uryyb, Jbeyq!\n");
	_printf("Actual: %R\n", "Hello, World!");

	_printf("Test cases for %%b\n");
	len = printf(" printf:\t0\n");
	len2 = _printf("_printf:\t%b\n", 0);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t1\n");
	len2 = _printf("_printf:\t%b\n", 1);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t\n", 4294967295);
	len2 = _printf("_printf:\t%b\n", 4294967295);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%b\n", 2147483647);
	len2 = _printf("_printf:\t%b\n", 2147483647);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t10000000000000000000000000000000\n");
	len2 = _printf("_printf:\t%b\n", 2147483648);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%b\n", 2147483649);
	len2 = _printf("_printf:\t%b\n", 2147483649);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);

	_printf("Test cases for %%b\n");
	len = printf(" printf:\t%b\n", 0);
	len2 = _printf("_printf:\t%b\n", 0);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%b\n", -1);
	len2 = _printf("_printf:\t%b\n", -1);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%b\n", -3245);
	len2 = _printf("_printf:\t%b\n", -3245);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%b\n", 3245);
	len2 = _printf("_printf:\t%b\n", 3245);
	_printf("length  printf: %d, length _printf: %d\n", len, len2);
	len = printf(" printf:\t%b\n", -2147483649);
	len2 = _printf("_printf:\t%b\n", -2147483649);
	_printf("length expected: %d, length _printf: %d\n", len, len2);

	return (0);
}
