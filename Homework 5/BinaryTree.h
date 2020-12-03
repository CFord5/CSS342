/*
 BinaryTree.h
 Author: Chandler Ford
 Description: This is the header file for the BinaryTree class. This class stores
			  nodes in a tree data structure and has insertion method along with
			  several traversal methods.
*/

#include <iostream>
#include <queue>
using namespace std;

#pragma once
class BinaryTree
{
private:
	struct Node  //Creates Node with int value and two pointers
	{
		int data;
		Node *left;
		Node *right;
	};
	Node *root;  //Used to keep track of BinaryTree root
public:
	//Default constructor
	//Precondition: None
	//Postcondition: Creates a new BinaryTree object
	BinaryTree();

	//Destructor
	//Precondition: BinaryTree object exists and is valid
	//Postcondition: BinaryTree object will be deallocated
	~BinaryTree();

	//Insert
	//Precondition: BinaryTree object exists and is valid
	//Postcondition: Item inserted either to the left or right depending on value
	void insert(int newData);

	//Pre-Order Wrapper
	//Precondition: Root and BinaryTree exist and are valid
	//Postcondition: Parent nodes will be traversed and printed before children
	void preOrder();

	//Pre-Order
	//Precondition: Root and BinaryTree exist and are valid
	//Postcondition: Parent nodes will be traversed and printed before children
	void preOrder(Node *root);

	//Post-Order Wrapper
	//Precondition: Root and BinaryTree exist and are valid
	//Postcondition: Children nodes will be traversed and printed before parents
	void postOrder();

	//Post-Order
	//Precondition: Root and BinaryTree exist and are valid
	//Postcondition: Children nodes will be traversed and printed before parents
	void postOrder(Node *root);

	//In-Order Wrapper
	//Precondition: Root and BinaryTree exist and are valid
	//Postcondition: Nodes will be traversed and printed from lowest to highest
	void inOrder();

	//In-Order
	//Precondition: Root and BinaryTree exist and are valid
	//Postcondition: Nodes will be traversed and printed from lowest to highest
	void inOrder(Node *root);
};