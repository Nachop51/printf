#include "main.h"
#include <stdint.h>

int print_pointer(va_list args)
{
	long int i;
	void *p = va_arg(args, void*);

	if (!p)
		return (-1);

	i = (unsigned long int)p;
	_stdout('0');
	_stdout('x');
	print_hexadecimal_aux(i);
	return (0);
}

int print_hexadecimal_aux(unsigned int n)
{
	unsigned int i = 0, j = 0, a = n;
	char *s;

	if (!n)
		return (-1);
	while (a != 0)
	{
		a /= 16;
		j++;
	}
	s = malloc(sizeof(char) * j + 1);
	if (s == NULL)
		return (-1);

	while (n > 0)
	{
		if (n % 16 >= 10)
		{
			s[i] = ((n % 16) - 10) + 97;
		}
		else
		{
			s[i] = n % 16 + 48;
		}
		n /= 16;
		i++;
	}
	s[i] = '\0';
	j = 0;
	while (i != 0)
	{
		i--;
		_stdout(s[i]);
		j++;
	}
	free(s);
	return (j);
}
