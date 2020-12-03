/*
 City.h
 Author: Chandler Ford
 Description: This is the header file for the City class. This class stores
			  the name and population of cities and has constructors and 
			  a destructor along with accessor/mutator methods.
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class City
{
public:
	//Default constructor
	//Precondition: None
	//Postcondition: Creates new City object
	City();

	//Constructor with input parameters
	//Precondition: Integer input value is not negative
	//Postcondition: Initializes data members with input parameters
	City(int myPopulation, string myName);

	//Destructor
	//Precondition: City object contains valid data member values
	//Postcondition: Deallocates city object
	~City();

	//setPopulation(): Mutator method that allows the city population to be set
	//Precondition: Input value exists and isn't negative
	//Postcondition: Value of city population will be set
	void setPopulation(int myPopulation);

	//getPopulation(): Accessor method for population
	//Precondition: The population value exists and isn't negative
	//Postcondition: Returns integer value of population
	int getPopulation() const;

	//setName(): Mutator method to set the name of the city
	//Precondition: Input is valid string
	//Postcondition: Name of city will be set
	void setName(string myName);

	//getName(): Accessor method for population
	//Precondition: Input value exists and is a valid string
	//Postcondition: Name of city will be returned
	string getName() const;
private:
	//Data members
	int population;
	string name;
};

