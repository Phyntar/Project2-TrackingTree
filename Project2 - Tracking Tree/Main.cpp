//Main.cpp

#include <iostream>
#include "TrackingTree.h"

using std::cout;
int main()
{
	

	TrackingTree* tree = new TrackingTree("10");
	tree->setLeft(new TrackingTree("7"));
	tree->setRight(new TrackingTree("6"));
	tree->display();
	system("pause");
	return 0;
}

int hashed(string in)
{
	return 0;
}




/*

//insert function below
//https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/


struct Node 

{
	int key;
	struct Node* left, *right;
};


struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};

// Inorder traversal of a binary tree
void inorder(struct Node* temp)
{
	if (!temp)
		return;

	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

//function to insert element in binary tree
void insert(struct Node* temp, int key)
{
	queue<struct Node*> q;
	q.push(temp);

	// Do level order traversal until we find 
	// an empty place.  
	while (!q.empty()) {
		struct Node* temp = q.front();
		q.pop();

		if (!temp->left) {
			temp->left = newNode(key);
			break;
		}
		else
			q.push(temp->left);

		if (!temp->right) {
			temp->right = newNode(key);
			break;
		}
		else
			q.push(temp->right);
	}

}

//https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/

*/