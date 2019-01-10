#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;

};

void push(struct node** head_ref,int new_data){
  struct node* new_node = (struct node*) malloc (sizeof(struct node));
  new_node ->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}


/*
Iterative Solution

1) Initialize count as 0
2) Initialize a node pointer, current = head.
3) Do following while current is not NULL
     a) current = current -> next
     b) count++;
4) Return count
*/
int length_Itr(struct node* head)
{
  int count =0;
  struct node *current = head;
  while(current!=NULL){
    current = current->next;
    count++;
  }
  return count;

}


/*
Recursive Solution

int getCount(head)
1) If head is NULL, return 0.
2) Else return 1 + getCount(head->next)
*/

int length_Rec(struct node *head){
  if(head == NULL) return 0;
  else return 1 + length_Rec(head->next);
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

    printf("Created Linked List: ");
    printList(head);

    //printf("\nLength of the Linked List is: %d\n",length_Itr(head));
    printf("\nLength of the Linked List is: %d\n",length_Rec(head));

    return 0;
}
