#include<iostream>
struct node{
  int data;
  struct node *next;

};

void push(struct node** head_ref,int new_data){
  struct node* new_node = (struct node*) malloc (sizeof(struct node));
  new_node ->data = new_data;
  new_node->next = (*head_ref);
  *head_ref = new_node;
}

//Iterative Approch
void reverseItr(struct node** head_ref){
       struct node *current = *head_ref;
       struct node *prev = NULL;
       struct node *next = NULL;


       while (current != NULL)
       {
           // Store next
           next = current->next;

           // Reverse current node's pointer
           current->next = prev;

           // Move pointers one position ahead.
           prev = current;
           current = next;
       }
       *head_ref = prev;
   }

// Recursive Approch
  // struct node *head;
  // void reverseRec(struct node* prev,struct node *current){
  //
  //
  //   if(current !=NULL){
  //     reverseRec(current,current->next);
  //     current->next = prev;
  //
  //   }else{
  //     head = prev;
  //   }
  // }

//Recursive Approch 2
// 1) Divide the list in two parts - first node and rest of the linked list.
// 2) Call reverse for the rest of the linked list.
// 3) Link rest to first.
// 4) Fix head pointer

void reverseRecursive(struct node** head_ref){
  struct node *first;
  struct node *rest;
  if(head_ref==NULL){
    return;
  }
  first = *head_ref;
  rest = first->next;
  if(rest==NULL) return;
  reverseRecursive(&rest);
  first->next->next = first;
  first->next = NULL;
  *head_ref = rest;
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

    std::cout << "\nCreated Linked List: " << '\n';
    printList(head);
    //reverseItr(&head);
    //std::cout << "\nAfter reversing(Iterative)" << '\n';
    //printList(head);

    reverseRecursive(&head);
    std::cout << "\nAfter reversing(Recursive)" << '\n';
    printList(head);
    return 0;
}
