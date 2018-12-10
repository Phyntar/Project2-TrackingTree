//TrackingTree.h

#include "TTnode.h"

#pragma once

class TrackingTree
{
public:

	TrackingTree();

	TTnode* getTree();

	void setTree(TTnode* in);

	int insertNode(TTnode* cur,TTnode* in);
	bool isFull(TTnode* in);
	int height(TTnode * in);
	void updateCrawl(int height);
	vector<TTnode*> nodesAtH(TTnode* curTree, int height);

private:

	TTnode * tree;

};

