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

private:

	TTnode * tree;

};

