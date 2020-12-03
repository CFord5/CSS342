/*
 BagOfMarbles.cpp
 Author: Chandler Ford 
 Description: This is the implementation file for the BagOfMarbles class. This class stores three
              different kind of marbles and has accessors, mutators, and some overloaded operators.
*/

#include "BagOfMarbles.h"
#include <iostream>
using namespace std;

//Default constructor
//Precondition: None
//Postcondition: Create new BagOfMarbles object
BagOfMarbles::BagOfMarbles()
{
}

//Constructor with input parameters
//Precondition: Input values are not negative numbers
//Postcondition: Able to create BagOfMarbles object and set number of red, green, and blue marbles
BagOfMarbles::BagOfMarbles(int numRed, int numGreen, int numBlue)
{
	setRedMarble(numRed);
	setGreenMarble(numGreen);
	setBlueMarble(numBlue);
}

//Destructor
//Preconditon: BagOfMarbles contains valid red, green, and blue marble values
//Postcondition: Deallocate BagOfMarbles object
BagOfMarbles::~BagOfMarbles()
{
}

//setBagOfMarbles(): Mutator method that allows the number of red, green, and blue marbles to be set
//Precondition: Input values are valid red, green, and blue marble values
//Postcondition: Value of red, green, and blue marbles will be set
void BagOfMarbles::setBagOfMarbles(int numRed, int numGreen, int numBlue)
{
	setRedMarble(numRed);
	setGreenMarble(numGreen);
	setBlueMarble(numBlue);
}


//setRedMarble(): Mutator method for red marbles
//Precondition: Input value isn't negative
//Postcondition: Value of red marbles will be set
bool BagOfMarbles::setRedMarble(int numRed)
{
	if (numRed < 0)
	{
		cout << "ERROR: Marble value can't be negative!" << endl;  //Notify user of invalid value
		redMarble = 0;  //Replace negative input value with zero
		return false;  //Number of marbles can't be less than zero
	}
	else
	{
		redMarble = numRed;
		return true;
	}
}

//getRedMarble(): Accessor method for red marbles
//Precondition: The number of red marbles exists
//Postcondition: Returns interger value of red marbles
int BagOfMarbles::getRedMarble() const
{
	if (redMarble >= 0)  //Returns value if valid
	{
		return redMarble;  
	}
	else
	{
		cout << "ERROR: Marble value can't be negative!" << endl;
	}
}

//setGreenMarble(): Mutator method for green marbles
//Precondition: Input value isn't negative
//Postcondition: Value of green marbles will be set
bool BagOfMarbles::setGreenMarble(int numGreen)
{
	if (numGreen < 0)
	{
		cout << "ERROR: Marble value can't be negative!" << endl;  //Notify user of invalid value
		greenMarble = 0;  //Replace negative input value with zero
		return false;  //Number of marbles can't be less than zero
	}
	else
	{
		greenMarble = numGreen;
		return true;
	}
}

//getGreenMarble(): Accessor method for green marbles
//Precondition: The number of green marbles exists
//Postcondition: Returns interger value of green marbles
int BagOfMarbles::getGreenMarble() const
{
	if (greenMarble >= 0)  //Returns value if valid
	{
		return greenMarble;
	}
	else
	{
		cout << "ERROR: Marble value can't be negative!" << endl;
	}
}

//setBlueMarble(): Mutator method for blue marbles
//Precondition: Input value isn't negative
//Postcondition: Value of blue marbles will be set
bool BagOfMarbles::setBlueMarble(int numBlue)
{
	if (numBlue < 0)
	{
		cout << "ERROR: Marble value can't be negative!" << endl;  //Notify user of invalid value
		blueMarble = 0;  //Replace negative input value with zero
		return false;  //Number of marbles can't be less than zero
	}
	else
	{
		blueMarble = numBlue;
		return true;
	}
}

//getBlueMarble(): Accessor method for blue marbles
//Precondition: The number of blue marbles is valid
//Postcondition: Returns interger value of blue marbles
int BagOfMarbles::getBlueMarble() const
{
	if (blueMarble >= 0)  //Returns value if valid
	{
		return blueMarble;
	}
	else 
	{
		cout << "ERROR: Marble value can't be negative!" << endl;
	}
}

//operator+: Overloads the + operator, allowing two BagOfMarble objects to be added
//Precondition: BagOfMarbles exists and is a valid object
//Postcondition: The red, green, and blue marble values of both objects are added together
BagOfMarbles BagOfMarbles::operator+(const BagOfMarbles &rhs) const
{
	BagOfMarbles result = *this;
	result.redMarble += rhs.redMarble;
	result.greenMarble += rhs.greenMarble;
	result.blueMarble += rhs.blueMarble;
	return result;
}

//operator +=: Overloads the += operator, allowing the += operation to work with two BagOfMarbles objects
//Precondition: BagOfMarbles exists and is a valid object
//Postcondition: The red, green, and blue marble values of the first object are set equal to the value of the
//first objects red, green, and blue marbles added to the second objects red, green, and blue marbles
BagOfMarbles & BagOfMarbles::operator+=(const BagOfMarbles & rhs)
{
	redMarble = redMarble + rhs.redMarble;
	greenMarble = greenMarble + rhs.greenMarble;
	blueMarble = blueMarble + rhs.blueMarble;
	return *this;
}

//operator ==: Overloads the == operator to compare two BagOfMarbles objects
//Precondition: BagOfMarbles exists and is a valid object
//Postcondition: Returns true if they have the same number of red, green, and blue marbles, false if not
bool BagOfMarbles::operator==(const BagOfMarbles &rhs) const
{
	return ((redMarble == rhs.redMarble) && (greenMarble == rhs.greenMarble) && (blueMarble == rhs.blueMarble));
}
