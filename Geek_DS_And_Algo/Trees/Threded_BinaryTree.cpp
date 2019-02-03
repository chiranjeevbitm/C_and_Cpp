#include<iostream>
struct Node
{
    int data;
    Node *left, *right;
    bool rightThread;
};
struct Node* leftmost(struct Node *n)
{
    if (n == NULL)
       return NULL;

    while (n->left != NULL)
        n = n->left;

    return n;
}

void inOrder(struct Node *root)
{
    struct Node *cur = leftmost(root);
    while (cur != NULL)
    {
        std::cout << cur->data << ' ';

        // If this node is a thread node, then go to
        // inorder successor
        if (cur->rightThread)
            cur = cur->right;
        else // Else go to the leftmost child in right subtree
            cur = leftmost(cur->right);
    }
}

struct Node* newtNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
int main()
{
	struct Node* root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	inOrder(root);

	return 0;
}
