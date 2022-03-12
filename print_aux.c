#include "printf.h"

int print_aux(const char *format, print_f print[], va_list args)
{
	int i = 0, j = 0, count = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (print[j].s[0])
			{
				if (print[j].s[0] == format[i + 1])
				{
					count += print[j].f(args);
					i++;
					break;
				}
				j++;
			}
			if (format[i + 1] != '\0')
			{
				i++;
				continue;
			}
			else
				break;
		}
		_stdout(format[i]);
		count++;
		i++;
	}
	return (count);
}