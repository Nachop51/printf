#include <unistd.h>

/**
 * _stdout - Prints out a char to the standard output
 * @c: Char to be printed
 *
 * Return: no error
 */
int _stdout(char c)
{
	return (write(1, &c, 1));
}
