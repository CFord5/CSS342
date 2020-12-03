/*
 LinkedList.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the LinkedList class. This class stores
			  nodes containing the city object. In addition to a head and next pointers, it 
			  features a tail and previous pointer allowing thec lass to implement a doubly-
			  linked list.
*/

#include "LinkedList.h"

//Default constructor
//Precondition: None
//Postcondition: Creates new LinkedList object
LinkedList::LinkedList()
{
}

//Destructor
//Precondition: LinkedList object exists and is valid
//Postcondition: Deallocates LinkedList object
LinkedList::~LinkedList()
{
	cout << "Destructor called on LinkedList object." << endl;
}

//add(): Adds node to LinkedList object
//Precondition: LinkedList and City objects exist and are valid
//Postcondition: The City object will be placed inside a new node in the LinkedList
void LinkedList::add(City myObject)
{
	if (head == NULL)  //If the LinkedList doesn't have a head node yet, the City object will be added to a new head node
	{
		Node *n = new Node;  //A pointer is created to a new node
		n->object = myObject;  //The new node is given a City object
		n->prev = NULL;  //There should be nothing in fron of the head
		head = n;  //The head and tail are going to be the same if there is only one node
		tail = n;
		size++;  //Increment the number of nodes by one
		n = NULL;  //Have n become a nullptr
		delete n;  //Deallocate n
	}
	else  //If the LinkedList already has a head, a new node will be added after the tail
	{
		Node *n = new Node;  //A pointer is created to a new node
		n->object = myObject;  //The new node is given a City object
		n->prev = tail;  //The new node is at the end of the list, so the previous pointer should point at the old tail
		tail->next = n;  //The new node comes after the old tail, so the next pointer of the old tail should point at the new node
		tail = n;  //The new node is the new end of the list and thus the new tail
		tail->next = NULL;  //The end of the list doesn't have anything after it
		size++;  //Increment the number of nodes by one
		n = NULL;  //Have n become a nullptr
		delete n;  //Deallocate n
	}
}

//printLinkedList(): Prints the information contained in the LinkedList
//Precondition: LinkedList and City objects exist and are valid
//Postcondition: The City object information stored in the LinkedList will be printed
void LinkedList::printLinkedList()
{
	Node *temp = head;  //Create a temporary node so the head value doesn't get messed up
	while (temp != NULL)  //While there is a node
	{
		cout << "The city of " << temp->object.getName() << " has a population of " << temp->object.getPopulation() << endl;  //Print information
		temp = temp->next;  //Go to next node
	}
}

//returnSize(): Returns number of nodes in LinkedList object
//Precondition:  LinkedList object exists and has valid nodes
//Postcondition: Returns integer value of number of nodes in LinkedList
int LinkedList::returnSize() const
{
	return size;
}

//sortDescending(): Sorts the city population values from highest to lowest (insertion sort)
//Big-O Analysis: Descending sort has a Big-O of O(n^2) due to two levels of nested for-loops
//Precondition: LinkedList exists and contains valid nodes with City objects
//Postcondition: City population values will be sorted from lowest to highest
void LinkedList::sortDescending()
{
	Node *ptr1, *ptr2;  //Create two pointers helpful in the sorting process, ptr1 deals with traversing through the main LinkedList, ptr2 is for sorting magic
	City temp;  //Create a temporary City object to help in sorting process
	ptr1 = head;  //Set the helper pointers to the head of the LinkedList 
	ptr2 = head;

	for (int i = 0; i < size; i++)  //For each node in the list
	{
		temp = ptr1->object;  //Assign the object in the node to the temporary City object
		for (int j = 0; j < i; j++)  //Gets ptr2 where ptr1 is
		{
			ptr2 = ptr2->next;  //Traverse through the list (to keep up with ptr1 going through the main LinkedList)
		}
		for (int j = i; j > 0 && ptr2->prev->object.getPopulation() < temp.getPopulation(); j--)  //Compare the helper pointer with current temp City object
		{
			ptr2->object = ptr2->prev->object;  //While the previous values are smaller than the temp City object's values, move them back
			ptr2 = ptr2->prev;  //Traverse through the list
		}
		ptr2->object = temp;  //The helper pointer is assigned the value of temp
		ptr2 = head;  //The helper pointer is reset to the original head
		ptr1 = ptr1->next;  //Traverse through the list
	}
}

//sortAscending(): Sorts the city population values from lowest to highest (insertion sort), this method just flips head/tail and prev/next from the previous method
//Big-O Analysis: Ascending sort has a Big-O of O(n^2) due to two levels of nested for-loops
//Precondition: LinkedList exists and contains valid nodes with City objects
//Postcondition: City population will be sorted from highest to lowest
void LinkedList::sortAscending()
{
	Node *ptr1, *ptr2;  //Create two pointers helpful in the sorting process, ptr1 deals with traversing through the main LinkedList, ptr2 is for sorting magic
	City temp;  //Create a temporary City object to help in sorting process
	ptr1 = tail;  //Set the helper pointers to the head of the LinkedList 
	ptr2 = tail;

	for (int i = 0; i < size; i++)  //For each node in the list
	{
		temp = ptr1->object;  //Assign the object in the node to the temporary City object
		for (int j = 0; j < i; j++)  //Gets ptr2 where ptr1 is
		{
			ptr2 = ptr2->prev;  //Traverse through the list (to keep up with ptr1 going through the main LinkedList)
		}
		for (int j = i; j > 0 && ptr2->next->object.getPopulation() < temp.getPopulation(); j--)  //Compare the helper pointer with current temp City object
		{
			ptr2->object = ptr2->next->object;  //While the next values are smaller than the temp City object's values, move them forward
			ptr2 = ptr2->next;  //Traverse through the list
		}
		ptr2->object = temp;  //The helper pointer is assigned the value of temp
		ptr2 = tail;  //The helper pointer is reset to the original tail
		ptr1 = ptr1->prev;  //Traverse through the list
	}
}

//linearSearch(): Searches for City object given 
//Big-O Analysis: The search function has a Big-O of O(n) due to its single while loop
//Precondition: City object exists and input has valid name
//Postcondition: Prints the name and population of City object
void LinkedList::linearSearch(string input)
{
	bool foundInput = false;  //Boolean variable that returns true if matching value found
	Node *temp = head;  //Create a temp variable so that the head doesn't get moved

	while (temp != NULL)  //While there are nodes
	{
		if (temp->object.getName() == input)  //If the City object's name matches the input value
		{
			foundInput = true;  //Boolean value becomes true
			cout << "The city of " << temp->object.getName() << " has a population of " << temp->object.getPopulation() << endl;  //Print info
			temp = NULL;  //Stop loop
		}
		else  //If name doesn't match
		{
			temp = temp->next;  //Keep traversing list
		}	
	}

	if (foundInput == false)  //If there were no matches in the LinkedList
	{
		cout << "The inputted city name could not be found." << endl;  //Notify user
	}
}
