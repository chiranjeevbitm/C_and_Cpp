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

void delete_at_pos(struct node** head_ref,int position)  //k = nodedata to be deleted
{
  struct node *temp = *head_ref;
  //if first node to delete
  if(position==0){
    *head_ref = temp->next;
    free(temp);
    return;

  }
  // for middle node to be deleted 
  for(int i=0; temp!=NULL && i<position-1;i++){
    temp = temp->next;

  }
  if(temp == NULL || temp->next ==NULL) return;
  struct node *next  = temp->next->next;

  free(temp->next);
  temp->next = next;
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
    delete_at_pos(&head, 3);
    puts("\nLinked List after Deletion of position 3: ");
    printList(head);
    return 0;
}
