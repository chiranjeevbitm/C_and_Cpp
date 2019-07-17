#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node *left,*right;
};

struct node *lca(struct node *root,int n1,int n2)
{
  while(root!=NULL)
  {
  if(root->data>n1 && root->data>n2)
  root = root ->left;
  else if(root->data<n1 && root->data<n2)
  root = root ->right;

  else break;
}
return root;
}
struct node *newNode(int data)
{
  struct node *node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left=node->right =NULL;
  return (node);
}

int main()
{
  struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct node *t = lca(root,n1,n2);
    cout<<"LCA of "<<n1 <<" and "<< n2<<" is "<<t->data<<"\n";

    return 0;
}
