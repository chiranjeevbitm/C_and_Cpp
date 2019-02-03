#include <iostream>
//#include <stdio.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};
void K_Dist(struct node *root, int k) {
  if (root == NULL)
    return;
  if (k == 0) {
    std::cout << root->data << ' ';
    return;
  } else {
    K_Dist(root->left, k - 1);
    K_Dist(root->right, k - 1);
  }
}

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);
  std::cout << "Enter vakue of k" << '\n';
  int k;
  std::cin >> k;
  std::cout << "At distance " << k << " from  the tree, nodes are" << '\n';
  K_Dist(root, k);
  return 0;
}
