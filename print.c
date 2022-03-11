#include "printf.h"

int main(int argc, char *argv[])
{
	int n = 10;
	char *str = "HSLJLHS";

	_printf("Hello %d\n", n);
	_printf("Hello %s\n", str);
	return (0);
}
