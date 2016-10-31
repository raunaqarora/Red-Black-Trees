#ifndef REDBLACK_H
#define REDBLACK_H
#include "Athlete.h"

class RedBlack
{
private:
	int numDeleted;
public:
	int size;
	Athlete* root;
	Athlete* nil;
	RedBlack();
	Athlete * compare(Athlete * a, Athlete* b, string maxOrMin);
	void inorderTreeWalk(Athlete* node);
	void postorderTreeWalk(Athlete* node);
	void preorderTreeWalk(Athlete* node);
	Athlete* treeSearch(Athlete* node, string key);
	Athlete* treeMinimum(Athlete* node);
	Athlete* treeMaximum(Athlete* node);
	Athlete* treeSuccessor(Athlete* node);
	Athlete* treePredecessor(Athlete* node);
	void treeInsert(Athlete *toInsert);
	void bstInsert(Athlete *toInsert);
	void leftRotate(Athlete *pivot);
	void rightRotate(Athlete *pivot);
	string *getParameters(string in);
	~RedBlack();
};

#endif