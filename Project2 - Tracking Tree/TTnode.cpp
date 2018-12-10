//TTnode.cpp


#include "TTnode.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::hash;

char* gen_random(const int len);
string hasher(string in, hash<string> stHash);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructor~~~~~

TTnode::TTnode(string in)
{
	parentID = gen_random(8);
	rawEvent = in;
	lHash = "null";
	rHash = "null";
	id = hasher(getParentID() + in,hashTb);
	id.resize(8);
	leftChild = NULL;
	rightChild = NULL;	

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Get Functions~~~~~

string TTnode::getID()
{
	return id;
}
string TTnode::getParentID()
{
	return parentID;
}
string TTnode::getRawEvent()
{
	return rawEvent;
}
string TTnode::getRHash()
{
	return rHash;
}
string TTnode::getLHash()
{
	return lHash;
}
vector<string> TTnode::getRHisth()
{
	return rHisth;
}
vector<string> TTnode::getLHisth()
{
	return lHisth;
}

TTnode * TTnode::getLeft()
{
	return leftChild;
}
TTnode * TTnode::getRight()
{
	return rightChild;
}

hash<string> TTnode::getHashTb()
{
	return hashTb;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Set Functions~~~~~

void TTnode::setLeft(TTnode* in)
{
	leftChild = in;
}
void TTnode::setRight(TTnode* in)
{
	rightChild = in;
}

void TTnode::setID(string in)
{
	id = in;
}
void TTnode::setParentID(string in)
{
	parentID = in;
}
void TTnode::setRawEvent(string in)
{
	rawEvent = in;
}
void TTnode::setRhash(string in)
{
	addRhisth(rHash);
	rHash = in;
}
void TTnode::setLhash(string in)
{
	addLhisth(lHash);
	lHash = in;
}
void TTnode::addRhisth(string in)
{
	rHisth.push_back(in);
}
void TTnode::addLhisth(string in)
{
	lHisth.push_back(in);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Display Functions~~~~~

void TTnode::display()
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

void TTnode::displayLeft(TTnode * subtree, std::string prefix)
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

void TTnode::displayRight(TTnode * subtree, std::string prefix)
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