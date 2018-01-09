#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer06.h"


int compar(const char * a,const char * b)
{
   if((a == NULL) || (b == NULL))
   {
     return 1;
    }
 return strcmp(a,b);
}


int main(int argc,char ** argv)
{
  const char  str[10] = "B";
  const char  str2[10] = "g";
//  const char  str3[10] = "X";
//  const char  str4[10] = "L";
  int i = 1;
  List * lhs =  NULL;
  List * head = NULL;
  List * rhs = NULL;
  List * temp = NULL;
  lhs = List_createNode(str);
  temp = lhs;
  rhs = List_createNode(str2);
  head = rhs;
  while(i < 2 )
  {
     temp->next  = List_createNode(str2);//&str[i]
     head->next = List_createNode(str);
     temp = temp->next;
     head = head->next;
     temp->next = NULL;
     head->next = NULL;
     i++;
  }       
   

   lhs = List_sort(lhs,compar);
   rhs = List_sort(rhs,compar);
   head = List_merge(lhs,rhs,compar);
//   List_destroy(head);
  while(head != NULL)
   {
     printf("%s ",(head->str));
     head = head->next;
   }

     printf("\n");
   return EXIT_SUCCESS;
}     



