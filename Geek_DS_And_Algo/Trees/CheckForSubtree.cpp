#include <iostream>
//#include <stdio.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};

bool areIdentical(struct node *root1, struct node *root2) {
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;

  return (root1->data == root2->data &&
          areIdentical(root1->left, root2->left) &&
          areIdentical(root1->right, root2->right));
}

bool isSubtree(struct node *S, struct node *T) {
  if (S == NULL)
    return true;
  if (T == NULL)
    return false;

  if (areIdentical(T, S))
    return true;

  return (isSubtree(T->left, S) || isSubtree(T->right, S));
}

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

int main() {
  struct node *T = newNode(26);
  T->right = newNode(3);
  T->right->right = newNode(3);
  T->left = newNode(10);
  T->left->left = newNode(4);
  T->left->left->right = newNode(30);
  T->left->right = newNode(60);

  struct node *S = newNode(100);
  S->right = newNode(600);
  S->left = newNode(40);
  S->left->right = newNode(300);

  if (isSubtree(T, S))
    std::cout << "Tree 2 is subtree of Tree 1" << '\n';
  else
    std::cout << "Tree 2 is not a subtree of Tree 1" << '\n';

  return 0;
}
