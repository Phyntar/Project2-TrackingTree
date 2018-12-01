//Main.cpp

#include "TrackingTree.h"

int main()
{

}

int hashed(string in)
{
	return 0;
}




//code for insertion into the tree
// Driver code 
int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder traversal before insertion:";
	inorder(root);

	int key = 12;
	insert(root, key);

	cout << endl;
	cout << "Inorder traversal after insertion:";
	inorder(root);

	return 0;
}
//https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
