#include <iostream>
//#include <stdio.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};
int getWidth(struct node *root, int level);
int height(struct node *root);
struct node *newNode(int data);

int getMaxWidth(struct node *root) {
  int maxWidth = 0;
  int width;
  int h = height(root);
  for (int i = 0; i <= h; i++) {
    width = getWidth(root, i);
    if (width > maxWidth)
      maxWidth = width;
  }
  return maxWidth;
}

int getWidth(struct node *root, int level) {
  if (root == NULL)
    return 0;

  if (level == 1)
    return 1;

  else if (level > 1)
    return (getWidth(root->left, level - 1) + getWidth(root->right, level - 1));

  return 0;
}

int height(struct node *node) {
  if (node == NULL)
    return 0;
  else {
    int lheight = height(node->left);
    int rheight = height(node->right);

    return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
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
  root->right->right = newNode(8);
  root->right->left = newNode(10);
  root->right->right->left = newNode(6);
  root->right->right->right = newNode(7);

  std::cout << "Max width of the tree is " << getMaxWidth(root) << '\n';
  return 0;
  ;
}
