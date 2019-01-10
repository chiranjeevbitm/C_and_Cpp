#include<iostream>

struct node{
  int data;
  struct node *next;
};

void Rotatek(struct node **head_ref,int k){
  if(k==0)
  return;

  struct node* current = *head_ref;
  int count = 1;

  while(count<k && current!=NULL){
    current = current->next;
    count++;
  }
  if(current == NULL)
  return;

  struct node *kthnode = current;

  while(current->next !=NULL)
  current = current->next;

  current->next = *head_ref;

  *head_ref = kthnode->next;

  kthnode->next = NULL;
}


void push(struct node **head_ref,int new_data){
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void printList(struct node *node) {
  while(node!=NULL){
    std::cout << node->data << ' ';
    node = node->next;

  }
}

int main(){
  int k;
  struct node *head = NULL;
  for (int i = 60; i > 0; i -= 10)
      push(&head, i);

  std::cout << "Given linked list : " << '\n';
  printList(head);
  std::cout <<'\n' <<"Enter the value of k" << '\n';
  std::cin >> k;

  Rotatek(&head,k);
  std::cout << "After "<< k <<"  Rotation Linkead list becomes :"<< '\n';
  printList(head);

  return 0;
}
