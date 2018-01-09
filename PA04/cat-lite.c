#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc ,char ** argv)
{
  // argc is the numebr of arguments,while argv refers to the argument.
  // All arguments are treated as file names. 
  int i;
  int j;
  char * a = "--help";
  char ch;
  FILE * fp;//file pointer.
  for(i = 0;i < argc;i++)
    {
      if (strcmp(argv[i],a)== 0)//comapres the argument to help returns 0 if they match.
     {
     printf("Usage: cat-lite [--help] [FILE]...\n"); 
     printf("With no FILE, or when FILE is -, read standard input (can exit with CTRL\n");
     printf("+D, play around with ""cat"" to\n"); 
     printf("get a sense of how this works).\n");
     printf("\n");
     printf("Examples:\n");
     printf("  cat-lite README   Print the file README to standard output.\n");
     printf("  cat-lite f - g    Print f's contents, then standard input,\n"); 
     printf("                    then g's contents.\n");
     printf("  cat-lite          Copy standard input to standard output.\n");
     return EXIT_SUCCESS;
     }  
   }
   
   if (argc == 1)
   {
      while(!feof(stdin))//as long as its not the end of the file
             {
                ch = fgetc(stdin);// points to the next charactersget the characters from stdin
                if(ch != EOF)
                {
                   fputc(ch,stdout);//will write the character to stdout.ctrl + d to exit the stdin and the rest of the code should execute.

                } 
             }
   }
   
   for (j = 1; j < argc;j++)
   {
        
	if(strcmp(argv[j],"-") == 0)//if the argument is '-' 
        {
             while(!feof(stdin))//as long as its not the end of the file
             {
                ch = fgetc(stdin);// points to the next charactersget the characters from stdin
                if(ch != EOF)
                {
                   fputc(ch,stdout);//will write the character to stdout.ctrl + d to exit the stdin and the rest of the code should execute.
		
	        }  
             }
        }
	else{
		fp = fopen(argv[j],"r");//opens the file and reads
       		// fprintf(stdout,fgetc(FILE*fp));
       
		
        	if(fp == NULL)
           	{
             		fprintf(stderr,"cat cannot open %s\n",argv[j]);
            		return EXIT_FAILURE;
           	}
         	else
           	{
             		while(!feof(fp))// as long as it is not the end of the file
               		{
		 		ch = fgetc(fp);//get the character
                 		if (ch != EOF)
                 		{
                    		   fputc(ch,stdout);//writes the character on stdout.
                	 	}

             		}  
           		fclose(fp);
		}
              
           }
      }
           
return EXIT_SUCCESS;
}
 

