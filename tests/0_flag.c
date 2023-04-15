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

	len = _printf("% 05d\n", 1234);
	len2 = printf("% 05d\n", 1234);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		printf("len: %d, len2: %d\n", len, len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
