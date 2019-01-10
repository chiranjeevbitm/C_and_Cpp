#include<iostream>

// A linked list node
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
void deletenode(struct Node** head_ref , struct Node* del){
  if(*head_ref == NULL || del == NULL){
    return;
  }
  if(*head_ref == del){
    *head_ref = del->next;
  }
  if(del->next !=NULL){
    del->next->prev=del->prev;
  }
  if(del->prev !=NULL){
    del->prev->next=del->next;
  }
  free(del);
  return;
}
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	struct Node* last;
	std::cout<<"\nTraversal in forward direction "<<"\n";
	while (node != NULL) {
		std::cout << node->data << " ";
		last = node;
		node = node->next;
	}
}
int main()
{
	struct Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);
	std::cout << "Created DLL is:" << '\n';
	printList(head);

	deletenode(&head,head);
  deletenode(&head,head);
  std::cout << "After deleting node 5 and 6 DLL:" << '\n';
	printList(head);
	return 0;
}
