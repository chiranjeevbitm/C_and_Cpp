// Insertion

// 1. Insertion in an empty list
// 2. Insertion at the beginning of the list
// 3. Insertion at the end of the list
// 4. Insertion in between the nodes

#include<iostream>

struct node{
  int data;
  struct node *next;

};
// adding first element in empty circular linked list
struct node *addtoEmpty(struct node* last,int new_data){
  if(last != NULL)
  return last;

  struct node *temp = (struct node*) malloc (sizeof(struct node));
  temp->data = new_data;
  last = temp;

  last->next = last;
  return last;
}
// add in the begining of the circular linkesd list
struct node *addBegin(struct node *last ,int new_data){
  if(last == NULL)
  return addtoEmpty(last , new_data);

  struct node *temp = (struct node*) malloc (sizeof(struct node));
  temp->data =new_data;
  temp->next = last->next;
  last->next = temp;

  return last;

}
// adding to End
struct node *addEnd(struct node *last ,int new_data){
  if(last == NULL)
  return addtoEmpty(last , new_data);

  struct node *temp = (struct node*) malloc (sizeof(struct node));
  temp->data =new_data;
  temp->next = last->next;
  last->next = temp;
  last = temp;

  return last;

}
struct node *addAfter(struct node *last, int new_data ,int item){
  if(last==NULL){
    return NULL;
  }
  struct node *temp, *p;
  p = last->next;
  do{
    if(p->data == item){
      temp = (struct node*) malloc(sizeof(struct node));
      temp->data = new_data;
      temp->next = p->next;
      p->next = temp;
      if(p ==last)
        last = temp;
      return last;
    }
    p = p->next;
  }while(p != last->next);
  std::cout << "Not present in the list" << '\n';
  return last;
}
void travrse(struct node* last){
  struct node* p;
  if(last == NULL)
  {
    std::cout << "The circular linked list is empty" << '\n';
    return;
  }
  p = last->next;
  do{
    std::cout << p->data << " ";
    p=p->next;
  }
  while(p != last->next);
}
//traverse and print data of circular linked list
void printList(struct node *first){
  struct node * temp  = NULL;
  if(first!=NULL){
    do{
      std::cout << temp->data << " ";
      temp = temp->next;
    }while(temp!=first);
  }
}

int main(){
  struct node *last = NULL;
  last = addtoEmpty(last,4);
  last = addBegin(last,1);
  last = addEnd(last,7);
  last = addAfter(last,2,1);
  last = addAfter(last,3,2);
  last = addAfter(last,5,4);
  last = addAfter(last,6,5);
  travrse(last);
  //printList(last);

  return 0;
}
