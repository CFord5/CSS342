/*
 City.cpp
 Author: Chandler Ford
 Description: This is the header file for the City class. This class stores
			  the name and population of cities and has constructors and
			  a destructor along with accessor/mutator methods.
*/

#include "City.h"

//Default constructor
//Precondition: None
//Postcondition: Creates new City object
City::City()
{
}

//Constructor with input parameters
//Precondition: Integer input value is not negative
//Postcondition: Initializes data members with input parameters
City::City(int myPopulation, string myName)
{
	setPopulation(myPopulation);
	setName(myName);
}

//Destructor
//Precondition: City object contains valid data member values
//Postcondition: Deallocates city object
City::~City()
{
	//cout << "Destructor called on City object: " << name << endl;
}

//setPopulation(): Mutator method that allows the city population to be set
//Precondition: Input value exists and isn't negative
//Postcondition: Value of city population will be set
void City::setPopulation(int myPopulation)
{
	if (myPopulation >= 0)  //Population can't be negative
	{
		population = myPopulation;
	}
	else
	{
		population = 0;  //Negative numbers get set to zero
		cout << "Error! Population can't be negative!" << endl;  //Notify user
	}
}

//getPopulation(): Accessor method for population
//Precondition: The population value exists and isn't negative
//Postcondition: Returns integer value of population
int City::getPopulation() const
{
	if (population >= 0)  //Population can't be negative
	{
		return population;
	}
	else
	{
		cout << "Error! Population can't be negative!" << endl;  //Notify user
		return 0;  //Return zero if negative
	}
}

//setName(): Mutator method to set the name of the city
//Precondition: Input is valid string
//Postcondition: Name of city will be set
void City::setName(string myName)
{
	name = myName;
}

//getName(): Accessor method for population
//Precondition: Input value exists and is a valid string
//Postcondition: Name of city will be returned
string City::getName() const
{
	return name;
}
