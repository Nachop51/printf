#include "printf.h"

int main(int argc, char *argv[])
{
	int n = 234567897;
	char *str = "ASDsadsad";

	_printf("Hello %i, %s\n", n, str);
	_printf("Hello %s\n", str);
	return (0);
}
