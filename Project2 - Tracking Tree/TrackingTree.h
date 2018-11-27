// TrackingTree.h

#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;
class TrackingTree
{
public:
	
	string getID();
	string getParentID();
	string getRawEvent();
	string getRHash();
	string getLHash();
	vector<string> getRHisth();
	vector<string> getLHisth();



private:
	
	string id;
	string parentID;
	string rawEvent;
	string rHash;
	string lHash;
	vector<string> rHisth;
	vector<string> lHisth;
};
