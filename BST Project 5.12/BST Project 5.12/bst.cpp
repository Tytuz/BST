#include <iostream>
#include "bst.h"

using namespace std;

BST::BST() {
	
Root = nullptr;

}
//0 Errors

BST::~BST() {

	PostOrderDeleteTree(Root);

}
//0 Errors

void BST::PostOrderDeleteTree(Node* current) {

	if (current != nullptr) {
		PostOrderDeleteTree(current->Lt);
		PostOrderDeleteTree(current->Rt);
		if (isspace(current->Key)) {
			cout << "SPACE DELETED" << endl;
			delete current;
		}
		else {
			cout << current->Key << " DELETED" << endl;
			delete current;
		}
	}
}
//0 Errors

int BST::Height() {

	return GetHeight(Root);

}
//0 Errors

int BST::GetHeight(Node* current) {

	if (!current) 
		return -1;
	
	int leftHeight = GetHeight(current->Lt);
	int rightHeight = GetHeight(current->Rt);
	return (leftHeight >= rightHeight) ? 1 + leftHeight : 1 + rightHeight;

}
//0 Errors

void BST::Insert(char k, int v)
{
	//get dynamic memory, if unable return message to client
	Node* newnode = new Node(k, v);
	if (newnode == nullptr)
	{
		cout << "Error allocating memory" << endl;
		return;
	}

	//insert node in tree, if tree empty this becomes the root
	if (Root == nullptr)
		Root = newnode;
	else
	{
		//tree not empty, find insertion point and insert as leaf
		Node* current = Root;
		Node* parent = nullptr;

		//find insertion spot, parent will point to insertion node
		while (current != nullptr)
		{
			parent = current;
			if (newnode->Key < current->Key)
				current = current->Lt;
			else if (newnode->Key > current->Key)
				current = current->Rt;
			else {
				IncFreq(current);
				return;
			}

		}

		//link node to parent
		if (newnode->Key <= parent->Key)
			parent->Lt = newnode;
		else
			parent->Rt = newnode;
		
	}
	
}
//0 Errors

void BST::IncFreq(Node* p) {

	p->Value++;

}
//0 Errors

void BST::Print() {

	PrintInorder(Root);

}
//0 Errors

void BST::PrintInorder(Node* current) {

	if (current != nullptr) {

		PrintInorder(current->Lt);
		if (isspace(current->Key))
			cout << "SPACE  " << current->Value << endl;
		else
		cout << current->Key << "  " << current->Value << endl;
		PrintInorder(current->Rt);

	}
	
}
//0 Errors

