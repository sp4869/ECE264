#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer07.h"
static void Tree_printInorder ( BusinessNode * tn)
{
        if (tn == NULL )
        {
        return ;
        }
        printf("%s %s %s\n",tn->stars,tn->name,tn->address);
        Tree_printInorder (tn -> left );         
        Tree_printInorder (tn -> right );
}
int main(int argc,char ** argv)
{ 
   const char * s = "2";
  char * star1 = strdup(s);
  const char * n = "XYZU";
  char * name1 = strdup(n);
  const char * a = "fgfsfshfskdhf";
  char * ad1 = strdup(a);
  const char * s2 = "3";
  char * star2 = strdup(s2);
  const char * n2 = "ABCD";
  char * name2 = strdup(n2);
  const char * a2 = "sdkjh";
  char * ad2 = strdup(a2); 
//  char * star3 = "4";
//  char * name3 = "EFGC";
//  char * ad3 = "pipi";
   BusinessNode * temp = create_node(star1,name1,ad1);
   BusinessNode * node = create_node(star2,name2,ad2);
  // BusinessNode * head = create_node(star3,name3,ad3);
  BusinessNode * root = tree_insert(temp,NULL);
  root = tree_insert(node,root);
//  BusinessNode * ans = tree_search_name(name2,NULL);

 // BusinessNode * search = load_tree_from_file("yelp_businesses.tsv");
  Tree_printInorder(root);
 // destroy_tree(search);
  return EXIT_SUCCESS;
}

