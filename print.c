#include "printf.h"

int main(int argc, char *argv[])
{
	int n = 13432780;
	char *str = "ASDsadsad";

	_printf("Hello %i, %s\n", n, str);
	_printf("Hello %s\n", str);
	return (0);
}
