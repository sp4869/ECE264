#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc ,char ** argv)
{
  int i;
  char ch;
  FILE * fp;
  for(i = 1;i < argc;i++)
  {
     fp = fopen(argv[i],"r");
     if(fp != NULL)
     {
       while(!feof(fp))
       {
           ch = fgetc(fp);
           if(ch != EOF)
           {
             fputc(ch,stdout);
           }
       }
       fclose(fp);
     }
  }  
 
   return EXIT_SUCCESS;
}
