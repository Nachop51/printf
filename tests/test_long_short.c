#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;
	len = _printf("%hu\n", 578344225874334);
	len2 = printf("%hu\n", 578344225874334);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%u\n", 578344225874334);
	len2 = printf("%u\n", 578344225874334);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%lu\n", 578344225874334);
	len2 = printf("%lu\n", 578344225874334);
	_printf("len: %d, len2: %d\n", len, len2);

	len = _printf("%hd\n", 578344225874334L);
	len2 = printf("%hd\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%d\n", 578344225874334L);
	len2 = printf("%d\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%ld\n", 578344225874334L);
	len2 = printf("%ld\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);

	len = _printf("%hx\n", 578344225874334L);
	len2 = printf("%hx\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%x\n", 578344225874334L);
	len2 = printf("%x\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%lx\n", 578344225874334L);
	len2 = printf("%lx\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);

	len = _printf("%hX\n", 578344225874334L);
	len2 = printf("%hX\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%X\n", 578344225874334L);
	len2 = printf("%X\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%lX\n", 578344225874334L);
	len2 = printf("%lX\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);

	len = _printf("%ho\n", 578344225874334L);
	len2 = printf("%ho\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%o\n", 578344225874334L);
	len2 = printf("%o\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%lo\n", 578344225874334L);
	len2 = printf("%lo\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);

	len = _printf("%hb\n", 578344225874334L);
	len2 = printf("%hb\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%b\n", 578344225874334L);
	len2 = printf("%b\n", 578344225874334L);
	_printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%lb\n", 578344225874334L);
	len2 = printf("%lb\n", 578344225874334L);

	return (0);
}
