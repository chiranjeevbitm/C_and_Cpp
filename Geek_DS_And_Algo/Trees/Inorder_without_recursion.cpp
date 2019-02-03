/*
ALGORITHM

1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.

*/

#include<iostream>
#include<stack>
using namespace std;
struct node
{
  int data;
  struct node* left,*right;
  node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

void inorder(struct node *root)
{
  stack<node *>s;
  node* curr = root;
  while(curr!=NULL || s.empty()==false)
  {
    while(curr!=NULL)
    {
      s.push(curr);
      curr = curr->left;

    }
    curr = s.top();
    s.pop();
    std::cout << curr->data << ' ';
    curr = curr->right;
  }
}
int main()
{
    struct node *root = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);

    inorder(root);
    return 0;
}
