/*
 Set.h
 Author: Chandler Ford
 Description: This is the header file for the Set class. This class stores
			  keys containing the template data type, a counter of attempts,
			  and a pointer. Features insert and other functions.
*/

#pragma once
#include "LinkedList.h"

//Uses templates
template <typename T>
class Set:public LinkedList<T>
{
public:
	//Insert
	//Precondition: Set and template data type exist and are valid
	//Postcondition: The template data type will be placed inside a new key in the Set
	void insert(T newData);
	
	//Print
	//Precondition: LinkedList exists and is valid
	//Postcondition: Data and counter inside keys will be printed
	void print();

	//Get Super Counter
	//Precondition: Set exists and is valid
	//Postcondition: Returns number of attempts to add unique keys to Set
	int getSuperCounter() const;

	//Get Key Counter
	//Precondition: Set exists and is valid
	//Postcondition: Returns number of attempts to add that specific value
	int getKeyCounter(T targetValue);

	//Sort + Display Top Three
	//Precondition: Set exists and is valid
	//Postcondition: Sorts keys by counter and displays top three
	void sortDisplayTopThree();

private:
	//Used to store unique key values of Set and their counters
	struct Key
	{
		Key *next;
		T data;
		int counter;
	};

	//Keeps track of beginning of Set keys
	Key *head2;

	//Keeps track of number of attempts to add unique keys to Set
	int superCounter;
};
