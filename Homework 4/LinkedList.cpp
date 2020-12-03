/*
 LinkedList.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the LinkedList class. This class stores
              nodes containing the template data type and a pointer. Features get,
              insert, and delete functions and more.
*/

#include "LinkedList.h"

//Default constructor
//Precondition: None
//Postcondition: Creates new LinkedList object
template <typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	size = 0;
}

//Destructor
//Precondition: LinkedList object exists and is valid
//Postcondition: Deallocates LinkedList object
template <typename T>
LinkedList<T>::~LinkedList()
{
	cout << "*Deleting LinkedList*" << endl;
}

//Get
//Precondition: Integer exists and is a valid location
//Postcondition: Node at location will be returned
template<typename T>
T LinkedList<T>::get(int position)
{
	Node *temp = head;
	if (position == 0)  //Return node from start
	{
		return temp->data;
	}
	else if (position > size)  //Return node from end
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->data;
	}
	else if (head == NULL)  //If node is null
	{
		cout << "*Cannot get node from empty list*" << endl; 
		return -1;
	}
	else  //If node is in the middle
	{
		for (int i = 0; i < position; i++)  //Loop through until position reached
		{
			temp = temp->next;
		}
		return temp->data;
	}
}

//Insert
//Precondition: LinkedList and template data type exist and are valid
//Postcondition: The template data type will be placed inside a new node in the LinkedList
template<typename T>
void LinkedList<T>::insert(T newData, int position)
{
	Node *n = new Node;  //Make a new Node
	n->data = newData;

	if (head == NULL)  //Create node
	{
		n->next = NULL;
		head = n;
		size++;
	}
	else if (position == 0)  //Place at start of LinkedList
	{
		n->next = head;
		head = n;
		size++;
	}
	else if (position > size)  //Place at end of LinkedList
	{
		n->next = NULL;
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
		size++;
	}
	else  //Place in middle of LinkedList
	{
		Node *previous = new Node;  //Make two pointers
		Node *current = new Node;
		current = head;  //Start one at the head
		for (int i = 0; i < position; i++)
		{
			previous = current;  //Previous node lags behind
			current = current->next;  //Iterate through
		}
		previous->next = n;  //Node goes after previous 
		n->next = current;  //And before current
		//delete previous;
		//delete current;
	}
	//delete n;
}

//Delete
//Precondition: Integer exists and is a valid location
//Postcondition: Node at location will be deleted
template<typename T>
void LinkedList<T>::deleteN(int position)
{
	Node *temp = new Node;  //Use temp to help manage deletion
	if (position == 0)  //Delete from start
	{
		temp = head;
		head = head->next;
		size--;
	}
	else if (position > size)  //Delete from end
	{
		Node *previous = new Node;
		temp = head;
		while (temp->next != NULL)
		{
			previous = temp;
			temp = temp->next;
		}
		previous->next = NULL;
		size--;
	}
	else if (head == NULL)  //If node is null
	{
		cout << "*Cannot delete node from empty list*" << endl;
	}
	else  //If node is in hte middle
	{
		Node *previous = new Node;
		temp = head;
		for (int i = 0; i < position; i++)  //Loop through until you get to it
		{
			previous = temp;  //Previous lags behind
			temp = temp->next;  //Iterate through
		}
		previous->next = temp->next;  //Skip over one
		size--;
		//delete previous;
	}
	//delete temp;
}

//Print
//Precondition: LinkedList exists and is valid
//Postcondition: Data inside nodes will be printed
template<typename T>
void LinkedList<T>::print()
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

//Get Size
//Precondition: LinkedList exists and is valid
//Postcondition: Number of nodes in LinkedList will be returned
template<typename T>
int LinkedList<T>::getSize()
{
	return size;
}

//Increment Size
//Precondition: LinkedList exists and is valid
//Postcondition: Size of LinkedList will be increased by one
template<typename T>
void LinkedList<T>::incrementSize()
{
	size++;
}
