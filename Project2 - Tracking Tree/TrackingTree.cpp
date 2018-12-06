//TrackingTree.cpp

#include "TrackingTree.h"
#include "TTnode.h"

TrackingTree::TrackingTree()
{
	tree = new TTnode("9");
}

TTnode* TrackingTree::getTree()
{
	return tree;
}

void TrackingTree::setTree(TTnode* in)
{
	tree = in;
}

int TrackingTree::insertNode(TTnode* cur,TTnode* in)
{
	if (cur == NULL)
	{
		cur = in;
		return 0;
	}
	else if (cur->getLeft() == NULL)
	{
		cur->setLeft(in);
		return 0;
	}
	else if (cur->getRight() == NULL)
	{
		cur->setRight(in);
		return 0;
	}
	else
	{
		if (!isFull(cur->getRight()))
		{
			insertNode(cur->getRight(), in);
			return 0;
		}
		else
		{
			insertNode(cur->getLeft(), in);
			return 0;
		}
	}
	return 1;
}

bool TrackingTree::isFull(TTnode* in)
{
	if (in->getLeft() != NULL && in->getRight() != NULL)
	{
		if (isFull(in->getLeft()) && isFull(in->getRight()))
		{
			return true;
		}
	}

	if (in->getLeft() == NULL && in->getRight() == NULL)
	{
		return true;
	}

	return false;
}