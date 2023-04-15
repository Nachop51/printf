# \_printf -- Readme page

### NAME

&emsp;\_printf()

### SYNOPSIS

&emsp;#include <main.h>

&emsp;**int printf(const char \*_format_, ...);**

### DESCRIPTION

&emsp;The \_printf is a function that takes a format and can take n parameters. In order to display those
parameters in a specific way it is necessary to specify it in the format(with % and a valid conversion). Then sends the formatted output to the standard output.

#### Usage example

&emsp;\_printf("Hello %s", "world!");

&emsp; Output: Hello world!

##### Could also take no parameters:

&emsp;\_printf("Hello World!");

&emsp; Output: Hello world!

##### Could also take more than one parameter:

&emsp; \_printf("Today is %s, march %dth", "tuesday", 15)

&emsp; Output: Today is tuesday, march 15th

###### Note: In order to print a % use %%.

### Conversion Specifiers

&emsp; **d, i** &emsp;Converts the argument to a signed decimal

##### Example:

&emsp; \_printf("My favourite number is: %d", 15);

##### Expected output:

&emsp; My favourite number is: 15

&emsp; **u, o, x, X** &emsp;Converts the argument to an unsigned base

##### Examples:

&emsp; \_printf("Today is: %u", 15); <- (u stands for unsigned decimal)\
&emsp; \_printf("10 in octal is: %o", 10); \
&emsp; \_printf("Lowercase hexadecimal: %x", 29); \
&emsp; \_printf("Uppercase hexadecimal: %X", 29); <- (uppercase letters)

##### Expected output:

&emsp; Today is: 15 \
&emsp; 10 in octal is: 12 \
&emsp; Lowercase hexadecimal: 1d \
&emsp; Uppercase hexadecimal: 1D

&emsp; **b** &emsp;Converts the argument to an unsigned binary

##### Example:

&emsp; \_printf("20 in binary is: %b", 20);

##### Expected output:

&emsp; 20 in binary is: 10100

&emsp; **c** &emsp;Converts the value of an int (see ASCII table) into a character

##### Example:

&emsp; \_printf("The initial of my name is: %c", 'N'); <- Just 78 also works

##### Expected output:

&emsp; The initial of my name is: N

&emsp; **s** &emsp;Takes a pointer to an array of characters (a string, excluding the '\0' (null char))

##### Example:

&emsp; \_printf("My name is: %s", "Nacho");

##### Expected output:

&emsp; My name is: Nacho

&emsp; **p** &emsp;Takes an address as a parameters and prints it in hexadecimal

##### Example:

&emsp; char \*pointer = "pointer";

&emsp; \_printf("The address of my %s is: %p", pointer, &ptr);

##### Expected output:

&emsp; The address of my pointer is: 0x7fff55dc8440 (random address value in hex value)

&emsp; **r** &emsp;Takes a pointer to an array of characters (a string) and prints it in reverse

##### Example:

&emsp; \_printf("My name in reverse is: %r", "Nacho");

##### Expected output:

&emsp; My name in reverse is: ohcaN

&emsp; **R** &emsp;Takes a pointer to an array of characters (a string) and converts it to Rot13

##### Example:

&emsp; \_printf("My name in rot13 is: %R", "Nacho");

##### Expected output:

&emsp; My name in rot13 is: Anpub

&emsp; **S** &emsp;Takes a pointer to an array of characters (a string) but print the value of non-printable chars in hex

##### Example:

&emsp; \_printf("%S", "The value of \\n is \n");

##### Expected output:

&emsp; The value of \n is \x0A

### RETURN VALUE

&emsp; The value of the return is the amount of characters printed excluding the null char

&emsp; For example: int rvalue = \_printf("Hello"); \
Output: Hello\
&emsp; \_printf("rvalue is: %d", rvalue);\
Output: rvalue is: 4

## Flowchart

![App Screenshot](https://i.postimg.cc/KvVjgKvs/Flowchart-about-printf.png)
