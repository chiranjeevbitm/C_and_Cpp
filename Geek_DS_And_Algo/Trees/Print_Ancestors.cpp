#include <iostream>
//#include <stdio.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};

bool printAncestors(struct node *root, int target) {
  if (root == NULL)
    return false;
  if (root->data == target)
    return true;

  if (printAncestors(root->left, target) ||
      printAncestors(root->right, target)) {
    std::cout << root->data << ' ';
    return true;
  }
  return false;
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
  root->left->left->left = newNode(7);

  std::cout << "Enter vakue of target" << '\n';
  int target;
  std::cin >> target;
  std::cout << "The ancestors of the node " << target << "  are" << '\n';
  printAncestors(root, target);
  return 0;
}
