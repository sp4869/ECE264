#include<stdlib.h>
#include "answer03.h"
#include<stdio.h>
#include <string.h>
int main(int argc,char ** argv)

{
  int a;
  int i;
  int g;
  char * n;
  char * b = "Hello";
  int f;
  f = strlen(b);
  char * s;
//  s  = malloc(sizeof(char) * f);
//  for (a = 0;b[a] != '\0';a++)
//      { 
//         s[a] = b[a];
//      }
  char * c = "d,c,b,e,a"; 
  char * d = ",";
  const char * s2 = "Zippy";
  char * first; 
 // first = strcat_ex(&s,&f,s2);
//  printf("Result = %s\n",first);
  char ** test = explode(c,d,&g);
  printf("new_g = %d\n",g);
 // n = implode(test,g,d);
 // printf("n = %s\n",n);
  char * str_2 = strdup("Rochak");
   sortStringCharacters(str_2);
  printf("Answer = %s\n",str_2);
/*  destroyStringArray(test,g);
  for (i = 0;i < g;i++)
 {
   printf("answer = %s\n",test[i]);
 }
*/ 
  sortStringArray(test,g);
 for (i = 0;i < g;i++)
  {
    printf("answer = %s\n",test[i]);
  }
 
//  free(first);
  for(i = 0;i < g;i++)
    {
      free(test[i]);
    }
  free(test);
//  free(n);
  free(str_2);

  return EXIT_SUCCESS;
}
