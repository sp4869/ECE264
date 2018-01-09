#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer07.h"

char ** explode(const char * str,const char * delims,int * arrLen);


BusinessNode * create_node(char * stars,char * name,char * address)
{
  BusinessNode * head = NULL;
  head = malloc(sizeof(BusinessNode));
  head -> name = name;
  head -> stars = stars;
  head -> address = address;
  head -> left = NULL;
  head -> right = NULL;
  return head;
}

BusinessNode * tree_insert(BusinessNode * node,BusinessNode * root)
{

  if (root == NULL)
  {
    return node;
  }
 
  //order the nodes on the basis of the BusinessNode name.
 
  if(strcmp(root->name,node->name) >= 0)//the node should be placed to the left of the root.
    {
           if (root->left == NULL)//if there is no node there,place the node.  
         {
	  root->left = node;
           return root;
	 }
	   else  //if a node present,then we should determine if the new node is greater or less than the currrent node.
         {
           tree_insert(node,root->left);
         }  
      }     
   else     
      {
          if(root->right == NULL)
          {
             root->right = node;
             return root;
	     }
          else
          { 
             tree_insert(node,root->right);
          } 
      }
  return root;
}


BusinessNode * tree_search_name(char * name,BusinessNode * root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if(strcmp(root->name,name) == 0)
   {
     return root;
   }
  else
   {
     if(strcmp(root->name,name) > 0 )
     {
      return(tree_search_name(name,root->left));
      
     }
     else
     {
      return(tree_search_name(name,root->right));
     }
    }
  return root;
}

void destroy_tree(BusinessNode * root)
{
  if(root != NULL)
  { 
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root -> name);
    free(root -> address);
    free(root-> stars);
    free(root); 
  }
   
}
BusinessNode * load_tree_from_file(char * filename)
{
  return NULL;
}
 
/*BusinessNode * load_tree_from_file(char * filename)
{
   BusinessNode * node = NULL;
   BusinessNode * temp = NULL;
   char ** str;//used to call explode
   int ch;//used to get fgetc
   char line[2000];
   int i = 0;
   const char * delim = "\t";
   int x;
   FILE * fptr = NULL;
   fptr = fopen(filename,"r");
   if(fptr == NULL)
     {
       return NULL;
     }
   while(!feof(fptr))
      {

           ch = fgetc(fptr); 
            if (ch != EOF)
            {
	      // printf("%s",line);
                if(ch != '\n')
                {
                   line[i] = ch;  
                   i++;
                }
                
                else
                {
                   line[i] = '\0';
                   i = 0;
                   str = explode((const char *)line,delim,&x);
                   node =  create_node(str[0],str[1],str[2]);
		   //  for (x = 0; x < 3;x++){
		   //  printf("%s\n", str[x]);
		   //   }
		   //   printf("%s\n", line);
		   free(str);
                   temp = tree_insert(node,temp);                        
                }
             }  
      }
   fclose(fptr);
   return temp;
}
*/
 
/* char ** explode(const char * str,const char * delims,int * arrLen)

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
       strArr[i] = malloc((strlen(str)+1) * sizeof(char));
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
*/
