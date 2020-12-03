/*
 BagOfMarbles.h
 Author: Chandler Ford
 Description: This is the header file for the BagOfMarbles class. This class stores three different
              kind of marbles and has accessors, mutators, and some overloaded operators.
*/

#pragma once
#include <iostream>
using namespace std;

class BagOfMarbles
{
public:
	//Default constructor
	//Precondition: None
	//Postcondition: Create new BagOfMarbles object
	BagOfMarbles();

	//Constructor with input parameters
	//Precondition: Input values are not negative numbers
	//Postcondition: Able to create BagOfMarbles object and set number of red, green, and blue marbles
	BagOfMarbles(int numRed, int numGreen, int numBlue);

	//Destructor
	//Preconditon: BagOfMarbles contains valid red, green, and blue marble values
	//Postcondition: Deallocate BagOfMarbles object
	~BagOfMarbles();

	//setBagOfMarbles(): Mutator method that allows the number of red, green, and blue marbles to be set
	//Precondition: Input values are valid red, green, and blue marble values
	//Postcondition: Value of red, green, and blue marbles will be set
	void setBagOfMarbles(int numRed, int numGreen, int numBlue);

	//setRedMarble(): Mutator method for red marbles
	//Precondition: Input value isn't negative
	//Postcondition: Value of red marbles will be set
	bool setRedMarble(int numRed);

	//getRedMarble(): Accessor method for red marbles
	//Precondition: The number of red marbles exists
	//Postcondition: Returns interger value of red marbles
	int getRedMarble() const;

	//setGreenMarble(): Mutator method for green marbles
	//Precondition: Input value isn't negative
	//Postcondition: Value of green marbles will be set
	bool setGreenMarble(int numGreen);

	//getGreenMarble(): Accessor method for green marbles
	//Precondition: The number of green marbles exists
	//Postcondition: Returns interger value of green marbles
	int getGreenMarble() const;

	//setBlueMarble(): Mutator method for blue marbles
	//Precondition: Input value isn't negative
	//Postcondition: Value of blue marbles will be set
	bool setBlueMarble(int numBlue);

	//getBlueMarble(): Accessor method for blue marbles
	//Precondition: The number of blue marbles is valid
	//Postcondition: Returns interger value of blue marbles
	int getBlueMarble() const;

	//operator+: Overloads the + operator, allowing two BagOfMarble objects to be added
	//Precondition: BagOfMarbles exists and is a valid object
	//Postcondition: The red, green, and blue marble values of both objects are added together
	BagOfMarbles operator+(const BagOfMarbles &rhs) const;

	//operator +=: Overloads the += operator, allowing the += operation to work with two BagOfMarbles objects
	//Precondition: BagOfMarbles exists and is a valid object
	//Postcondition: The red, green, and blue marble values of the first object are set equal to the value of the
	//first objects red, green, and blue marbles added to the second objects red, green, and blue marbles
	BagOfMarbles& operator+=(const BagOfMarbles &rhs);

	//operator ==: Overloads the == operator to compare two BagOfMarbles objects
	//Precondition: BagOfMarbles exists and is a valid object
	//Postcondition: Returns true if they have the same number of red, green, and blue marbles, false if not
	bool operator==(const BagOfMarbles &rhs) const;
private:
	//Data members
	int redMarble;
	int greenMarble;
	int blueMarble;
};

