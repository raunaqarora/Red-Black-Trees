//#define CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include <iostream>
#include <string>
#include "RedBlack.h"
#include "Athlete.h"

using namespace std;

int main()
{
	int size;
	int numberOfCommands;
	string in;
	string token;					//temp buffer string
	cin >> size;
	cin.clear();
	//cin.ignore();
	RedBlack tree = RedBlack();

	try
	{
		getline(std::cin, in);
		do
		{
			cout << "next command: " + in << endl;

			if (in.substr(0, 12) == "tree_inorder")
			{
				tree.inorderTreeWalk(tree.root);
			}
			else if (in.substr(0, 13) == "tree_preorder")
			{
				tree.preorderTreeWalk(tree.root);
			}
			else if (in.substr(0, 14) == "tree_postorder")
			{
				tree.postorderTreeWalk(tree.root);
			}
			else if (in.substr(0, 12) == "tree_minimum")
			{
				Athlete* temp = tree.treeMinimum(tree.root);
				cout << "The first athlete is " << endl;
				temp->print();
			}
			else if (in.substr(0,12) == "tree_maximum")
			{
				Athlete* temp = tree.treeMaximum(tree.root);
				cout << "The last athlete is " << endl;
				temp->print();
			}
			else if (in.substr(0, 11) == "tree_insert")
			{
				//insert using parameters. store in an array of 8.
				string parameter = in.substr(12);
				int i = 0;
				int pos = parameter.find(",");
				int index = 0;
				string parameters[8];

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

					Athlete* temp = new Athlete(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5], parameters[6], parameters[7]);		
					tree.treeInsert(temp);
					//delete temp;
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
					string parameter = in.substr(12);
					int i = 0;
					int pos = parameter.find(",");
					int index = 0;
					string parameters[4];

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
					string key = parameters[0] + parameters[1] + parameters[2] + parameters[3];
					Athlete* temp = tree.treeSearch(tree.root, key);
					if (temp != tree.nil)
					{
						cout << "The medal recipient " << temp->athlete << " has the medal of " << temp->medal << endl;
					}
					else
					{
						cout << parameters[3] << " for " << parameters[0] << " with event " << parameters[2] << " not found" << endl;
					}
				}
				else if (in.substr(0, 16) == "tree_predecessor")
				{
					if (tree.size == 0)
					{
						cout << "Tree is empty" << endl;
						continue;
					}
					string parameter = in.substr(17);
					int i = 0;
					int pos = parameter.find(",");
					int index = 0;
					string parameters[4];

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
					string key = parameters[0] + parameters[1] + parameters[2] + parameters[3];
					Athlete* temp = tree.treeSearch(tree.root, key);
					Athlete* pre;
					if (temp != tree.nil)
					{
						pre = tree.treePredecessor(temp);
						if (pre == tree.nil)
						{
							cout << "The medal recipient " << parameters[3] << " for " << parameters[0] << " with event " << parameters[2] << "  does not have any predecessor" << endl;
						}
						else
						{
							cout << "The predecessor of the medal recipient " << parameters[3] << " for " << parameters[0] << " with event " << parameters[2] << " is " << endl << endl;
							pre->print();
						}
					}
					else
					{
						cout << parameters[3] << " for " << parameters[0] << " with event " << parameters[2] << " not found" << endl;
					}
				}
				else if (in.substr(0, 14) == "tree_successor")
				{
					string parameter = in.substr(15);
					int i = 0;
					int pos = parameter.find(",");
					int index = 0;
					string parameters[4];

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
					string key = parameters[0] + parameters[1] + parameters[2] + parameters[3];
					Athlete* temp = tree.treeSearch(tree.root, key);

					Athlete* succ;
					if (temp != tree.nil)
					{
						succ = tree.treeSuccessor(temp);
						if (succ == tree.nil)
						{
							cout << "The medal recipient " << parameters[3] << " for " << parameters[0] << " with event " << parameters[2] << "  does not have any successor" << endl;
						}
						else
						{
							cout << "The successor of the medal recipient " << parameters[3] << " for " << parameters[0] << " with event " << parameters[2] << " is " << endl << endl;
							succ->print();
						}
					}
					else
					{
						cout << parameters[3] << " for " << parameters[0] << " with event " << parameters[2] << " not found" << endl;
					}
				}
			}
		cout << endl;
		getline(std::cin, in);
		}	while (in != "quit");
	}
	catch (...)
	{
		cout << "Input error";
	}
	//_CrtDumpMemoryLeaks();
}

