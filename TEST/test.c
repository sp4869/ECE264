:w#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct listnode
 {
 struct listnode * next ;
 int value ;
 } Node ;


 Node * Node_construct ( int );
 Node * List_insert ( Node *  , int );
void List_destroy ( Node *  );
void List_print ( Node * );



 Node * Node_construct ( int v )
 {
 Node * n = malloc ( sizeof ( Node ));
 n -> value = v ;
 n -> next = NULL ;
 return n ;
 }

 /*
 *  insert a value v to a linked list .
 *   head : the head of the original list .
 *    return the head of the new list .
 *     */
 Node * List_insert ( Node * head , int v )
 {
 Node * p = Node_construct ( v );
 if ( head == NULL )
 {
 return p ;
 }
 if (( v % 2) == 1) /* odd number */
 {
 /* insert at the beginning */
 p -> next = head ;
 }
 Node * q = head ;
 /* insert at the end */
 while (( q -> next ) != NULL )
 {
 q = q -> next ;
 }
 q -> next = p ;
 return head ;
 }

 /* delete every node */
 void List_destroy ( Node * head )
 {
 while ( head != NULL )
 {
 Node * p = head -> next ;
 free ( head );
 head = p ;
 }
 }

 void List_print ( Node * head )
 {
 printf ("\nPrint the whole list :\n ");
 while ( head != NULL )
 {
 printf ("% d " , head -> value );
 head = head -> next ;
 }
 printf ("\n \n ");
 }

 int main ( int argc , char * argv [])
 {
 Node * head = NULL ; /* must initialize it to NULL */
 head = List_insert ( head , 917);
 head = List_insert ( head , -504);
 head = List_insert ( head , 263);
 head = List_insert ( head , 326);
 head = List_insert ( head , 138);
 head = List_insert ( head , -64);
 List_print ( head );
 List_destroy ( head );
 return EXIT_SUCCESS ;
 }
