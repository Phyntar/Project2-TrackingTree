//TrackingTree.cpp

#include "TrackingTree.h"
#include "TTnode.h"

TrackingTree::TrackingTree()
{
	tree = NULL;
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
		setTree(in);
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
			if (!isFull(cur->getLeft()))
			{
				insertNode(cur->getLeft(), in);
			}
			else
			{
				if (height(cur->getLeft()) == height(cur->getRight()))
				{
					insertNode(cur->getLeft(), in);
				}
				else
				{
					insertNode(cur->getRight(), in);
				}
			}
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

int TrackingTree::height(TTnode * in)
{
	if (in == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(in->getLeft());
		int rheight = height(in->getRight());

		if (lheight > rheight)
		{
			return lheight + 1;
		}
		else
		{
			return rheight + 1;
		}
	}
}