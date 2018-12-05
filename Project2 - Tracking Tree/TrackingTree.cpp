//TrackingTree.cpp

#include "TrackingTree.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Get Functions~~~~

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
TrackingTree* TrackingTree::getLeft()
{
	return leftChild;
}

TrackingTree* TrackingTree::getRight()
{
	return rightChild;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Set Functions~~~~

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