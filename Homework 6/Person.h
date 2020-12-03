/*
 Person.h
 Author: Chandler Ford
 Description: This is the header file for the Person class. This class stores
		      the name along with getters and setters and serves as a parent class.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#pragma once
class Person
{
public:
	//Default constructor
	//Precondition: None
	//Postcondition: Creates Person object
	Person();

	//Constructor
	//Precondition: String exists and is valid
	//Postcondition: Creates initialized Person object
	Person(string newName);

	//Destructor
	//Precondition: Person object exists
	//Postcondition: Deletes Person object
	~Person();

	//setName
	//Precondition: String exists and is valid
	//Postcondition: Name will be set to parameter argument
	void setName(string newName);

	//getName
	//Precondition: Name exists and is valid
	//Postcondition: Returns name 
	string getName() const;
private:
	//Data members
	string name;
};

