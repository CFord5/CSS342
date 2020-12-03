/*
 Student.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the Student class. This class stores
			  the name along with getters and setters and inherits from Person.
*/

#include "Student.h"

//Default constructor
//Precondition: None
//Postcondition: Creates Student object
Student::Student()
{
}

//Constructor
//Precondition: String and Person exists and are valid
//Postcondition: Creates initialized Student object with Person constructor
Student::Student(string newName):Person(newName)
{
}

//Destructor
//Precondition: Student object exists
//Postcondition: Deletes Student object
Student::~Student()
{
}
