#include<iostream>

struct node
{
    int data;
    struct node *left,*right;
    node(int data)
    {
      this->data = data;
      left = right = NULL;
    }
};

void printPostorder(struct node *node)
{
  if(node == NULL)
  return;

  printPostorder(node->left);
  printPostorder(node->right);
  std::cout << node->data << ' ';
}
void printInorder(struct node *node)
{
  if(node == NULL)
  return;

  printInorder(node->left);
  std::cout << node->data << ' ';
  printInorder(node->right);

}
void printPreorder(struct node *node)
{
  if(node == NULL)
  return;

  std::cout << node->data << ' ';
  printPreorder(node->left);
  printPreorder(node->right);

}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  std::cout << "\nPreorder traversal of the thee is :" << '\n';
  printPreorder(root);
  std::cout << "\nInorder traversal of the thee is :" << '\n';
  printInorder(root);
  std::cout << "\nPostorder traversal of the thee is :" << '\n';
  printPostorder(root);
}
