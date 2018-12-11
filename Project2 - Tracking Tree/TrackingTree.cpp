//TrackingTree.cpp

#include "TrackingTree.h"
#include "TTnode.h"

#include <iostream>

using std::cout;

string hasher(string in, hash<string> stHash);
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

int TrackingTree::insertNode(TTnode* cur,string in)
{
	if (cur == NULL)
	{
		setTree(new TTnode(in));
		return 0;
	}
	else if (cur->getLeft() == NULL)
	{
		cur->setLeft(new TTnode(in));
		cur->getLeft()->setParentID(cur->getID());
		return 0;
	}
	else if (cur->getRight() == NULL)
	{
		cur->setRight(new TTnode(in));
		cur->getRight()->setParentID(cur->getID());
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

void TrackingTree::updateCrawl(int height)
{

	if (height > 0)
	{
		vector<TTnode*> curLevel = nodesAtH(tree, height);

		for (int i = 0; i < curLevel.size(); i++)
		{
			if (curLevel.at(i)->getLeft() != NULL)
			{
				if (curLevel.at(i)->getLHash() != hasher(curLevel.at(i)->getLeft()->getID() + curLevel.at(i)->getLeft()->getParentID() + curLevel.at(i)->getLeft()->getLHash() + curLevel.at(i)->getLeft()->getRHash(), curLevel.at(i)->getHashTb()))
				{
					curLevel.at(i)->setLhash(hasher(curLevel.at(i)->getLeft()->getID() + curLevel.at(i)->getLeft()->getParentID() + curLevel.at(i)->getLeft()->getLHash() + curLevel.at(i)->getLeft()->getRHash(), curLevel.at(i)->getHashTb()));
				}
			}			

			if (curLevel.at(i)->getRight() != NULL)
			{
				if (curLevel.at(i)->getRHash() != hasher(curLevel.at(i)->getRight()->getID() + curLevel.at(i)->getRight()->getParentID() + curLevel.at(i)->getRight()->getRHash() + curLevel.at(i)->getRight()->getRHash(), curLevel.at(i)->getHashTb()))
				{
					curLevel.at(i)->setRhash(hasher(curLevel.at(i)->getRight()->getID() + curLevel.at(i)->getRight()->getParentID() + curLevel.at(i)->getRight()->getRHash() + curLevel.at(i)->getRight()->getRHash(), curLevel.at(i)->getHashTb()));
				}
			}

		}


		updateCrawl(height - 1);
	}
	
	
	

}

vector<TTnode*> TrackingTree::nodesAtH(TTnode* curTree, int height) 
{
	vector<TTnode *> nodes;
	if (height == 1)
	{
		if (curTree != NULL)
		{
			nodes.push_back(curTree);
		}
		return nodes;
	}	
	else
	{
		vector<TTnode *> left, right;
		left = nodesAtH(curTree->getLeft(), height - 1);
		right = nodesAtH(curTree->getRight(), height - 1);
		nodes.reserve(left.size() + right.size()); // preallocate memory
		nodes.insert(nodes.end(), left.begin(), left.end());
		nodes.insert(nodes.end(), right.begin(), right.end());
		return nodes;
	}

	return vector<TTnode*>();
}

void TrackingTree::showNode(TTnode* inTree, string id)
{
	if (inTree->getID() == id)
	{
		cout << "ID: " << inTree->getID();
		cout << "\nParentID: " << inTree->getParentID();
		cout << "\nRawEvent: " << inTree->getRawEvent();
		cout << "\nLeft Hash: " << inTree->getLHash();
		cout << "\nRight Hash: " << inTree->getRHash();
		cout << "\nLeft History: ";
		for (int i = 0; i < inTree->getLHisth().size(); i++)
		{
			cout << inTree->getLHisth().at(i) << ", ";
		}
		cout << "\nRight History: ";
		for (int i = 0; i < inTree->getRHisth().size(); i++)
		{
			cout << inTree->getRHisth().at(i) << ", ";
		}
	}
	else
	{
		if (inTree->getLeft() != NULL)
		{
			showNode(inTree->getLeft(), id);
		}
		if (inTree->getRight() != NULL)
		{
			showNode(inTree->getRight(), id);
		}
		
	}

}

void TrackingTree::changeNode(TTnode * inTree, string id, string raw)
{
	if (inTree->getID() == id)
	{
		inTree->setRawEvent(raw);
	}
	else
	{
		if (inTree->getLeft() != NULL)
		{
			changeNode(inTree->getLeft(), id, raw);
		}
		if (inTree->getRight() != NULL)
		{
			changeNode(inTree->getRight(), id, raw);
		}		
	}
}