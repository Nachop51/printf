#include "main.h"
#include <stdint.h>

int print_pointer(va_list args)
{
	long int i, j = 0;
	void *p = va_arg(args, void*);

	if (!p)
		return (-1);

	i = (unsigned long int)p;
	_stdout('0');
	_stdout('x');
	j += print_hexadecimal_aux(i);
	return (j + 2);
}

int print_hexadecimal_aux(unsigned long int n)
{
	long int i = 0, j = 0, *ar;
	unsigned long int a = n;

	if (!n)
		return (-1);
	while (a / 16 != 0)
	{
		a /= 16;
		j++;
	}
	j++;
	ar = malloc(sizeof(long int) * j);
	if (ar == NULL)
		return (-1);
	while (i < j)
	{
		ar[i] = n % 16;
		n /= 16;
		i++;
	}
	i = j - 1;
	while (i >= 0)
	{
		if (ar[i] > 9)
			ar[i] += 39;
		_stdout(ar[i] + '0');
		i--;
	}
	free(ar);
	return (j);
}
