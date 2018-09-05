#include <stdio.h>
#include <stdlib.h>

 typedef struct linked_list
{
  
int *data;
   
struct linked_list *next;
 
} linked_list;

 
linked_list * new_node (int *x)
{
  
linked_list * new_node = (linked_list *) malloc (sizeof (linked_list));
  
if (x != NULL)
    {
      
new_node->data = (int *) malloc (sizeof (int));
      
*(new_node->data) = *x;
    
}
  else
    {
      
new_node->data = NULL;
    
}
  
 
new_node->next = NULL;
  
return new_node;

}


 
void
print_list (linked_list * head)
{
  
if (head->data)
    {
      
      do
	{
	  
printf ("%d ", *(head->data));
	
}
      while (head = head->next);
    
}
  else
    {
      
printf ("List is empty");
    
}
  
printf ("\n");

}


 
void
insert_node (linked_list * head, int x)
{
  
linked_list * current = head;
  
if (current->data)
    {
      
while (current->next)
	{
	  
current = current->next;
	
}
      
 
current->next = new_node (&x);
    
}
  else
    {
      
current->data = (int *) malloc (sizeof (int));
      
*(current->data) = x;

} 
} 
 
void

delete_node (linked_list * head, int x)
{
  
printf ("Trying to delete %d\n", x);
  
linked_list * current = head, *prev = NULL;
  
if (current->data)
    {
      
while (current->next && *(current->data) != x)
	{
	  
prev = current;
	  
current = current->next;
	
}
      
 
if (*(current->data) == x)
	{
	  
if (prev)
	    {
	      
prev->next = current->next;
	    
}
	  else
	    {
	      
if (current->next)
		{
		  
linked_list * t = current->next;
		  
current->data = t->data;
		  
current->next = t->next;
		  
free (t);
		  
return;
		
}
	    
}
	  
 
if (current->next)
	    {
	      
free (current);
	    
}
	  else
	    {
	      
current->data = NULL;
	    
}
	
}
    
}
  else
    {
      
return;
    
}

}


 
 
int
main ()
{
  
linked_list * head = new_node (NULL);
  
 
insert_node (head, 4);
  
insert_node (head, 2);
  
insert_node (head, 1);
  
insert_node (head, 10);
  
print_list (head);
  
 
delete_node (head, 1);
  
print_list (head);
  
 
delete_node (head, 5);
  
print_list (head);
  
 
delete_node (head, 4);
  
print_list (head);
  
 
delete_node (head, 2);
  
print_list (head);
  
 
delete_node (head, 10);
  
print_list (head);
  
 
delete_node (head, 1);
  
print_list (head);
  
 
insert_node (head, 3);
  
insert_node (head, 9);
  
print_list (head);

}

