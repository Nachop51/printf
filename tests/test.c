#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{

  _printf("Test cases for %%u\n");
  printf("Expected: 0\n");
  printf("Actual: %u\n", 0);
  printf("Expected: 1\n");
  printf("Actual: %u\n", 1);
  printf("Expected: 4294967295\n");
  _printf("Actual: %u\n", 4294967295);
  printf("Expected: 2147483647\n");
  _printf("Actual: %u\n", 2147483647);
  printf("Expected: 2147483648\n");
  _printf("Actual: %u\n", 2147483648);
  printf("Expected: 2147483649\n");
  _printf("Actual: %u\n", 2147483649);
  printf("Expected: 4294967294\n");
  _printf("Actual: %u\n", 4294967294);
  printf("Expected: 4294967295\n");
  _printf("Actual: %u\n", 4294967295);

  _printf("Test cases for %%d\n");
  _printf("Test cases for %%o\n");
  printf("Expected: 0\n");
  _printf("Actual: %o\n", 0);
  printf("Expected: 1\n");
  _printf("Actual: %o\n", 1);
  printf("Expected: 37777777777\n");
  _printf("Actual: %o\n", 4294967295);
  printf("Expected: 17777777777\n");
  _printf("Actual: %o\n", 2147483647);
  printf("Expected: 20000000000\n");
  _printf("Actual: %o\n", 2147483648);
  printf("Expected: 20000000001\n");
  _printf("Actual: %o\n", 2147483649);
  printf("Expected: 37777777776\n");
  _printf("Actual: %o\n", 4294967294);
  printf("Expected: 37777777777\n");
  _printf("Actual: %o\n", 4294967295);

  _printf("Test cases for %%x\n");
  printf("Expected: 0\n");
  _printf("Actual: %x\n", 0);
  printf("Expected: 1\n");
  _printf("Actual: %x\n", 1);
  printf("Expected: ffffffff\n");
  _printf("Actual: %x\n", 4294967295);
  printf("Expected: 7fffffff\n");
  _printf("Actual: %x\n", 2147483647);
  printf("Expected: 80000000\n");
  _printf("Actual: %x\n", 2147483648);
  printf("Expected: 80000001\n");
  _printf("Actual: %x\n", 2147483649);

  _printf("Test cases for %%X\n");
  printf("Expected: 0\n");
  _printf("Actual: %X\n", 0);
  printf("Expected: 1\n");
  _printf("Actual: %X\n", 1);
  printf("Expected: FFFFFFFF\n");
  _printf("Actual: %X\n", 4294967295);
  printf("Expected: 7FFFFFFF\n");
  _printf("Actual: %X\n", 2147483647);
  printf("Expected: 80000000\n");
  _printf("Actual: %X\n", 2147483648);
  printf("Expected: 80000001\n");

  _printf("Test cases for %%p\n");
  printf("Expected: (nil)\n");
  _printf("Actual: %p\n", NULL);
  printf("Expected: %p\n", &printf);
  _printf("Actual: %p\n", &printf);
  printf("Expected: %p\n", &main);
  _printf("Actual: %p\n", &main);

  _printf("Test cases for %%r\n");
  _printf("Expected: !dlroW ,olleH\n");
  _printf("Actual: %r\n", "Hello, World!");
  _printf("Expected: Hello, World!\n");
  _printf("Actual: %r\n", "!dlroW ,olleH");

  _printf("Test cases for %%R\n");
  _printf("Expected: Uryyb, Jbeyq!\n");
  _printf("Actual: %R\n", "Hello, World!");

  _printf("Test cases for %%b\n");
  printf("Expected: 0\n");
  _printf("Actual: %b\n", 0);
  printf("Expected: 1\n");
  _printf("Actual: %b\n", 1);
  printf("Expected: 11111111111111111111111111111111\n");
  _printf("Actual: %b\n", 4294967295);
  printf("Expected: 1111111111111111111111111111111\n");
  _printf("Actual: %b\n", 2147483647);
  printf("Expected: 10000000000000000000000000000000\n");
  _printf("Actual: %b\n", 2147483648);
  printf("Expected: 10000000000000000000000000000001\n");
  _printf("Actual: %b\n", 2147483649);

  _printf("Test cases for %%b\n");
  printf("Expected:\t%b\n", 0);
  _printf("Actual:\t\t%b\n", 0);
  printf("Expected:\t%b\n", -1);
  _printf("Actual:\t\t%b\n", -1);
  printf("Expected:\t%b\n", -3245);
  printf("Expected:\t%b\n", 3245);
  _printf("Actual:\t\t%b\n", -3245);
  _printf("Actual:\t\t%b\n", 3245);
  printf("Expected:\t%b\n", -2147483649);
  _printf("Actual:\t\t%b\n", -2147483649);

  return (0);
}
