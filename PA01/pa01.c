#include <stdio.h>
#include <stdlib.h>

// The line below includes the /definitions/ of the functions that you write
// in this assignment. Including the definitions allows you to use
// the functions in this file.
#include "answer01.h"

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
	printf("%d", array[ind]);
	if(ind != len - 1) {
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to 
    // include this line to ensure that our output is immediately
    // printed out output.
    fflush(stdout); 
}


void printArray_1(const int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
        printf("%d", array[ind]);
        if(ind != len - 1) {
            printf(", ");
        }
    }
    printf("}");
    // If we don't include a '\n' character, then we need to
    // include this line to ensure that our output is immediately
    // printed out output.
    fflush(stdout);
}


void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". sum = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[] = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    // You can add more test-cases here
    int array3[] = {10,20,-30,40,-50};
    int len3 = 5;
    int expected3 = -10;
    test_arraySum(array3,len3,expected3);

    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len); 
    printf(". count = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}

void test_01_arrayCountNegative()
{
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    // You can add more test-cases here
    // ...

    printf("\n");
}

void test_arrayIsIncreasing(int * array, int len, int expected)
{
    printArray(array, len);
    int result;
    result = arrayIsIncreasing(array, len);
    printf(". result = %d, expected = %d.", result, expected);
    if(result != expected)
        printf(" FAIL");
    printf("\n");
}

void test_02_arrayincreasing()
{
  printf("Testing arrayisIncreasing(...)\n");

  int array1[] = { -3,-1,4,2,0 };
  int len1 = 5;
  test_arrayIsIncreasing(array1,len1,0);
  
  int array2[] = { -8,-9,4,2,0 };
  int len2 = 5;
  test_arrayIsIncreasing(array2,len2,0);
  
  int array3[] = { 27,17,4,2,0 };
  int len3 = 5;
  test_arrayIsIncreasing(array3,len3,0);
  
  int array4[] = { -103,-104,4,2,0 };
  int len4 = 5;
  test_arrayIsIncreasing(array4,len4,0);

  int array5[] = {};
  int len5 = 0;
  test_arrayIsIncreasing(array5,len5,1);

  
  printf("\n");

}

void test_arrayindexfind(int needle, const int * haystack, int len,int expected)
{
    printArray_1(haystack,len);
    int result;
    result = arrayIndexFind(needle,haystack,len);
    printf(". Answer = %d, expected = %d.", result, expected);
    if(result != expected)
        printf(" FAIL");
    printf("\n");
}


void test_03_arrayindexfind()

{
  printf("Testing arrayindexfind(...)\n");

  int array1[] = { -3,-1,4,2,0 };
  int len1 = 5;
  test_arrayindexfind(-3,array1,len1,0);

  int array2[] = { -8,-9,4,2,0 };
  int len2 = 5;
  test_arrayindexfind(-9,array2,len2,1);

  int array3[] = { 27,17,4,2,0 };
  int len3 = 5;
  test_arrayindexfind(4,array3,len3,2);

  int array4[] = { -103,-104,4,2,0 };
  int len4 = 5;
  test_arrayindexfind(2,array4,len4,3);

  int array5[] = {};
  int len5 = 0;
  test_arrayindexfind(1,array5,len5,-1);


  printf("\n");

}


void test_arrayfindsmallest(int * array, int len, int expected)
{
    printArray(array, len);
    int result;
    result = arrayFindSmallest(array, len);
    printf(". result = %d, expected = %d.", result, expected);
    if(result != expected)
        printf(" FAIL");
    printf("\n");
}


void test_04_arrayfindsmallest()
{
  printf("Testing arrayfindsmallest(...)\n");

  int array1[] = { -3,-1,4,2,0 };
  int len1 = 5;
  test_arrayfindsmallest(array1,len1,0);

  int array2[] = { -8,-9,4,2,0 };
  int len2 = 5;
  test_arrayfindsmallest(array2,len2,1);

  int array3[] = { 27,17,4,0,0 };
  int len3 = 5;
  test_arrayfindsmallest(array3,len3,3);

  int array4[] = {-104,-104,4,2,-104 };
  int len4 = 5;
  test_arrayfindsmallest(array4,len4,0);

  int array5[] = {};
  int len5 = 0;
  test_arrayfindsmallest(array5,len5,0);


  printf("\n");

}



int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n\n");

    // Uncomment to run two example (incomplete) testcases.
    test_00_arraySum();
    test_01_arrayCountNegative();
    test_02_arrayincreasing();
    test_03_arrayindexfind();
    test_04_arrayfindsmallest();	
	//If you write any additional test functions, you can call them below

    return EXIT_SUCCESS;
}


