#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answer05.h"

#define FALSE 0
#define TRUE 1

Image * Image_load(const char * filename)
{
	FILE * fp = NULL;
	size_t read;
	ImageHeader header;
	Image * tmp_im = NULL,* im = NULL;
	int err = FALSE;

	if(!err)
	{ // Open filename
		fp = fopen(filename, "rb");
		if(!fp)
		{
			printf( "Failed to open file '%s'\n", filename);
			err = TRUE;
		}
	}

	if(!err)
	{ // Read the header
		read = fread(&header, sizeof(ImageHeader), 1, fp);
		if(read != 1)
		{
			printf( "Failed to read header from '%s'\n", filename);
			err = TRUE;
		}
	}

	if(!err)
	{
		if(header.magic_number != ECE264_IMAGE_MAGIC_NUMBER)
		{
			fprintf(stderr,"The magic number in the header is incorrect\n");
			err = TRUE;
		}
	}

	if(!err)
	{
		if(header.width <= 0)
		{
			fprintf(stderr,"Incorrect width and height\n");
			err = TRUE;
                      //  fclose(fp);
                      //  return NULL;
		}
	}

	if(!err)
	{
		if(header.height <= 0)
		{
			fprintf(stderr,"Incorrect heigth\n");
			err = TRUE;
                    //    fclose(fp);
                    //    return NULL;
		}
	}

	if(!err)
	{
		if(header.comment_len == 0)
		{
			fprintf(stderr,"Incorrect comment length\n");
			err = TRUE;
                   //     fclose(fp);
		}  //     return NULL;  
	}

	int a;
	a = header.width * header.height;
	if(!err)
	{ // Allocate Image struct
		tmp_im = malloc(sizeof(Image));
		if(tmp_im == NULL) 
		{
			printf( "Failed to allocate im structure\n");
			err = TRUE;
                        free(tmp_im);
                        fclose(fp);
                        return NULL;
		} 

		tmp_im->comment = malloc(sizeof(char) * header.comment_len); 
                tmp_im -> data = malloc(sizeof(uint8_t) * a);
                if(tmp_im->comment == NULL || tmp_im->data == NULL)
                {
                  free(tmp_im->comment);                
                  free(tmp_im->data);             
                  free(tmp_im);
                  fclose(fp);
                  return NULL; 
	        }
        }

	if(!err)
	{
		read = fread(tmp_im->comment,sizeof(char),header.comment_len,fp);
		if(read != header.comment_len)
		{
			printf( "Failed to read header from '%s'\n", filename);
			err = TRUE;
                        free(tmp_im->comment);
                        free(tmp_im->data);
                        free(tmp_im);
                        if(fp)
                        {
                          fclose(fp);
                        }
                        return NULL;
		}
	}

	if(!err)
	{
		if(tmp_im->comment[header.comment_len- 1] != '\0') //becasue comment_len includes null byte in its length
		{
			err = TRUE;
                        free(tmp_im->comment);
                //        free(tmp_im->data);
                //        free(tmp_im);
                        if(fp)
                        {
                          fclose(fp);
                        }
                        return NULL;

		}
	}

	if(!err)
	{
		read= fread(tmp_im->data,sizeof(char),a,fp);
		if(read != a)
		{
			err = TRUE;
                        printf("Cant read\n");
                        free(tmp_im->comment);
                        free(tmp_im->data);
                        free(tmp_im);
                        if(fp)
                        {
                          fclose(fp);
                        }
                        return NULL;

		}
                
	}

	char test[1];
	if(!err)
	{
		read = fread(test,sizeof(char),1,fp);
		if(read != 0)
		{
			err = TRUE;
		}
	}

	if(!err)
	{ // Init the Image struct
		tmp_im->width = header.width;
		tmp_im->height = header.height;
	}

	if(!err)
	{ // We're winners... 
		im = tmp_im;  // bmp will be returned
		tmp_im = NULL; // and not cleaned up
	}

	if(tmp_im != NULL)
	{
		free(tmp_im->comment); // Remember, you can always free(NULL)
		free(tmp_im->data);
		free(tmp_im);
	}
	if(fp)
	{
		fclose(fp);
	}   	    	    	                	            
	return im;
}
void linearNormalization(int width, int height, uint8_t * intensity)
{
   int min = intensity[0];  // Assume min is the first data point.
   int max = intensity[0];  //Assume max is the first data point.
   int i = 1;
   int j;
   int a  = width * height;
   while(i < a)
   {
       if(min > intensity[i])   //if the minimum is greater than this point,assume that value to be new minimum. 
       {
           min = intensity[i];
       }
      
       if (max < intensity[i])  //if the max is less than this value,this becomes the new max.
       {
           max = intensity[i];
       }
       
     i++;
        
   }
   
   for(j = 0; j < a;j++) //scaling all the data points using the max and min found.
   {
       intensity[j] = (intensity[j] - min) * 255.0  / (max - min);
   	
   }
	    
}	

int Image_save(const char * filename, Image * image)
{
   int err;
   err = FALSE;
   size_t read;
   FILE * fp = NULL;
   fp = fopen(filename, "wb");
    if(fp == NULL) 
    {
	    printf( "Failed to open '%s' for writing\n", filename);
	    return FALSE; // No file ==> out of here.
    }
    
   ImageHeader header;
   header.magic_number = 0x21343632;
   header.width = image->width;
   header.height = image->height;
   header.comment_len = strlen(image->comment) + 1;
   int a = header.height * header.width;
    
   if(!err)
    { // Read the header
 	    read = fwrite(&header, sizeof(ImageHeader), 1, fp);
 	    if(read != 1)
 	    {
 	        printf( "Failed to read header from '%s'\n", filename);
 	        err = TRUE;
 	    }
    }       
   
    if(!err)
    {
        read = fwrite(image->comment,sizeof(char),header.comment_len,fp);
        if(read != header.comment_len)
        {
            printf( "Failed to read header from '%s'\n", filename);
            err = TRUE;
        }
    }
    
    if(!err)
    {
        read= fwrite(image->data,sizeof(char),a,fp);
        if(read != a)
        {
          err = TRUE;
        }
    }
    
    if(fp)
    {
	    fclose(fp);
    }
    
    return (!err);
    
}

void Image_free(Image * image)
{
     if(image != NULL)
   { 
     free(image->comment);
     free(image-> data);
     free(image);
   }

}
         	    	    	                	                
