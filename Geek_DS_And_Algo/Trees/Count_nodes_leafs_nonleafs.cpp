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
int leaves(struct node * node)
{
  if(!node)
  return 0;
  if(node->left == NULL&&node->right==NULL)
  return 1;
  else
  {
    int l , r;
    l = leaves(node->left);
    r = leaves(node->right);
    return l+r;
  }
}
int nodes(struct node * node)
{
  if(!node)
  return 0;
  else
  {
    int l , r;
    l = nodes(node->left);
    r = nodes(node->right);
    return l+r+1;
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
    std::cout<<"Hight of tree is :"<< height(root)<<'\n';
    std::cout<<"Number of Nodes in the tree is :"<< nodes(root)<<'\n';
    std::cout<<"Number of leafs in the tree is :"<< leaves(root)<<'\n';
    std::cout<<"Number of nonleafs in the tree is :"<< nodes(root)-leaves(root)<<'\n';
    getchar();
    return 0;
}
