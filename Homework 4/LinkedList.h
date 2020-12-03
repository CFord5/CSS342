/*
 LinkedList.h
 Author: Chandler Ford
 Description: This is the header file for the LinkedList class. This class stores
			  nodes containing the template data type and a pointer. Features get,
			  insert, and delete functions and more.
*/

#pragma once
#include <iostream>
using namespace std;

//Uses templates
template <typename T>
class LinkedList
{
public:
	//Default constructor
	//Precondition: None
	//Postcondition: Creates new LinkedList object
	LinkedList();

	//Destructor
	//Precondition: LinkedList object exists and is valid
	//Postcondition: Deallocates LinkedList object
	~LinkedList();

	//Get
	//Precondition: Integer exists and is a valid location
	//Postcondition: Node at location will be returned
	T get(int position);

	//Insert
	//Precondition: LinkedList and template data type exist and are valid
	//Postcondition: The template data type will be placed inside a new node in the LinkedList
	void insert(T newData, int position);

	//Delete
	//Precondition: Integer exists and is a valid location
	//Postcondition: Node at location will be deleted
	void deleteN(int position);
	
	//Print
	//Precondition: LinkedList exists and is valid
	//Postcondition: Data inside nodes will be printed
	void print();

	//Get Size
	//Precondition: LinkedList exists and is valid
	//Postcondition: Number of nodes in LinkedList will be returned
	int getSize();

	//Increment Size
	//Precondition: LinkedList exists and is valid
	//Postcondition: Size of LinkedList will be increased by one
	void incrementSize();

private:
	//Used to create nodes of the LinkedList
	struct Node
	{
		Node *next;
		T data;
	};

	//Keeps track of beginning of LinkedList
	Node *head;

	//Used to keep track of the number of nodes
	int size;

};

