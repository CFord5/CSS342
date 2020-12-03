/*
 Instructor.h
 Author: Chandler Ford
 Description: This is the header file for the Instructor class. This class stores
			  the name along with getters and setters and inherits from Person.
*/

#include "Person.h"

#pragma once
class Instructor : public Person  //Inheritance
{
public:
	//Default constructor
	//Precondition: None
	//Postcondition: Creates Instructor object
	Instructor();

	//Constructor
	//Precondition: String and Person exists and are valid
	//Postcondition: Creates initialized Instructor object with Person constructor
	Instructor(string newName);

	//Destructor
	//Precondition: Instructor object exists
	//Postcondition: Deletes Instructor object
	~Instructor();
};

