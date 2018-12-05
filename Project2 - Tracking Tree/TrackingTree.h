// TrackingTree.h

#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;
class TrackingTree
{
public:

	TrackingTree(string in);
	string getID();
	string getParentID();
	string getRawEvent();
	string getRHash();
	string getLHash();
	vector<string> getRHisth();
	vector<string> getLHisth();
	TrackingTree * getLeft();
	TrackingTree * getRight();

	void setLeft(TrackingTree* in);
	void setRight(TrackingTree* in);
	void setID(string in);
	void setParentID(string in);
	void setRawEvent(string in);
	void setRhash(string in);
	void setLhash(string in);
	void addRhisth(string in);
	void addLhisth(string in);

	void display(std::ostream& outfile);
	void displayLeft(std::ostream & outfile, TrackingTree * subtree, std::string prefix);
	void displayRight(std::ostream & outfile, TrackingTree * subtree, std::string prefix);

private:
	
	string id;
	string parentID;
	string rawEvent;
	string rHash;
	string lHash;
	vector<string> rHisth;
	vector<string> lHisth;
	TrackingTree * leftChild;
	TrackingTree * rightChild;
};
