#include<string.h>
#include <stdio.h>
#include<stdlib.h>
int main(int argc,char ** argv)
{
  int i;
  for(i = 1; i < argc;i++)// argc will be the inputs on the command line not including ./example,argv is ./example.
   {
     printf("%s ",argv[i]);// Arguments should start from the first,so i = 1,also arguments must not count spaces.
   }//give a space after '%s ' so that there is space before the next word. 
  
   printf("\n");// makes sure that bash starts on the next line. 
   return EXIT_SUCCESS;
}
