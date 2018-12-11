//TrackingTree.h

#include "TTnode.h"

#pragma once

class TrackingTree
{
public:

	TrackingTree();

	TTnode* getTree();

	void setTree(TTnode* in);								//sets tree variable

	int insertNode(TTnode* cur,string in);					//finds where to insert a new node then inserts it
	bool isFull(TTnode* in);								//tests if a tree is a full tree
	int height(TTnode * in);								//returns the height of a tree
	void updateCrawl(int height);							//crawls through entire tree updating hash values
	vector<TTnode*> nodesAtH(TTnode* curTree, int height);	//returns a vector of nodes at height h for the updatecrawl function
	void showNode(TTnode* inTree, string id);				//searches for a node then prints it
	void changeNode(TTnode* inTree, string id, string raw);	//searches for a node then changes raw


private:

	TTnode * tree;

};

