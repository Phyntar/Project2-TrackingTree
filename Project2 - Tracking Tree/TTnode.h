// TTnode.h

#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::hash;
class TTnode
{
public:

	TTnode(string raw);
	string getID();
	string getParentID();
	string getRawEvent();
	string getRHash();
	string getLHash();
	vector<string> getRHisth();
	vector<string> getLHisth();
	TTnode * getLeft();
	TTnode * getRight();
	hash<string> getHashTb();

	void setLeft(TTnode* in);
	void setRight(TTnode* in);
	void setID(string in);
	void setParentID(string in);
	void setRawEvent(string in);
	void setRhash(string in);
	void setLhash(string in);
	void addRhisth(string in);
	void addLhisth(string in);

	void display();
	void displayLeft(TTnode * subtree, std::string prefix);
	void displayRight(TTnode * subtree, std::string prefix);

	void displayRec();
	void displayChildRec(TTnode * subtree);

private:

	string id;
	string parentID;
	string rawEvent;
	string rHash;
	string lHash;
	vector<string> rHisth;
	vector<string> lHisth;
	TTnode * leftChild;
	TTnode * rightChild;
	hash<string> hashTb;
};
