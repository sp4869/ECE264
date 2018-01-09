#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This does not work. You will need to fix it.
// Hint: look up swap(int *, int *) in the textbook
void swapString(char ** a, char ** b)
{
    // passing &str1 is passin the adddress of the pointer.
    // so char ** has to be used. 
    // tmp = *a, *a equals the address of first letter of str1.
   // so switching the address of 'o' and 'T' is carried out.
   // 
    char * tmp = "Three";
    tmp = *a; //Interchanging the pointer
    *a = *b;
    *b = tmp;
    printf("Calling swapString(...)\n");
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&tmp = %p\n", &tmp);
}

int main(int argc, char * * argv)
{
    printf("Welcome to PA03.\n"
	   "\n"
	   "Please make sure that the swapString(...) function works\n"
	   "\n");
    
    printf("Print out some memory addresses for argc, argv...\n"
	   "to illustrate how memory is laid out.\n");
    printf("&argc = %p\n", &argc);
    printf("&argv = %p\n", &argv);
    printf("argv = %p\n", argv);
    printf("*argv = %p\n", *argv);
    printf("*argv = %s\n", *argv);
    printf("**argv = %c\n", **argv);

    // Let's create our own array of strings
    printf("\nTesting swapString(...)\n");
     char * str1 = "one";
     char * str2 = "two";
    printf("Before swap, str1 == %p (i.e., '%s'), "
	   "str2 == %p (i.e., '%s')\n", str1, str1, str2, str2);
    swapString(&str1, &str2);
    printf("After swap, str1 == %p (i.e., '%s'), "
	   "str2 == %p (i.e., '%s')\n", str1, str1, str2, str2);

    return EXIT_SUCCESS;
}
