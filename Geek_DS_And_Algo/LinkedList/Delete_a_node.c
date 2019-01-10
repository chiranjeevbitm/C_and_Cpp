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

void delete_node(struct node** head_ref,int key)  //k = nodedata to be deleted
{
  struct node *temp = *head_ref, *prev;
  if(temp!=NULL && temp->data == key){
    *head_ref = temp->next;
    free(temp);
    return;

  }
  while(temp != NULL && temp->data != key){
    prev =temp;
    temp = temp->next;

  }
  if(temp == NULL) return;
  prev->next = temp->next;
  free(temp);
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

    puts("Created Linked List: ");
    printList(head);
    delete_node(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
