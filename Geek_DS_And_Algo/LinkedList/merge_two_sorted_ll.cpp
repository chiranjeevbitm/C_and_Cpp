#include<iostream>
struct node{
  int data;
  struct node *next;

};

void push(struct node** head_ref,int new_data){
  struct node* new_node = (struct node*) malloc (sizeof(struct node));
  new_node ->data = new_data;
  new_node->next = (*head_ref);
  *head_ref = new_node;
}
void movenode(struct node** dest_ref,struct node** source_ref);

/* Takes two lists sorted in increasing order, and splices
   their nodes together to make one big sorted list which
   is returned.  */
struct node* sortedMerge(struct node* a,struct node* b){
  struct node* result = NULL;
  if(a==NULL) return b;
  else if(b==NULL)   return a;
  if(a->data <= b->data){
    result = a;
    result->next = sortedMerge(a->next,b);
  }else{
    result = b;
    result->next = sortedMerge(a,b->next);
  }
  return result;
}

//utility function movenode takes the node from fron of the source and move it to front of the destination
void movenode(struct node** dest_ref,struct node** source_ref){
  //the front source node
  struct node* new_node = *source_ref;
  assert(new_node!=NULL);
  //Advance the source pointer
  *source_ref = new_node->next;
  //Link the old dest off the new node
  new_node->next = *dest_ref;
  //Move dest to point to the new node
  *dest_ref = new_node;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}



int main()
{
 struct node* res = NULL;
 struct node* head1 = NULL;
 struct node* head2 = NULL;

 push(&head1, 7);
 push(&head1, 6);
 push(&head1, 2);
 push(&head1, 1);

 push(&head2, 8);
 push(&head2, 5);
 push(&head2, 4);
 push(&head2, 3);

 std::cout << "\nCreated Linked List 1: " << '\n';
 printList(head1);

 std::cout << "\nCreated Linked List 2: " << '\n';
 printList(head2);

 res = sortedMerge(head1,head2);
 std::cout << "\nAfter merging sorted lists:" << '\n';
 printList(res);
}
