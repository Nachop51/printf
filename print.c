#include "printf.h"

int main(int argc, char *argv[])
{
	int n = 10;
	char *str = "ASDsadsad";

	_printf("Hello %d, %s\n", n, str);
	_printf("Hello %s\n", str);
	return (0);
}
