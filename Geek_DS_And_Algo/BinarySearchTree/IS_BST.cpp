
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

bool isBSTUtil(struct Node* root, Node *&prev)
{
    // traverse the tree in inorder fashion and
    // keep track of prev node
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
          return false;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
          return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }

    return true;
}
int isCompleteTree(struct Node *root)
{
	if(root == NULL)	return 1;
	if((root->left)==NULL && ((root->right)==NULL))	return 1;
	else if((root->left)!=NULL && ((root->right)!=NULL)) return(isCompleteTree(root->left) && isCompleteTree(root->right));
	else	return 0;
}

bool isBST(Node *root)
{
   Node *prev = NULL;
   return isBSTUtil(root, prev);
}

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}


int main()
{
	struct Node *root = newNode(50);
	root->left	 = newNode(30);
	root->right	 = newNode(40);
	root->left->left = newNode(20);
	root->left->right = newNode(40);

	// if (isBST(root))
	// 	cout << "Is BST";
	// else
	// 	cout << "Not a BST";
	if(isCompleteTree(root) == 1)
		cout << "Is BST\n";
	else
		cout << "Not a BST\n";

	return 0;
}
