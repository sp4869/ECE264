#include <stdlib.h>
#include "answer01.h"
#include <stdio.h>

int arraySum(int * array, int len)
{
 int sum_elements;
    sum_elements = 0;
    int i;// for loop will add the elements and return the sum.
    for (i = 0;i < len; i++)
    {
       sum_elements = sum_elements + array[i];
        
    }    
    return (sum_elements); 
}

int arrayCountNegative(int * array, int len)
{
  int count_elements;
	count_elements = 0;
	int i;//For every element below 0,the count will get updated.
	for (i = 0;i < len;i++)
	{
	    if (array[i] < 0)
	    {
	       count_elements = count_elements + 1;
	    }
	    
	}
	return (count_elements); //the count will be returned.
}

int arrayIsIncreasing(int * array, int len)
{
        int count_increase;
	count_increase = 0;
	int i;
	if ((len <= 0)||(len == 1))//if the length is 0 or 1 the following value is returned.
	    {
	        count_increase = 1;
	    }  
	else
	  {
	    for (i = 0;i < len - 1; i++)// the loop will check if the succeeding element is greater than the preceding one.
	      {
		if (array[i + 1] >= array[i])
		  {
		    count_increase = 1;
		  }
		else
		  {
		    count_increase = 0;
		    i = len;
		  } 
	      }
	  }
        return(count_increase);
}


int arrayIndexFind(int needle, const int * haystack, int len)
{
   int index_value;
   index_value = -1;
   int i;
   if (len == 0)
   {
       index_value = -1;
   }
   for (i = 0;i < len;i++)// if the value exists in the array the index value is returned. Else -1 is returned.
    {   
        if (haystack[i] == needle)
        {
            index_value = i;
        }
    }
    
    return (index_value);
}


int arrayFindSmallest(int * array, int len)
{
    int index_value;// delcare index value
    int smallest_element;// smallest element
    index_value = 0;
    int i;
    if ((len == 0)||(len == 1))
    {
        return(index_value);
    }
    else
    {
      smallest_element = array[0];// the smallest element is assumed to be the first element.
      for (i = len-1;i>= 0;i--)//the value of starts at (length -1),so the last value is comapred to the first one.
       {
	 if (array[i] <= smallest_element)//if the if statement holds good,the smallest element is assigned to this index.
          {
            smallest_element = array[i];
            index_value = i ;
          }
       }
        
    }
    
    return (index_value);//the index value of the smallest element is returned.
}

