#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#define  MAXLENGTH 8
static  void  printPartition(int * arr , int  len)
{
  int ind;
  printf("= ");
  for(ind = 0;ind < len - 1;ind++)
  {
    printf("%d + ",arr[ind]);
  }
  printf("%d\n", arr[len - 1]);
}

static void partitionHelper(int value,int * arr,int ind)
{
  if(value == 0)
  {
    printPartition(arr,ind);
    return;
  }
 int nextVal;
 for(nextVal = 1; nextVal <= value;nextVal++)
   {
     arr[ind] = nextVal;
     partitionHelper(value - nextVal,arr,ind + 1);
   }
}

void partition(int value)
{
  printf("partiton %d\n",value);
 int arr[MAXLENGTH];
 partitionHelper(value,arr,0);
}

int main(int argc,char ** argv)
{
  int val;
  for(val = 1;val <= MAXLENGTH;val++)
  {
    partition(val);
  }
 return EXIT_SUCCESS;
}
