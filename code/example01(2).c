#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	struct Node * next; //Compiler doesn't know this type is called Node yet
	int value;
} Node;

static Node * Node_construct ( int val )
{
	Node * nd = malloc ( sizeof ( Node ));
	nd -> value = val ;
	nd -> next = NULL ;
	return nd;
}

Node * List_insert ( Node * head , int val )
{
	printf (" insert  %d\n", val );
	Node * ptr = Node_construct ( val );
	ptr -> next = head ; // insert at the beginning
	return ptr ;
}


Node * List_search ( Node * head , int val )
{
	Node * ptr = head ;
	while ( ptr != NULL )
	{
		if (( ptr -> value ) == val )
		{
		return ptr ;
		}
		ptr = ptr -> next ;
	}
	return ptr ; // must be NULL
}

Node * List_delete ( Node * head , int val )
{
	printf (" delete  %d\n", val );
	Node * p = head ;
	if (p == NULL ) // empty list , do nothing
	{
		return p;
	}
	// delete the first node (i.e., head node )?
	if ((p -> value ) == val )
	{
		p = p -> next ;
		free ( head );
		return p; // p is the new head
	}
	// not deleting the first node
	Node * q = p -> next ;
	while ((q != NULL ) && ((q -> value ) != val ))
	{
		// check whether q is NULL before checking q -> value
		p = p -> next ;
		q = q -> next ;
	}
	if (q != NULL )
	{
		// delete the node whose value is val
		p -> next = q -> next ;
		free (q);
	}
	return head;
}

//Recursive implementation
Node * List_delete2 ( Node * head , int val )
{

	printf (" delete  %d\n", val );
	if ( head == NULL )
	{
		return NULL ;
	}
	if (( head -> value ) == val )
	{
		Node * p = head -> next ;
		free ( head );
		return p;
	}
	head -> next = List_delete2 ( head -> next , val ); //passes next value in list to recursive call
	return head;
}

void List_print ( Node * head )
{
	printf ("\nPrint  the   whole   list :\n");
	
	while ( head != NULL )
	{
		printf ("%d ", head -> value );
		head = head -> next ;
	}
	printf ("\n\n");
}
static void List_print2Help ( Node * head)
{
	if ( head == NULL )
	{
		return ;
	}
	printf ("%d ", head -> value );
	List_print2Help ( head -> next );
}

void List_print2 ( Node * head )
{
	printf ("\nPrint   the   whole   list :\n");
	List_print2Help ( head );
	printf ("\n\n");
}


void List_destroy ( Node * head )
{
	while ( head != NULL )
	{
		Node * p = head -> next ;
		free ( head );
		head = p;
	}

}
void List_destroy2 ( Node * head )
{
	if ( head == NULL )
	{
		return ;
	}
	List_destroy2 ( head -> next );
	free ( head ); // must be after the recursive call
}

int main (int argc, char ** argv)
{
	Node * head = NULL;
	
	head = List_insert(head, 11);
	head = List_insert(head, 22);
	head = List_insert(head, 33);
	List_print(head);
	head = List_delete(head,22);
	List_print(head);

	if(List_search(head,22)){
		printf("shouldn't get here");
	}
	else{
		printf("Linked list does not contain a node with value 22");
	}	

	if(List_search(head,11)){
		printf("Linked list contains value 11");	
	}
	List_destroy(head);
	return EXIT_SUCCESS;
	
}
