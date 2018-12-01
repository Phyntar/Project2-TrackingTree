//TrackingTree.cpp


#include "TrackingTree.h"
#include <cstdlib>

using std::hash;

TrackingTree::TrackingTree(string in)
{
	parentID = rand()%1000;
	rawEvent = in;
	lHash = "null";
	rHash = "null";
	id = "null";

}

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
	lHisth.push_back(in);
}


void TrackingTree::display(std::ostream& outfile)
{
	std::string prefix;
	if (id == "null")
	{
		outfile << "-" << std::endl;
	}
	else
	{
		displayLeft(outfile, tree_->left_, "    ");
		outfile << "---" << tree_->entry_ << std::endl;
		displayRight(outfile, tree_->right_, "    ");
	}
}

void TrackingTree::displayLeft(std::ostream & outfile, TrackingTree * subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		outfile << prefix + "/" << std::endl;
	}
	else
	{
		displayLeft(outfile, subtree->left_, prefix + "     ");
		outfile << prefix + "/---" << subtree->getID() << std::endl;
		displayRight(outfile, subtree->right_, prefix + "|    ");
	}
}

void TrackingTree::displayRight(std::ostream & outfile, TrackingTree * subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		outfile << prefix + "\\" << std::endl;
	}
	else
	{
		displayLeft(outfile, subtree->left_, prefix + "|    ");
		outfile << prefix + "\\---" << subtree->getID() << std::endl;
		displayRight(outfile, subtree->right_, prefix + "     ");
	}
}