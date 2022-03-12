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
	printf("%%sadasd%%%s\n", str);
	_printf("\n PRINTF RANCIO HECHO POR NACHO TESTS \n\n");
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	_printf("Len:[%d]\n", len);
	_printf("String:[%s]\n", "I am a string !");
	_printf("Hello %i, %s\n", n, str);
	_printf("Hello %s, %s, %c\n", str, str2, a);
	_printf("%d\n", INT_MAX);
	_printf("%d\n", INT_MIN);
	_printf("%u\n", UINT_MAX);
	_printf("%%sadasd%%%s\n", str);

	char *s;
	char *s2;
	char *s3;
	char *s4;
	char c;
	int i;

	c = 'p';

	i = -123455;

	s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit\n";

	s2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";

	s3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";

	s4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";

	_printf("fasdf\n %s\n %c\n %s\n %s\n %s\n %i\n\n\n", s, c, s2, s3, s4, i);

	unsigned int as;
	int b;

	as = -10;
	b = _printf("%u\n", as);
	_printf(">%i\n", b);
	b = printf("%u\n", as);
	printf(">%i\n", b);
	_printf("%b\n", 15);
	_printf("%b\n", 52);
	_printf("%b\n", 554);
	_printf("%b\n", 5324);
	_printf("%o\n", 15);
	_printf("%o\n", 52);
	_printf("%o\n", 554);
	_printf("%o\n", 5324);
	return (0);
}
