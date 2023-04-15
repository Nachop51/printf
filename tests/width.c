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
	int len, len2 = 0;

	len = _printf("%5d\n", 1234);
	len = _printf("%-25d\n", 1234);
	len = _printf("%13d\n", 1234);
	len = _printf("%-135d\n", 1234);
	len = _printf("%-54d\n", 1234);
	fflush(stdout);
	return (0);
}