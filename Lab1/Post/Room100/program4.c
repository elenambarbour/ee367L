/*
This is a program will compile perfectly even
though the function is defined after it is called
because there is a prototype.  The prototype is
in the header file.
*/

#include  "example.h" // header file

main()
{
hello();
}

void hello()
{
printf("Hello world\n");
}

