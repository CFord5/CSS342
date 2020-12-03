/*
 LinkedList.h
 Author: Chandler Ford
 Description: This is the header file for the LinkedList class. This class stores
			  nodes containing the city object. In addition to a head and next
			  pointers, it features a tail and previous pointer allowing the 
			  class to implement a doubly-linked list.
*/

#pragma once
#include "City.h"

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

	//add(): Adds node to LinkedList object
	//Precondition: LinkedList and City objects exist and are valid
	//Postcondition: The City object will be placed inside a new node in the LinkedList
	void add(City myObject);

	//printLinkedList(): Prints the information contained in the LinkedList
	//Precondition: LinkedList and City objects exist and are valid
	//Postcondition: The City object information stored in the LinkedList will be printed
	void printLinkedList();

	//returnSize(): Returns number of nodes in LinkedList object
	//Precondition:  LinkedList object exists and has valid nodes
	//Postcondition: Returns integer value of number of nodes in LinkedList
	int returnSize() const;

	//sortDescending(): Sorts the city population values from highest to lowest
	//Precondition: LinkedList exists and contains valid nodes with City objects
	//Postcondition: City population values will be sorted from lowest to highest
	void sortDescending();

	//sortAscending(): Sorts the city population values from lowest to highest
	//Precondition: LinkedList exists and contains valid nodes with City objects
	//Postcondition: City population will be sorted from highest to lowest
	void sortAscending();

	//linearSearch(): Searches for City object given name
	//Precondition: City object exists and input has valid name
	//Postcondition: Prints the name and population of City object
	void linearSearch(string input);
private:
	//Creates Node with a City object and two pointers
	struct Node
	{
		Node *next;  //Points to next node in list
		Node *prev;  //Points to previous node in list
		City object;  //Holds city object
	};
	
	//Used to keep track of beginning and end of list
	Node *head;
	Node *tail;

	//Used to keep track of the number of nodes
	int size;
};

