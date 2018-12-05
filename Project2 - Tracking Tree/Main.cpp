//Main.cpp

#include <iostream>
#include "TrackingTree.h"
#include <unordered_map>

using std::hash;
using std::cout;
using std::cin;


int main()
{
	
	TrackingTree* tree = new TrackingTree("10");
	tree->setLeft(new TrackingTree("7"));
	
	tree->getLeft()->setLeft(new TrackingTree("5"));
	tree->getLeft()->setRight(new TrackingTree("4"));

	tree->getLeft()->getLeft()->setLeft(new TrackingTree("1"));
	tree->getLeft()->getLeft()->setRight(new TrackingTree("fu"));

	tree->setRight(new TrackingTree("6"));

	tree->getRight()->setLeft(new TrackingTree("3"));
	tree->getRight()->setRight(new TrackingTree("2"));

	tree->display();

	

	system("pause");
	return 0;
}

char* gen_random(const int len)
{
	char* s = new char;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;

	return s;
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