/*
 Set.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the Set class. This class stores
              keys containing the template data type, a counter of attempts, and a
			  pointer. Features insert and other functions.
*/

#include "Set.h"

//Insert
//Precondition: Set and template data type exist and are valid
//Postcondition: The template data type will be placed inside a new key in the Set
template<typename T>
void Set<T>::insert(T newData)
{
	bool isUnique = true;  //Keeps track if unique or not
	bool firstHit = false;  //Makes sure you don't over count keys
	Key *temp2 = head2;

	while (temp2 != NULL && firstHit == false)  //Go through Set
	{
		if (temp2->data == newData)  //If data matches existing data
		{
			isUnique = false;  //It's not unique
			firstHit = true;  //Don't need to keep searching
			temp2->counter = temp2->counter + 1;  //Increment counter for key
		}
	temp2 = temp2->next;
	}

	if (isUnique == true)
	{
		superCounter++;  //Increment larger counter
		LinkedList<T>::insert(newData, 100);  //Also put everything in a LinkedList

		Key *n2 = new Key;  //Make a key
		n2->data = newData;  //Store the value
		n2->counter = 1;  //If unique would have appeared once

		if (head2 == NULL)  //Create first key
		{
			n2->next = NULL;
			head2 = n2;
		}
		else  //Add key to end
		{
			n2->next = NULL;
			Key *temp2 = head2;

			while (temp2->next != NULL)
			{
				temp2 = temp2->next;
			}

			temp2->next = n2;
		}
	}
	if (isUnique == false)  //If key already added, notify user
	{
		cout << "*Value " << newData << " has already been added (not unique)*" << endl;
	}
}

//Print
//Precondition: LinkedList exists and is valid
//Postcondition: Data and counter inside keys will be printed
template<typename T>
void Set<T>::print()
{
	Key *temp2 = head2;
	while (temp2 != NULL)
	{
		cout << "Attempted to add year " << temp2->data << " to the data structure " << temp2->counter << " time(s)." << endl;
		temp2 = temp2->next;
	}
	cout << getSuperCounter() << " insert(s) attempted." << endl;
}

//Get Super Counter
//Precondition: Set exists and is valid
//Postcondition: Returns number of attempts to add unique keys to Set
template<typename T>
int Set<T>::getSuperCounter() const
{
	return superCounter;
}

//Get Key Counter
//Precondition: Set exists and is valid
//Postcondition: Returns number of attempts to add that specific value
template<typename T>
int Set<T>::getKeyCounter(T targetValue)
{
	bool firstHit = false;
	Key *temp2 = head2;
	while (temp2 != NULL && firstHit == false)
	{
		if (temp2->data == targetValue)
		{
			bool firstHit = true;
			return temp2->counter;
		}
		temp2 = temp2->next;
	}
	return -1;
}

//Sort + Display Top Three
//Precondition: Set exists and is valid
//Postcondition: Sorts keys by counter and displays top three
template<typename T>
void Set<T>::sortDisplayTopThree()
{
	Key *ptr1 = head2; 
	Key *ptr2 = head2;

	for (ptr1 = head2; ptr1->next != NULL; ptr1 = ptr1->next)
	{
		for (ptr2 = head2; ptr2->next != NULL; ptr2 = ptr2->next)
		{
			if (ptr1->counter > ptr2->counter)
			{
				int tempCounter = ptr1->counter;  //Use bubble sort to move around key and counter values
				ptr1->counter = ptr2->counter;
				ptr2->counter = tempCounter;

				T temp2 = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp2;
			}
		}
	}

	Key *temp2 = head2;
	int i = 1;
	while (temp2 != NULL && i<=3)
	{
		cout << i << ") " << "Value: " << temp2->data << " Counter: " << temp2->counter << endl;  //Print out values of sorted top three
		cout << endl;
		i++;
		temp2 = temp2->next;
	}
}
