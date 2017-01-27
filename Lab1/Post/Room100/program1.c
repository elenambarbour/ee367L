/*
This is a program will compile but with warnings
because a function is defined after it is called and
there is no prototype.
*/

main()
{
hello();
}


void hello()
{
printf("Hello world\n");
}

