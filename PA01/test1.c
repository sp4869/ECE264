#include<stdio.h>
#include<stdlib.h>

int main(int argc,char ** argv)
{
 char * str = "Hello";
 int i;
 i = 0;
 while(str[i] != '\0')
  {
    printf("String = %s\n",str[i]);
    i++;
  }
 return EXIT_SUCCESS;
}    
