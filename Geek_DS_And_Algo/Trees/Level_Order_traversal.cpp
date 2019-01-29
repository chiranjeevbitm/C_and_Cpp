/* Function to print level order traversal of tree
printLevelorder(tree)
for d = 1 to height(tree)
   printGivenLevel(tree, d);

//Function to print all nodes at a given level

printGivenLevel(tree, level)
if tree is NULL then return;
if level is 1, then
    print(tree->data);
else if level greater than 1, then
    printGivenLevel(tree->left, level-1);
    printGivenLevel(tree->right, level-1);

*/

#include<iostream>

struct node
{
	int data;
	struct node* left, *right;
};

/* Function protoypes */
 void printGivenLevel(struct node* root, int level);
 int height(struct node* node);
// struct node* newNode(int data);


void LevelOrder(struct node* root)
{
	int h = height(root);
	int i;
	for (i=1; i<=h; i++)
		printGivenLevel(root, i);
}

void printGivenLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		std::cout << root->data << ' ';
	else if (level > 1)
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

int height(struct node* node)
{
	if (node==NULL)
		return 0;
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return(lheight+1);
		else return(rheight+1);
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
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

  std::cout<<"Level Order traversal of binary tree is \n";
	LevelOrder(root);

	return 0;
}
