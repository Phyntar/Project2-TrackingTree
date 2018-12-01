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

	void setID(string in);
	void setParentID(string in);
	void setRawEvent(string in);
	void setRhash(string in);
	void setLhash(string in);
	void addRhisth(string in);
	void addLhisth(string in);

private:
	
	string id;
	string parentID;
	string rawEvent;
	string rHash;
	string lHash;
	vector<string> rHisth;
	vector<string> lHisth;
};
