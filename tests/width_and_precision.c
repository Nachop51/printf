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

	len = _printf("%05.3d", 0);
	len2 = printf("%05.3d", 0);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%05.3d", 40);
	len2 = printf("%05.3d", 40);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%+5.3d", 0);
	len2 = printf("%+5.3d", 0);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%+5.3d", 40);
	len2 = printf("%+5.3d", 40);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% 5.3d", 0);
	len2 = printf("% 5.3d", 0);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% 5.3d", 40);
	len2 = printf("% 5.3d", 40);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% 05.3d", 0);
	len2 = printf("% 05.3d", 0);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% 05.3d", 40);
	len2 = printf("% 05.3d", 40);
	fflush(stdout);
	printf("\nlen: %d, len2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}