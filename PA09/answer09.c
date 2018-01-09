#include "answer09.h"

/* This function has been completed for you */

Node * Node_construct(int val, int ind)
{
	Node * nd = calloc(1,sizeof(Node));
	nd->next = NULL;
	nd->value = val;
	nd->index = ind;
	
	return nd;
}

/* This function has been completed for you */

static Node * List_insertHelper(Node * head , int val, int ind)
{
	if(head == NULL)
	{
		return Node_construct(val,ind);
	}
	head-> next = List_insertHelper(head->next,val,ind+1);
	return head;
}

/* This function has been completed for you */

Node * List_insert ( Node * head , int val)
{
	return List_insertHelper(head,val,0);
} 

/* This function has been completed for you */

void List_destroy ( Node * head )
{
	if(head==NULL) return;
	List_destroy(head->next);
	free(head);
}

/* This function has been completed for you */

void List_print(Node * head)
{
	while(head !=NULL)
	{
		printf("[%d]:%d ",head->index,head->value);
		head = head->next;
	}
	printf("\n");
}

int List_length(Node * head)
{
   Node * temp = head;
   int i = 0;
   while(temp != NULL)
  {
    temp = temp->next;
    i++;
  }
   return i; 	
}	
  

int List_swap(Node * head, int index1, int index2)
{
      Node * temp = head;
      Node * new = head;
       int a = List_length(head);
      if((index1 < 0) || (index1 > index2) || index1 > a || index2 > a)
	{
          return EXIT_FAILURE;
        }
      while(temp->index != index1)
           {
             temp = temp->next;
           } 
      while(new->index != index2)
          {
            new = new->next;
          }
      if(temp!= NULL && new != NULL)
	{
          int value = temp->value;
          temp-> value = new-> value;
          new-> value = value;
	}
      return EXIT_SUCCESS;	       
}

int List_read(Node * head, int index)
{
    Node * temp = head;
    int len = List_length(head);
    //  int i = 0;
    if((index > len) || (index < 0))
    {
      return -1;
    }
    while((temp->next != NULL) && (temp->index != index))
     {
       temp = temp->next;
     }
   
    return (temp->value);
}
      

int List_write(Node * head, int index, int val)
{
   Node * temp = head;
   int len = List_length(head);
   //  int i = 0;
   if((index > len)|| (index < 0))
     {
       return EXIT_FAILURE;
     }
   while(temp->index != index)
      {
        temp = temp->next;
      }	
   temp->value = val;
   return EXIT_SUCCESS;	
}
	
static void quickSortHelp ( Node * head , int first , int last )
 {
   int value = List_read(head,first);
   if(first >= last)
    {
      return;
    }
   int pivot = value;
   int low = first + 1;
   int high = last ;
	while (low < high )
	{
		while (( low < last ) && (List_read(head,low) <= pivot ))
		{
			// <= so that low will increment when arr [low ]
			// is the same as pivot , using < will stop
			// incrementing low when arr [low ] is the same
			// as pivot and the outer while loop will not stop
			low ++;
		}
		while (( first < high ) && (List_read(head,high) > pivot ))
		{
			high --;
		}
		if (low < high )
		{
		   List_swap(head,low,high);
		  // if(swap1 != 0)
		  //  {
		  //  return;
		      //  }	
		}
	}
	if ( pivot > List_read(head,high))
	{
 
	    List_swap(head,first,high);    
	  
	}
	quickSortHelp (head , first , high - 1);
	quickSortHelp (head , low , last );
   }
  
Node * List_qsort(Node * head, int length)
{
   quickSortHelp (head,0,length - 1);
  return head;
}

Node * List_readFromTextFile(char * filename)
{
   FILE * fptr = NULL;
   int val;
   Node * head = NULL;
   fptr = fopen(filename,"r");
   if(fptr == NULL)
     {
       return NULL;
     }
   while(fscanf(fptr,"%d",&val)!= EOF)	
     {
       head = List_insert(head,val);
     }
   fclose(fptr);  	
   return head; //Change this	
}

int List_writeToTextFile(Node * head, char * filename)
{
  Node * temp = head;
  FILE * fptr = NULL;
  fptr = fopen(filename,"w");
  if(fptr == NULL)
    {
      return EXIT_FAILURE;
    }
  while(temp != NULL)
    {
      fprintf(fptr,"%d",temp->value);	
      fprintf(fptr,"\n");
      temp = temp->next; 
    } 
      fclose(fptr);
   return EXIT_SUCCESS;
}

Node * List_readFromBinaryFile(char * filename)
{
  FILE * fptr = NULL;
  Node * head = NULL;
  Node * temp = malloc(sizeof(Node));	
  fptr = fopen(filename,"rb");
  while(fread(temp,sizeof(Node),1,fptr) == 1)
    {
      head = List_insert(head,temp -> value);
    }
  free(temp);
  fclose(fptr);	
  return (head); //Change this
}

int List_writeToBinaryFile(Node * head, char * filename)
{

  FILE * fptr = NULL;	
  fptr = fopen(filename,"wb");
  if(fptr == NULL)
    {
      return EXIT_FAILURE;
    }	
  while(head != NULL)
    {
      fwrite(head,sizeof(Node),1,fptr);
      head = head->next;
    }
  fclose(fptr);
  return EXIT_SUCCESS; 

}

