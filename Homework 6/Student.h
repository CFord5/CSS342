/*
 Student.h
 Author: Chandler Ford
 Description: This is the header file for the Student class. This class stores
			  the name along with getters and setters and inherits from Person.
*/

#include "Person.h"

#pragma once
class Student : public Person  //Inheritance
{
public:
	//Default constructor
	//Precondition: None
	//Postcondition: Creates Student object
	Student();

	//Constructor
	//Precondition: String and Person exists and are valid
	//Postcondition: Creates initialized Student object with Person constructor
	Student(string newName);

	//Destructor
	//Precondition: Student object exists
	//Postcondition: Deletes Student object
	~Student();
};

