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
	len = _printf("%#x\n", 0);
	len2 = printf("%#x\n", 0);
	printf("len: %d, len2: %d\n", len, len2);
	len = _printf("%#x\n", 1);
	len2 = printf("%#x\n", 1);
	printf("len: %d, len2: %d\n", len, len2);
	return (0);
}
