/*
 Driver.cpp
 Author: Chandler Ford
 Description: This is the driver file for the BagOfMarbles class. This driver creates several objects and demonstrates overloaded operators.
*/

#include "BagOfMarbles.h"
#include <iostream>
using namespace std;

int main()
{
	//Introduction
	cout << "HOMEWORK 1: OPERATOR OVERLOADING" << endl;
	cout << "Created by Chandler Ford for CSS 342 B." << endl;
	cout << endl;

	//Object creation and instantiation
	BagOfMarbles bagOne(1, 2, 3);
	BagOfMarbles bagTwo;
	bagTwo.setRedMarble(4);
	bagTwo.setGreenMarble(5);
	bagTwo.setBlueMarble(6);

	cout << "-------------------------------------------------------------------" << endl;
	cout << "OBJECT CREATION AND INSTANTIATION" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Bag One has " << bagOne.getRedMarble() << " red marbles." << endl;
	cout << "Bag One has " << bagOne.getGreenMarble() << " green marbles." << endl;
	cout << "Bag One has " << bagOne.getBlueMarble() << " blue marbles." << endl;
	cout << endl;

	cout << "Bag Two has " << bagTwo.getRedMarble() << " red marbles." << endl;
	cout << "Bag Two has " << bagTwo.getGreenMarble() << " green marbles." << endl;
	cout << "Bag Two has " << bagTwo.getBlueMarble() << " blue marbles." << endl;
	cout << "-------------------------------------------------------------------" << endl;

	//Arithmetic operand
	cout << "ARITHMETIC OPERAND" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Using the overloaded + operator, we can add the values of Bag One and Bag Two together to get Bag Three." << endl;
	cout << endl;

	BagOfMarbles bagThree = bagOne + bagTwo;  //Add Bag One and Bag Two together and assign value to new Bag Three object

	cout << "Bag Three has " << bagThree.getRedMarble() << " red marbles." << endl;
	cout << "Bag Three has " << bagThree.getGreenMarble() << " green marbles." << endl;
	cout << "Bag Three has " << bagThree.getBlueMarble() << " blue marbles." << endl;
	cout << "-------------------------------------------------------------------" << endl;

	//Compound operand
	cout << "COMPOUND OPERAND" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Using the overloaded += operator, we set Bag One equal to the contents" << endl;  
	cout <<	"of itself plus Bag Two." << endl;
	cout << endl;

	bagOne += bagTwo;  //Bag One is assigned the value of itself plus Bag Two

	cout << "Now Bag One has " << bagOne.getRedMarble() << " red marbles." << endl;
	cout << "Now Bag One has " << bagOne.getGreenMarble() << " green marbles." << endl;
	cout << "Now Bag One has " << bagOne.getBlueMarble() << " blue marbles." << endl;
	cout << "-------------------------------------------------------------------" << endl;

	//Comparison operand
	cout << "COMPARISON OPERAND" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "The overloaded == operator will return true (1) if the red, green, and" << endl;
	cout << "blue marble values of two BagOfMarbles objects match. If the values" << endl;
	cout << "don't match it will return false (0)." << endl;
	cout << endl;

	cout << "Bag One and Bag Two are equal: " << (bagOne == bagTwo) << endl;  //Returns false (0)
	cout << "Bag One and Bag Three are equal: " << (bagOne == bagThree) << endl;  //Returns true (1)
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl;

	//system("PAUSE");
	return 0;
}