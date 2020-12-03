/*
 BinaryTree.cpp
 Author: Chandler Ford
 Description: This is the driver file for the BinaryTree class. This file creates
			  three different Binary Trees and sorts each one three ways.
*/

#include "BinaryTree.h"

int main()
{
	//INTRODUCTION
	cout << "HOMEWORK 5: TREE TRAVERSALS" << endl;
	cout << "Created by Chandler Ford for CSS 342 B." << endl;
	cout << endl;

	//LEFT UNBALANCED
	BinaryTree leftUnbalanced;  //Create BinaryTree 

	leftUnbalanced.insert(30);  //Add items
	leftUnbalanced.insert(10);
	leftUnbalanced.insert(5);
	leftUnbalanced.insert(1);
	leftUnbalanced.insert(2);
	leftUnbalanced.insert(8);
	leftUnbalanced.insert(7);
	leftUnbalanced.insert(9);
	leftUnbalanced.insert(15);
	leftUnbalanced.insert(20);
	leftUnbalanced.insert(40);

	cout << "---------------------------------------" << endl;
	cout << "LEFT-UNBALANCED TREE DEMONSTRATION" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Pre-Order Traversal:" << endl;  //Pre-Order
	leftUnbalanced.preOrder();
	cout << endl;
	cout << "Post-Order Traversal:" << endl;  //Post-Order
	leftUnbalanced.postOrder();
	cout << endl;
	cout << "In-Order Traversal:" << endl;  //In-Order
	leftUnbalanced.inOrder();

	//RIGHT UNBALANCED
	BinaryTree rightUnbalanced;  //Create BinaryTree

	rightUnbalanced.insert(30);  //Add items
	rightUnbalanced.insert(10);
	rightUnbalanced.insert(40);
	rightUnbalanced.insert(35);
	rightUnbalanced.insert(34);
	rightUnbalanced.insert(36);
	rightUnbalanced.insert(50);
	rightUnbalanced.insert(49);
	rightUnbalanced.insert(55);
	rightUnbalanced.insert(52);
	rightUnbalanced.insert(60);

	cout << "---------------------------------------" << endl;
	cout << "RIGHT-UNBALANCED TREE DEMONSTRATION" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Pre-Order Traversal:" << endl;  //Pre-Order
	rightUnbalanced.preOrder();
	cout << endl;
	cout << "Post-Order Traversal:" << endl;  //Post-Order
	rightUnbalanced.postOrder();
	cout << endl;
	cout << "In-Order Traversal:" << endl;  //In-Order
	rightUnbalanced.inOrder();

	//SYMMETRICAL
	BinaryTree symmetrical;  //Create BinaryTree

	symmetrical.insert(30);  //Add items
	symmetrical.insert(10);
	symmetrical.insert(5);
	symmetrical.insert(4);
	symmetrical.insert(3);
	symmetrical.insert(2);
	symmetrical.insert(40);
	symmetrical.insert(45);
	symmetrical.insert(50);
	symmetrical.insert(51);
	symmetrical.insert(60);

	cout << "---------------------------------------" << endl;
	cout << "SYMMETRICAL TREE DEMONSTRATION" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Pre-Order Traversal:" << endl;  //Pre-Order
	symmetrical.preOrder();
	cout << endl;
	cout << "Post-Order Traversal:" << endl;  //Post-Order
	symmetrical.postOrder();
	cout << endl;
	cout << "In-Order Traversal:" << endl;  //In-Order
	symmetrical.inOrder();
	
	cout << endl;
	//system("PAUSE");
	return 0;
}