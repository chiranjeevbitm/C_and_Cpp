#include<iostream>

// A linked list node
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
void reverse(struct Node** head_ref){
 struct Node *temp  = NULL;
 struct Node *current = *head_ref;
 //swap next and prev for all nodes of doubly linked list
 while(current!=NULL){
  //swap
 temp = current->prev;
 current->prev = current->next;
 current->next = temp;

 current= current->prev;
 }
 if(temp!=NULL){
   *head_ref=temp->prev;
 }
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

  reverse(&head);
  std::cout << "After reversing DLL:" << '\n';
	printList(head);
	return 0;
}
