#include "RedBlack.h"
#include "Athlete.h"


RedBlack::RedBlack()
{
	size = 0;
	numDeleted = 0;
	nil = new Athlete();
	root = nil;
}

Athlete * RedBlack::compare(Athlete * a, Athlete * b, string maxOrMin)
{
	Athlete* max = nullptr;
	Athlete* min = nullptr;
	int i = a->discipline.compare(b->discipline);
	if (i > 0)
	{
		max = a;
		min = b;
		//set max and min
	}
	else if (i < 0)
	{
		max = b;
		min = a;
		//set max and min
	}
	else
	{
		i = a->event.compare(b->event);
		if (i > 0)
		{
			max = a;
			min = b;
			//set max and min
		}
		else if (i < 0)
		{
			max = b;
			min = a;
			//set max and min
		}
		else
		{
			i = a->gender.compare(b->gender);
			if (i > 0)
			{
				max = a;
				min = b;
				//set max and min
			}
			else if (i < 0)
			{
				max = b;
				min = a;
				//set max and min
			}
			else
			{
				i = a->athlete.compare(b->athlete);
				if (i > 0)
				{
					max = a;
					min = b;
					//set max and min
				}
				else if (i < 0)
				{
					max = b;
					min = a;
					//set max and min
				}
				else
				{
					cout << "Compare function: All fields match";
					return nil;
					//print error
				}
			}
		}
	}
	if (maxOrMin == "MAX")
	{
		return max;
	}
	else if (maxOrMin == "MIN")
	{
		return min;
	}
	else
	{
		return nullptr;
	}
}

void RedBlack::inorderTreeWalk(Athlete* node)
{
	if (root == nil)
	{
		cout << endl << "Tree is Empty" << endl;
	}
	else if (node != nil)
	{
		inorderTreeWalk(node->left);
		node->print();
		inorderTreeWalk(node->right);
	}
	if (node == nil)
	{
		return;
	}
}

void RedBlack::postorderTreeWalk(Athlete* node)
{
	if (root == nil)
	{
		cout << endl << "Tree is Empty" << endl;
	}
	else if (node != nil)
	{
		postorderTreeWalk(node->left);
		postorderTreeWalk(node->right);
		node->print();
	}
}

void RedBlack::preorderTreeWalk(Athlete* node)
{
	if (root == nil)
	{
		cout << endl << "Tree is Empty" << endl;
	}
	else if (node != nil)
	{
		node->print();
		preorderTreeWalk(node->left);
		preorderTreeWalk(node->right);
	}
}
 
Athlete * RedBlack::treeSearch(Athlete* node, string key)
{
	if (node == nil || key == node->key)
	{
		return node;
	}
	else
	{
		if (key < node->key)
		{
			return treeSearch(node->left, key);
		}
		else
		{
			return treeSearch(node->right, key);
		}
	}
}

Athlete * RedBlack::treeMinimum(Athlete* node)
{
	while (node->left != nil)
	{
		node = node->left;
	}
	return node;
}

Athlete * RedBlack::treeMaximum(Athlete * node)
{
	while (node->right != nil)
	{
		node = node->right;
	}
	return node;
}

Athlete * RedBlack::treeSuccessor(Athlete* node)
{
	if (node->right != nil)
	{
		return treeMinimum(node->right);
	}
	else
	{
		Athlete* parentNode = node->parent;
		while (parentNode != nullptr && node == parentNode->right)
		{
			node = parentNode;
			parentNode = parentNode->parent;
		}
		return parentNode;
	}
}

Athlete * RedBlack::treePredecessor(Athlete * node)
{
	if (node->left !=nil)
	{
		return treeMaximum(node->left);
	}
	else
	{
		Athlete* parentNode = node->parent;
		while (parentNode != nullptr && node == parentNode->left)
		{
			node = parentNode;
			parentNode = parentNode->parent;
		}
		return parentNode;
	}
}

void RedBlack::treeInsert(Athlete * toInsert)
{
	Athlete* y;
	Athlete* x = root;
	bstInsert(toInsert);
	toInsert->color = "RED";
	if (root == nil)
	{
		toInsert->color = "BLACK";
		root = toInsert;
		size++;
		return;
	}
	while (/*toInsert != root &&*/ toInsert->parent->color == "RED")
	{
		if (toInsert->parent == toInsert->parent->parent->left)
		{
			y = toInsert->parent->parent->right;
			if (y->color == "RED")
			{
				toInsert->parent->color = "BLACK";
				y->color = "BLACK";
				toInsert->parent->parent->color = "RED";
				toInsert = toInsert->parent->parent;
			}
			else
			{
				if (toInsert == toInsert->parent->right)
				{
					toInsert = toInsert->parent;
					leftRotate(toInsert);
				}
				toInsert->parent->color = "BLACK";
				toInsert->parent->parent->color = "RED";
				rightRotate(toInsert->parent->parent);
			}
		}
		else
		{

			y = toInsert->parent->parent->left;
			if (y->color == "RED")
			{
				toInsert->parent->color = "BLACK";
				y->color = "BLACK";
				toInsert->parent->parent->color = "RED";
				toInsert = toInsert->parent->parent;
			}
			else
			{
				if (toInsert == toInsert->parent->left)
				{
					toInsert = toInsert->parent;
					rightRotate(toInsert);
				}
				toInsert->parent->color = "BLACK";
				toInsert->parent->parent->color = "RED";
				leftRotate(toInsert->parent->parent);
			}
		}
	}
	root->color = "BLACK";
	size++;
}

void RedBlack::bstInsert(Athlete * toInsert)
{
	Athlete* nodeParent = nil;
	Athlete* node = root;
	while (node != nil)
	{
		nodeParent = node;
		Athlete* temp = compare(toInsert, nodeParent, "MIN");
		if (temp == nil)
		{
			return;
		}
		else if (temp->key == toInsert->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	toInsert->parent = nodeParent;
	toInsert->color = "RED";
	toInsert->left = nil;
	toInsert->right = nil;
	if (nodeParent == nil)
	{
		root = toInsert;
	}
	else
	{
		Athlete* temp = compare(toInsert, nodeParent, "MIN");
		if (temp->key == toInsert->key)
		{
			nodeParent->left = toInsert;
		}
		else
		{
			nodeParent->right = toInsert;
		}
	}
}

void RedBlack::leftRotate(Athlete * pivot)
{
	Athlete* rightChild = pivot->right;
	pivot->right = rightChild->left;
	if (rightChild->left != nullptr)
	{
		rightChild->left->parent = pivot;
	}

	rightChild->parent = pivot->parent;
	if (pivot == root)
	{
		root = rightChild;
	}
	else
	{
		if (pivot == pivot->parent->left)
		{
			pivot->parent->left = rightChild;
		}
		else
		{
			pivot->parent->right = rightChild;
		}
	}
	rightChild->left = pivot;
	pivot->parent = rightChild;
}

void RedBlack::rightRotate(Athlete * pivot)
{
	Athlete* leftChild = pivot->left;
	pivot->left = leftChild->right;
	if (leftChild->right != nullptr)
	{
		leftChild->right->parent = pivot;
	}
	leftChild->parent = pivot->parent;
	if (pivot == root)
	{
		root = leftChild;
	}
	else
	{
		if (pivot == pivot->parent->right)
		{
			pivot->parent->right = leftChild;
		}
		else
		{
			pivot->parent->left = leftChild;
		}
	}
	leftChild->right = pivot;
	pivot->parent = leftChild;
}

string* RedBlack::getParameters(string in)
{
	string parameter;
	static string* parameters;
	if (in.substr(0, 11) == "tree_insert")
	{
		string parameter = in.substr(12);
		int i = 0;
		int pos = parameter.find(",");
		int index = 0;
		parameters = new string[8];

		try
		{
			while (pos != string::npos)										//Split parameters into array
			{
				parameters[index] = (parameter.substr(i, pos - i));
				i = ++pos;
				pos = parameter.find(",", pos);

				if (pos == string::npos)
					parameters[index + 1] = (parameter.substr(i, parameter.length()));
				index++;
			}
		}
		catch (...)
		{
			cout << "Initialization error while reading parameters" << endl;
		}
	}
	else
	{
		if (in.substr(0, 11) == "tree_search")
		{
			parameter = in.substr(12);
		}
		else if (in.substr(0, 16) == "tree_predecessor")
		{
			parameter = in.substr(17);
		}
		else if (in.substr(0, 14) == "tree_successor")
		{
			parameter = in.substr(15);
		}
		else
		{
			return nullptr;
		}

		string key;
		int i = 0;
		int pos = parameter.find(",");
		int index = 0;
		parameters = new string[4];
		while (pos != string::npos)										//Split parameters into array
		{
			parameters[index] = (parameter.substr(i, pos - i));
			i = ++pos;
			pos = parameter.find(",", pos);

			if (pos == string::npos)
				parameters[index + 1] = (parameter.substr(i, parameter.length()));
			index++;
		}
	}
	return parameters;

}

RedBlack::~RedBlack()
{
	//delete root;
}
