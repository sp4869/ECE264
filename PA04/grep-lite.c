#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
int main(int argc ,char ** argv)

{
  int quiet = FALSE;// -q
  int invert = FALSE;// -v
  int line_num = FALSE;//-n
  int i;
  char * a = "--help";
 
  for(i = 0;i < argc;i++)
   { 
     if(strcmp(argv[i],a)== 0)
      {
        printf("Usage: grep-lite [OPTION]... PATTERN\n");
	printf("Search for PATTERN in standard input. PATTERN is a\n");
	printf("string. grep-lite will search standard input line by\n");
	printf("line, and (by default) print out those lines which\n");
	printf("contain pattern as a substring.\n");
  	printf("  -v, --invert-match     print non-matching lines\n");
  	printf("  -n, --line-number      print line numbers with output\n");
  	printf("  -q, --quiet            suppress all output\n");
	printf("Exit status is 0 if any line is selected, 1 otherwise;\n");
	printf("if any error occurs, then the exit status is 2.\n");
	return EXIT_SUCCESS;
      }
   }
   if(argv[argc - 1][0] == '-')//check to see if the pattern starts with a '-'
   {
	fprintf(stderr,"Error\n");
        return 2;
   }
   int j;
   for(j = 1;j < argc - 1;j++)// do not check the pattern,so check argc - 1.
   {
    
       if(strcmp(argv[j],"-v") == 0 || strcmp(argv[j],"--invert-match")== 0)
       {
         invert = TRUE;
       }
       if(strcmp(argv[j],"-q")== 0 || strcmp(argv[j],"--quiet")== 0)
       {
         quiet = TRUE;
         return 1;
       }
       if(strcmp(argv[j],"-n")== 0 || strcmp(argv[j],"--line-number")== 0)
       {
         line_num = TRUE;
       }
  
   }
   
   int c = 1;   
   char arr[2010];// array of size 2010.
   char * b;
   FILE * fp = stdin;// pointer to string typed in terminal
   int q = 1;// Assume that there are no matching lines.
   while(fgets(arr,2000,fp)!= NULL)// checks the line if its null
   {
    b = strstr(arr,argv[argc - 1]);//returns a pointer to the matching string. Searches for the pattern in stdin.  
    if (b != NULL)// there is match between pattern and stdin.
      {
         q = 0;// if there is matching line then q must be set to 0.
        if(quiet == FALSE)
        {
          if(line_num == TRUE)
         { 
           printf("%d:",c);
         }
          
          printf("%s",arr);
        }
      }
   else// did not find a pattern
   {
     if(quiet == FALSE)
     {
          if(invert == TRUE)
          {
             printf("%s",arr);
          }
     }
  }
    c++;
  }
  return q;
}  
//How to incorporate -v,-Q on the same line,will exit status be 0,what has the hgher preference      