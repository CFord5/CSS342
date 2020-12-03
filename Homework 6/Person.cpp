/*
 Person.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the Person class. This class stores
			  the name along with getters and setters and serves as a parent class.
*/

#include "Person.h"

//Default constructor
//Precondition: None
//Postcondition: Creates Person object
Person::Person()
{
	name = "";
}

//Constructor
//Precondition: String exists and is valid
//Postcondition: Creates initialized Person object
Person::Person(string newName)
{
	setName(newName);
}

//Destructor
//Precondition: Person object exists
//Postcondition: Deletes Person object
Person::~Person()
{
}

//setName
//Precondition: String exists and is valid
//Postcondition: Name will be set to parameter argument
void Person::setName(string newName)
{
	name = newName;
}

//getName
//Precondition: Name exists and is valid
//Postcondition: Returns name 
string Person::getName() const
{
	return name;
}
