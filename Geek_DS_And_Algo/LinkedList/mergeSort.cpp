#include<iostream>

struct node{
  int data;
  struct node *next;

};
struct node* sortedMerge(struct node* a,struct node* b);

void frontBackSplit(struct node* source,struct node** front_ref,struct node** back_ref);

void mergesort(struct node** head_ref){
  struct node* head = *head_ref;
  struct node* a;
  struct node* b;
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
  frontBackSplit(head, &a, &b);
  mergesort(&a);
  mergesort(&b);
  *head_ref = sortedMerge(a, b);

}
struct node* sortedMerge(struct node* a,struct node* b){
  struct node* result = NULL;
  if(a==NULL)
  return (b);
  else if(b==NULL)
  return (a);
  if(a->data <= b->data){
    result = a;
    result->next = sortedMerge(a->next,b);
  }else{
    result = b;
    result->next = sortedMerge(a,b->next);
  }
  return (result);
}
void frontBackSplit(struct node* source,struct node** front_ref,struct node** back_ref){
  struct node* fast;
  struct node* slow;
  slow = source;
  fast = source->next;
  while(fast!=NULL){
    fast = fast->next;
      if (fast != NULL)
      {
          slow = slow->next;
          fast = fast->next;
      }
    }
  *front_ref = source;
  *back_ref = slow->next;
  slow->next = NULL;
}


void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

void push(struct node** head_ref,int new_data){
  struct node* new_node = (struct node*) malloc (sizeof(struct node));
  new_node ->data = new_data;
  new_node->next = (*head_ref);
  *head_ref = new_node;
}

int main()
{
 struct node* res = NULL;
 struct node* head1 = NULL;

 push(&head1, 3);
 push(&head1, 4);
 push(&head1, 2);
 push(&head1, 1);


 std::cout << "\nCreated Linked List 1: " << '\n';
 printList(head1);

 mergesort(&head1);
 std::cout << "\nAfter merge sorted lists is:" << '\n';
 printList(head1);
 getchar();
 return 0;
}
