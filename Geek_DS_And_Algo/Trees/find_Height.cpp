#include<iostream>

struct node
{
    int data ;
    struct node *left,*right;
};

int height(struct node * node)
{
  if(!node)
  return 0;
  else
  {
    int l , r;
    l = height(node->left);
    r = height(node->right);

    if(l>r)
    return l+1;
    else return r+1;
  }
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    std::cout<<"Hight of tree is :"<< height(root);

    getchar();
    return 0;
}
