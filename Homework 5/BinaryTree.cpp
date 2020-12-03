/*
 BinaryTree.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the BinaryTree class. This class stores
              nodes in a tree data structure and has insertion method along with
			  several traversal methods.
*/

#include "BinaryTree.h"

//Default constructor
//Precondition: None
//Postcondition: Creates a new BinaryTree object
BinaryTree::BinaryTree()
{
	root = NULL;
}

//Destructor
//Precondition: BinaryTree object exists and is valid
//Postcondition: BinaryTree object will be deallocated
BinaryTree::~BinaryTree()
{
	cout << "*Deleted Binary Tree*" << endl;
}

//Insert
//Precondition: BinaryTree object exists and is valid
//Postcondition: Item inserted either to the left or right depending on value
void BinaryTree::insert(int newData)
{
	Node *n = new Node;  //Create new node to hold input
	n->data = newData;
	n->left = NULL;
	n->right = NULL;

	if (root == NULL)  //If there is no root, set the root to the new node
	{
		root = n;
	}
	else
	{
		Node *temp = root;  //Set a temporary pointer node equal to the root
		bool inserted = false;  //Keeps track of if the new node has been placed yet

		while (!inserted)  //While the new node hasn't been placed yet
		{
			if (n->data < temp->data)  //If the new nodes data is less than the current pointer nodes data
			{
				if (temp->left == NULL)  //If the there is no left child node
				{
					temp->left = n;  //Set the left child node to the new node
					inserted = true;  //Set boolean to true
				}
				else  //If there is a left child node
				{
					temp = temp->left;  //Traverse to it
				}
			}
			else  //If the new nodes data isn't less than the current pointer nodes data
			{
				if (temp->right == NULL)  //If the there is no right child node
				{
					temp->right = n;  //Set the right child node to the new node
					inserted = true;  //Set boolean to true
				}
				else  //If there is a right child node
				{
					temp = temp->right;  //Traverse to it
				}
			}
		}
	}
}

//Pre-Order Wrapper
//Precondition: Root and BinaryTree exist and are valid
//Postcondition: Parent nodes will be traversed and printed before children
void BinaryTree::preOrder()
{
	if (root == NULL) return;  //Break if there node is null

	cout << root->data << endl;  //Print node data
	preOrder(root->left);  //Recursively traverse left
	preOrder(root->right);  //Recursively traverse right
}

//Pre-Order
//Precondition: Root and BinaryTree exist and are valid
//Postcondition: Parent nodes will be traversed and printed before children
void BinaryTree::preOrder(Node *root)
{
	if (root == NULL) return;  //Break if node is null

	cout << root->data << endl;  //Print node data
	preOrder(root->left);  //Recursively traverse left
	preOrder(root->right);   //Recursively traverse right
}

//Post-Order Wrapper
//Precondition: Root and BinaryTree exist and are valid
//Postcondition: Children nodes will be traversed and printed before parents
void BinaryTree::postOrder()
{
	if (root == NULL) return;  //Break if node is null

	postOrder(root->left);  //Recursively traverse left
	postOrder(root->right);  //Recursively traverse right
	cout << root->data << endl;  //Print node data
}

//Post-Order
//Precondition: Root and BinaryTree exist and are valid
//Postcondition: Children nodes will be traversed and printed before parents
void BinaryTree::postOrder(Node *root)
{
	if (root == NULL) return;  //Break if node is null

	postOrder(root->left);  //Recursively traverse left
	postOrder(root->right);  //Recursively traverse right
	cout << root->data << endl;  //Print node data
}

//In-Order Wrapper
//Precondition: Root and BinaryTree exist and are valid
//Postcondition: Nodes will be traversed and printed from lowest to highest
void BinaryTree::inOrder()
{
	if (root == NULL) return;  //Break if node is null

	inOrder(root->left);  //Recursively traverse left
	cout << root->data << endl;  //Print node data
	inOrder(root->right);  //Recursively traverse right
}

//In-Order
//Precondition: Root and BinaryTree exist and are valid
//Postcondition: Nodes will be traversed and printed from lowest to highest
void BinaryTree::inOrder(Node * root)
{
	if (root == NULL) return;  //Break if node is null

	inOrder(root->left);  //Recursively traverse left
	cout << root->data << endl;  //Print node data
	inOrder(root->right);  //Recursively traverse right
}
