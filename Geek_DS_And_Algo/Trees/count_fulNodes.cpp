#include<iostream>

struct node
{
    int data ;
    struct node *left,*right;
};

int fullNodes(struct node * node)
{
  if(!node)
  return 0;
  if(!node->left&&!node->right)
  return 0;
  else
  {
    int l , r;
    l = fullNodes(node->left);
    r = fullNodes(node->right);
    if(node->left!=NULL && node->right!=NULL)
    return l+r+1;
    else return l+r;
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

    std::cout<<"Hight of tree is :"<< fullNodes(root);

    getchar();
    return 0;
}
