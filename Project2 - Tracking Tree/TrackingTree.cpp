//TrackingTree.cpp

#include "TrackingTree.h"

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
	lHash.push_back(in);
}