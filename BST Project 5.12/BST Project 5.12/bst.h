#include <string>
using namespace std;

class Node
{
public:
	char Key; //ordering element
	int Value;
	Node* Lt;
	Node* Rt;

	Node(char k, int v)
	{
		Key = k;
		Value = v;
		Lt = Rt = nullptr;
	}
};

//Class definition for a Binary Search Tree
class BST
{
public:

	//constructor
	BST();

	//Destructor
	~BST();

	//Insert BST
	void Insert(char, int);

	//print out the entire list
	void Print();

	//get height of BST
	int Height();

private:

	//helper functions
	void PrintInorder(Node*);
	void PostOrderDeleteTree(Node*);
	int GetHeight(Node*);

	void IncFreq(Node*);

	Node* Root;
};

