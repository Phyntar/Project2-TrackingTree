//TrackingTree.cpp


#include "TrackingTree.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::hash;

char* gen_random(const int len);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructor~~~~~

TrackingTree::TrackingTree(string in)
{
	parentID = gen_random(8);
	rawEvent = in;
	lHash = "null";
	rHash = "null";
	id = getParentID() + in;
	id.resize(8);
	leftChild = NULL;
	rightChild = NULL;	

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Get Functions~~~~~

string TrackingTree::getID()
{
	return id;
}
string TrackingTree::getParentID()
{
	return parentID;
}
string TrackingTree::getRawEvent()
{
	return rawEvent;
}
string TrackingTree::getRHash()
{
	return rHash;
}
string TrackingTree::getLHash()
{
	return lHash;
}
vector<string> TrackingTree::getRHisth()
{
	return rHisth;
}
vector<string> TrackingTree::getLHisth()
{
	return lHisth;
}

TrackingTree * TrackingTree::getLeft()
{
	return leftChild;
}
TrackingTree * TrackingTree::getRight()
{
	return rightChild;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Set Functions~~~~~

void TrackingTree::setLeft(TrackingTree* in)
{
	leftChild = in;
}
void TrackingTree::setRight(TrackingTree* in)
{
	rightChild = in;
}

void TrackingTree::setID(string in)
{
	id = in;
}
void TrackingTree::setParentID(string in)
{
	parentID = in;
}
void TrackingTree::setRawEvent(string in)
{
	rawEvent = in;
}
void TrackingTree::setRhash(string in)
{
	rHash = in;
}
void TrackingTree::setLhash(string in)
{
	lHash = in;
}
void TrackingTree::addRhisth(string in)
{
	rHisth.push_back(in);
}
void TrackingTree::addLhisth(string in)
{
	lHisth.push_back(in);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Display Functions~~~~~

void TrackingTree::display()
{
	std::string prefix;
	if (id == "null")
	{
		cout << "-" << std::endl;
	}
	else
	{
		displayLeft(getLeft(), "      ");
		cout << "-----" << getID() << std::endl;
		displayRight(getRight(), "      ");
	}
}

void TrackingTree::displayLeft(TrackingTree * subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		cout<< prefix + "/" << std::endl;
	}
	else
	{
		displayLeft(subtree->getLeft(), prefix + "       ");
		cout<< prefix + "/-----" << subtree->getID() << std::endl;
		displayRight(subtree->getRight(), prefix + "|      ");
	}
}

void TrackingTree::displayRight(TrackingTree * subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		cout << prefix + "\\" << std::endl;
	}
	else
	{
		displayLeft(subtree->getLeft(), prefix + "|      ");
		cout << prefix + "\\-----" << subtree->getID() << std::endl;
		displayRight(subtree->getRight(), prefix + "       ");
	}
}