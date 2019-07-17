#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
  int key;
  struct node *left,*right;
};
struct node *newNode(int item)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root)
{
  if(root != NULL)
  {
    inorder(root->left);
    cout<< root->key<<"\n";
    inorder(root->right);

  }
}
struct node *insert(struct node *node,int key)
{
  if(node ==NULL) return newNode(key);
  if(key<node->key)
    node->left = insert(node->left,key);
  else if(key>node->key)
    node->right=insert(node->right,key);

  return node;
}

int findMin(struct node* node)
{
  struct node *current  = node;
  while(current->left !=NULL)
  {
    current = current->left;
  }
  return current->key;
}

int findMax(struct node* node)
{
  struct node *current  = node;
  while(current->right !=NULL)
  {
    current = current->right;
  }
  return current->key;
}
int main()
{
  struct node *root = NULL;
   root = insert(root, 50);
   root = insert(root, 55);
   insert(root, 30);
   insert(root, 20);
   insert(root, 40);
   insert(root, 70);
   insert(root, 60);
   insert(root, 80);
   cout<<"minimum in the tree  "<<findMin(root)<<'\n';
   cout<<"maximum in the tree  "<<findMax(root)<<'\n';

   //inorder(root);
   return 0;

}
