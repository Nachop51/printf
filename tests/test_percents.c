#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len2 = printf("% % % %");
	len = _printf("% % % %");
	printf("_printf: %d, printf: %d\n", len, len2);
	len2 = printf("% ", 10);
	len = _printf("% ", 10);
	printf("_printf: %d, printf: %d\n", len, len2);

	return (0);
}
