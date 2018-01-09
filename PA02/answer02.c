#include <stdlib.h>
#include "answer02.h"

char * my_strcat(char * dest, const char * src)
{
	int i;
	i = 0;
	int j;
    //int count_src;
    int count_dest;
    //count_src = my_strlen(src);
    count_dest = my_strlen(dest);
    if (count_dest == 0)
    {
        dest[i] = '\0';
    }    
    for (j = count_dest; dest[j] == '\0';j++)
        {
            if (src[i] != '\0')
            {
                dest[j] = src[i] ;
                i++;
                dest[j + 1] = '\0';
            }
            else 
            {
                return(char *)dest;
            }
        }
    
    return (char *)dest;

}

char * my_strcpy(char * dest, const char * src)
{
    int i;
    int count;
    count = my_strlen(src);
    if (src == NULL )
    {
        return (char *)dest;
    }
    else if (count == 0)
    {
        i = 0;
        dest[i] = '\0';
    }    
    for (i = 0; src[i] != '\0';i++)
        {
            dest[i] = src[i];
        }
    dest[i] = '\0';
    return (char *)dest;
}


char * my_strchr(const char * str, int ch)

{   
    int i;
    if (ch !='\0')
    {
        for(i=0;str[i] != '\0';i++)
        {
            if(str[i] == (char) ch)
            {
              return (char *)str + i;
            }
        
        }
    
        return(NULL); 
    }
    
    else
    {
        i = 0;
        while(str[i] !='\0')
        {
          i++;
        }
    }
    return (char *)str + i;
}


int my_countchar(const char * str, char ch)
{
    int count;
    count = 0;
    int i;
    for (i = 0;str[i] != '\0';i++)
        {
            if (str[i] == ch)
            {
               count++;
            }
        }        
    return (count);
}


size_t my_strlen(const char * str)
{
    int count;
    int i;
    count = 0;
    for (i = 0;str[i] != '\0';i++)
         {
            count = count + 1;
         }         
	return (count);
}

char * my_strrchr(const char * str, int ch)
{
    int j;
    int i;
    int count ;
    count = my_strlen(str);
    i = 0;
    if (ch !='\0')
    {
        for(j = count - 1 ;str[j] != '\0';j--)
            {
               if(str[j] == (char)ch)
               {
                    return (char *)str + j;
               }
            }
        return(NULL); 
    }
    
    else
    {
        while(str[i] !='\0')
        {
          i++;
        }
    }
    return (char *)str + i;
}


char * my_strstr(const char * haystack, const char * needle)
{
    int i;
    int j;
    j = 0;
    i = 0;
    int count_haystack;
    int count_needle;
    count_haystack = (int)my_strlen(haystack);
    count_needle = (int)my_strlen( needle);
    if (count_needle == 0)
    {
        return(char *)haystack;
    }
    
    while (j < count_haystack)
    {
        
           while((i + j < count_haystack) && (haystack[i + j] == needle[i]) && (needle[i] != '\0'))
                   {
                      
                      i++;
                      
                   }

        if ( i == count_needle)
        {
            return(char *)(haystack + j);
        }
        j++;
    }
	return NULL;
}





int my_isspace(int ch)
{
    char i;
    i = (char) ch;
    
    if((i == ' ') || (i == '\f') || (i == '\n') || (i == '\r') || (i == '\t') || (i == '\v'))
        {
            ch = 1;
        }
        
        else
        
        {
            ch= 0;
    
        }    
    
    return ch;
}

int my_atoi(const char * str)
{
    int j;
    int a;
    a = 0;
    int ret;
    ret = 0;
    j = 0;
    while((str[j] != '\0') &&  (my_isspace(str[j])== 1))
    {
        j++;
    }
    if(str[j] == '-')
        {   
            if ((str[j + 1] <= '0') && ((str[j + 1]) >= '9'))
            {
                return 0;
            }
            a = 1;
            j++;
        }
    if(str[j] == '+')
    {
        if ((str[j + 1] <= '0') && (str[j + 1] >= '9'))
            {
                return 0;
            }
        j++;
    }
    
    while ((str[j] >= '0') && (str[j] <= '9'))  
        {
            ret  *= 10;
            ret += (str[j] - '0');
            j++;
        }
    if (a == 1)
    {
        return (-ret);
    }
    
    return(ret);
    
}
