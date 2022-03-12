#include <limits.h>
#include <stdio.h>
#include "printf.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int n = 13432780;
	char *str = "\"sd";
	char *str2 = "asdsa";
	char a = 65;
	char *null = NULL;
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");

	printf("\n PRINTF TESTS \n\n");
	printf("%u\n", 39265893);
	printf("Length:[%d, %i]\n", len2, len2);
	printf("Negative:[%d]\n", -762534);
	printf("Character:[%c]\n", 'H');
	printf("String:[%s]\n", "I am a string !");
	printf("Len:[%d]\n", len2);
	printf("Hello %i, %s\n", n, str);
	printf("Hello %s, %s, %c\n", str, str2, a);
	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MIN);
	printf("%u\n", UINT_MAX);
	// printf("Unknown:[%r]\n");
	// _printf("Unknown:[%r]\n");
	_printf("\n PRINTF RANCIO TESTS \n\n");
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	// _printf("%S\n", "Best\nSchool");
	_printf("Len:[%d]\n", len);
	_printf("String:[%s]\n", "I am a string !");
	_printf("Hello %i, %s\n", n, str);
	_printf("Hello %s, %s, %c\n", str, str2, a);
	_printf("%d\n", INT_MAX);
	_printf("%d\n", INT_MIN);
	_printf("%u\n", UINT_MAX);
	return (0);
}
