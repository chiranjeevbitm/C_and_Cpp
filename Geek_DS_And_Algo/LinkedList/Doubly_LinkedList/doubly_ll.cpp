#include<iostream>

// A linked list node
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

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

void insertAfter(struct Node* prev_node, int new_data)
{
	if (prev_node == NULL) {
	std::cout << "prev_node cannot be NULL" << "\n";
		return;
	}
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;

	new_node->prev = prev_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}
// addEnd
void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref;

	new_node->data = new_data;

	new_node->next = NULL;

	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;

	new_node->prev = last;

	return;
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

	std::cout<< "\nTraversal in reverse direction "<<"\n";
	while (last != NULL) {
		std::cout << last->data << " ";
		last = last->prev;
	}
}
int main()
{
	struct Node* head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	std::cout << "Created DLL is:" << '\n';
	printList(head);
	return 0;
}
