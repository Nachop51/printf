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
	_printf("%+d\n", 30);
	printf("%+d\n", 30);
	_printf("%+ d\n", 30);
	printf("%+ d\n", 30);
	_printf("% +d\n", 30);
	printf("% +d\n", 30);
	_printf("% d\n", 30);
	printf("% d\n", 30);

	_printf("%+d\n", -30);
	printf("%+d\n", -30);
	_printf("%+ d\n", -30);
	printf("%+ d\n", -30);
	_printf("% +d\n", -30);
	printf("% +d\n", -30);
	_printf("% d\n", -30);
	printf("% d\n", -30);
	return (0);
}
