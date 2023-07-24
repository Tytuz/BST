// Titus D Foster
// Binary Search Tree


//When run, the purpose of this program is to take a user inputted string (ending whenever '$' is input) and put it in a binary search tree. It then calculates the height of the tree.
//After that it then prints the inorder traversal of the tree and then deletes the tree in post order style.

#include <iostream>
#include "bst.h"
#include <string>
using namespace std;

int main()
{
	//create BST wordlist object
	BST wordlist;

	//get string and insert into BST
	string line;
	char CharToInsert;
	getline(cin, line);

	while (line != "$")
	{
		for (int i = 0; i < line.size(); i++) {

			char CharToInsert = line[i];
			wordlist.Insert(CharToInsert, 1);

		}
		getline(cin, line);
	}

	//print height
	cout << "The height of the tree is " << wordlist.Height() << endl;
	
	//print inorder traversal
	wordlist.Print();

	//DESTRUCTOR CALLED HERE - PRINT OUT THE NODE VALUE BEFORE IT IS DELETED
	return 0;
}