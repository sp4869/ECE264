#include<stdlib.h>
#include "answer03.h"
#include<string.h>

char * strcat_ex(char ** dest,int * n, const char * src)
 {   
     if (*dest == NULL)
	{
  	  *n = (2 * strlen(src) + 1);
          *dest = malloc(*n * sizeof(char));
          strcat(*dest,src);
          return(*dest);
        }	
     if ( strlen(src) + strlen(*dest) + 1 > *n )// so then create a buffer and allocate memory
	{
          char * buffer = malloc(( (2 * (strlen(src) + strlen(*dest))) + 1) * sizeof(char));
          *n = (1 + 2 * (strlen(src) + strlen(*dest))) * sizeof(char);
          strcpy(buffer,*dest);//copy contents of dest into buffer
          free(*dest);//free memory after use
          *dest = buffer;
          strcat(*dest,src);//run strcat which will append the str into dest              
        } 
     else
        {
          strcat(*dest,src);
          
        } 
   
  return(*dest);
}
 

char ** explode(const char * str,const char * delims,int * arrLen)

{
  int i;
  int x;
  x = 0;//used to calculate number of delimiters which match the string.
  // Find the number of delimiter characters which appear in the string str.
  for ( i = 0; str[i] != '\0';i++)
	{

  	   if (strchr(delims,str[i])!= NULL)
       	    {
               x++;
             }
        }   
 
  //printf("x = %d\n",x); 
  char ** strArr;//create a new string array. it has to be a 2d array because there are rows and columns
  strArr = malloc((x + 1) * sizeof(char *));//Space allocated should be n + 1 characters times char *.
  for (i = 0;i < x + 1;i++)
     {
       strArr[i] = malloc(x + 1 * sizeof(char*));
     }    
  int last;//points to i + 1;
  last = 0;//initialize value to 0
  int arrInd = 0;//new string
  for (i = 0;str[i] != '\0';i++)
   {
      if (strchr(delims,str[i]) != NULL)
       	    {
              
               int difference ;
               difference = i - last ;
               char new_string[difference];
               int j;
               for( j = 0; j < difference;j++)
                {
                   new_string[j] = str[last];
                   last++;
                }
		new_string[difference] = '\0';
                strcpy(strArr[arrInd],new_string); 
                last = i + 1;
                arrInd++;
             }
   }
  int d;
  int e = strlen(str) - last;
  char new_string2[e];
  for( d = 0; d < e;d++)
      {
         new_string2[d] = str[last];
         last++;
      }
  new_string2[e] = '\0';
  strcpy(strArr[arrInd],new_string2);
  *arrLen = x + 1;   
//  int c;
 // for(c = 0;c < x + 1;c++)
 //   {
  //    free(strArr[c]);
//    }
  
  return(strArr); 
}
     
char * implode(char ** strArr,int len,const char * glue)
{
  int i;
  int d = 0;
  char * new_string;
  char * update_string;
  char * buffer = malloc(sizeof(char));
  int h = 0;
//  printf("Len = %d\n",len);
//  int c;
//  for(c = 0;c < len;c++)
//    {
//  	printf("strArr = %s\n",strArr[c]);
//    }
   for (i = 0;i < len;i++)   
    {  
     if ( i == len - 1)
      { 
       update_string = strcat_ex(&buffer,&h,strArr[len - 1]);
       return(update_string);
      }
     d = strlen(strArr[i]); 
     new_string = strcat_ex(&strArr[i],&d,glue);
     update_string = strcat_ex(&buffer,&h,new_string);
    }
  free(buffer);
  return(update_string);
 }
 
int compar(const void * a, const void * b)
{
  const char * u = *(const char **) a;
  const char * v = *(const char **) b;
  return strcmp(u,v);
  
}


void sortStringArray(char ** arrstring,int len)
{
  qsort(arrstring,(size_t) len, (size_t)sizeof(char*),compar) ;

}
 
 
int compar_2(const void * a,const void * b)
{
 const char * u =   (char*) a;
 const char * v =   (char*) b;
 return *u - *v; 

}

void sortStringCharacters(char * str)
{
 qsort(str,(size_t)strlen(str),(size_t)sizeof(char),compar_2);

}

void destroyStringArray(char * * strArr, int len)
{
 int i;
    for (i = 0;(strArr[i] != '\0' && i < len);i++)
    {
        free(strArr[i]);
    }
  
 free(strArr);
}
  


