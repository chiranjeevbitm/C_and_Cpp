#include<iostream>

struct node
{
  int data;
  node *next;
};

//Linked List Creation

class list
{
private:
  node *head, *tail;
  public:
  list()
  {
    head=NULL;
    tail=NULL;
  }


void createnode(int value){
  node *temp = new node;
  temp->data = value;
  temp->next = NULL;
  if(head== NULL){
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else{
    tail->next = temp;
    tail = temp;
  }
}
void display(){
  node * temp = new node;
  temp =head;
  while(temp!=NULL){
    std::cout << temp->data << '\t';
    temp = temp->next;
  }
}
void insert_start(int value)
{
  node *temp=new node;
  temp->data=value;
  temp->next=head;
  head=temp;
}


};

int main(){
  list obj;
  std::cout << "============== the linked list is =================" << '\n';
  obj.createnode(10);
  obj.createnode(20);
  obj.createnode(30);
  obj.createnode(40);
  obj.display();
  std::cout << '\n'<< "====================================================" << '\n';

}
