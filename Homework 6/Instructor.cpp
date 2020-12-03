/*
 Instructor.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the Instructor class. This class stores
			  the name along with getters and setters and inherits from Person.
*/

#include "Instructor.h"

//Default constructor
//Precondition: None
//Postcondition: Creates Instructor object
Instructor::Instructor()
{
}

//Constructor
//Precondition: String and Person exists and are valid
//Postcondition: Creates initialized Instructor object with Person constructor
Instructor::Instructor(string newName):Person(newName)
{
}

//Destructor
//Precondition: Instructor object exists
//Postcondition: Deletes Instructor object
Instructor::~Instructor()
{
}
