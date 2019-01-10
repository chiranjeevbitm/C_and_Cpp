#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;

};
// 1. insert at beginning
void push(struct node** head_ref,int new_data){

  // allocate new node
  struct node* new_node = (struct node*) malloc (sizeof(struct node));
  //put new_data
  new_node ->data = new_data;
  //make next of new_data as head
  new_node->next = (*head_ref);
  //move head to point new node
  (*head_ref) = new_node;

}
// 2. insert after a given node
void insert_after(struct node* prev_node, int new_data){
  //prev_node should not be NULL
  if(prev_node==NULL){
    printf("previous node scanot not be NULL\n");
    return;
  }
  // allocate new node
  struct node* new_node = (struct node*) malloc (sizeof(struct node));
  //put new_data
  new_node ->data = new_data;

  new_node ->next = prev_node->next;

  prev_node->next = new_node;
}
// 3. insert at the end
void append(struct node** head_ref,int new_data){

  // allocate new node
  struct node* new_node = (struct node*) malloc (sizeof(struct node));

  struct node  *temp = *head_ref;
  //put new_data
  new_node ->data = new_data;
  new_node->next =NULL;

  //check for if there is only one node or no node

 if(*head_ref==NULL){
   *head_ref = new_node;
   return;
 }

 while(temp->next!=NULL){
   temp=temp->next;
 }
 temp->next = new_node;
 return;
}


void printlist(struct node* node){
  while(node!=NULL){
    printf("%d ",node->data );
    node= node->next;
  }
}

int main(){
   struct node *head = NULL;
   append(&head,2);
   push(&head,1);
   append(&head,4);
   insert_after(head->next,3);
   printf("\n Created Linked list is: ");
   printlist(head);
   return 0;




}
