//Main.cpp

#include <iostream>
#include "TTnode.h"
#include "TrackingTree.h"
#include <unordered_map>

using std::hash;
using std::cout;
using std::cin;


int main()
{
	TrackingTree * treeMaster = new TrackingTree();

	treeMaster->insertNode(treeMaster->getTree(), new TTnode("10"));
	treeMaster->insertNode(treeMaster->getTree(), new TTnode("10"));
	treeMaster->insertNode(treeMaster->getTree(), new TTnode("10"));
	treeMaster->insertNode(treeMaster->getTree(), new TTnode("10"));
	treeMaster->insertNode(treeMaster->getTree(), new TTnode("10"));
	treeMaster->insertNode(treeMaster->getTree(), new TTnode("10"));
	treeMaster->insertNode(treeMaster->getTree(), new TTnode("10"));
	treeMaster->getTree()->display();
	
	
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

string hasher(string in, hash<string> stHash)
{
	string out;

	for (int i = 0; i < 8; i++)
	{
		out.push_back(stHash(in + static_cast<char>(i)));
	}

	return out;
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