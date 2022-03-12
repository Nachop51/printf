#include "printf.h"

int print_percentage(__attribute__((unused))va_list args)
{
	_stdout('%');
	return (1);
}
