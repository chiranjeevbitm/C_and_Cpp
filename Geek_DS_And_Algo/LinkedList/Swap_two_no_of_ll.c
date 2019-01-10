#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;

};

/*
need to check for
1) x and y may or may not be adjacent.
2) Either x or y may be a head node.
3) Either x or y may be last node.
4) x and/or y may not be present in linked list.
*/

void swap(struct node **head_ref,int x , int y){
  if(x == y) return;

  struct node *prevX = NULL , *currX  = *head_ref;
  while(currX && currX->data !=x){
    prevX = currX;
    currX = currX-> next;

  }
  struct node *prevY = NULL , *currY  = *head_ref;
  while(currY && currY->data !=x){
    prevY = currY;
    currY = currY-> next;

  }
  if(currX == NULL || currY == NULL)
  return;
  if(prevX == NULL)
    prevX->next = currY;
  else
    *head_ref = currY;

  if(prevY == NULL)
      prevY->next = currX;
  else
      *head_ref = currX;

       // Swap next pointers
       struct node *temp = currY->next;
       currY->next = currX->next;
       currX->next  = temp;
  }


void push(struct node** head_ref,int new_data){
  struct node* new_node = (struct node*) malloc (sizeof(struct node));
  new_node ->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
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

    struct node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 13);
    push(&head, 8);

    printf("\n Linked list before calling swap() ");
    printList(head);

    swap(&head, 1, 13);

    printf("\n Linked list after calling swap() ");
    printList(head);

}
