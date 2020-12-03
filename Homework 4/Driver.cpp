/*
 Driver.cpp
 Author: Chandler Ford
 Description: This is the driver file for the LinkedList and Set classes. 
			  It creates a Set full of unique values (years from 1980s)
			  and demonstrates some methods.
*/

#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Set.h"
#include "Set.cpp"

//Main
//Precondition: Classes exist and are valid objects
//Postcondition: Program will be run and output will be displayed on console
int main()
{
	//Make a LinkedList object with ten items as a backup
	LinkedList<int> itemLL;
	
	int j = 0;
	for (int i = 1980; i < 1990; i++)
	{
		itemLL.insert(i, j);
		j++;
	}

	//Create and fill Set with the years 1980-1989
	Set<int> itemSet;

	for (int i = 1980; i < 1990; i++)
	{
		itemSet.insert(i);
	}

	//Introduction
	cout << "--------------------------------------------------------------" << endl;
	cout << "HOMEWORK 4: OPERATOR OVERLOADING" << endl;
	cout << "Created by Chandler Ford for CSS 342 B." << endl;
	cout << "--------------------------------------------------------------" << endl;

	//Display LinkedList with ten items
	cout << "LINKEDLIST WITH TEN ITEMS (Years of the 1980s)" << endl;
	cout << "--------------------------------------------------------------" << endl;
	itemSet.LinkedList::print();
	cout << "--------------------------------------------------------------" << endl;

	//Explanation of demonstration of use of set
	cout << "DEMONSTRATION OF USE OF SET" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "My Set data structure reads in the years of the 1980s using a" << endl;
	cout << "calibrated for-loop and the Set insert function." << endl;
	cout << "--------------------------------------------------------------" << endl;

	//Adding a value that already exists in set
	cout << "ADDING VALUE THAT ALEADY EXISTS IN SET" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "Before adding a value that already exists in Set:" << endl;
	cout << "Attempted to add year 1980 to the data structure " << itemSet.getKeyCounter(1980) << " time(s)." << endl;  //Has been added once by the loop
	cout << endl;
	cout << "Adding an item that already exists in Set:" << endl;
	itemSet.insert(1980);  //A message appears notifying the user that this value has already been added
	cout << endl;
	cout << "After adding a value that already exists in Set:" << endl;
	cout << "Attempted to add year 1980 to the data structure " << itemSet.getKeyCounter(1980) << " time(s)." << endl;  //Now has been added twice
	cout << "--------------------------------------------------------------" << endl;

	//Print out everything in set
	cout << "PRINT OUT EVERYTHING IN SET" << endl;
	cout << "--------------------------------------------------------------" << endl;
	itemSet.print();
	cout << "--------------------------------------------------------------" << endl;

	//Add more items to the set
	cout << "*Adding more items to the set*" << endl;
	cout << "--------------------------------------------------------------" << endl;
	itemSet.insert(1984);
	itemSet.insert(1985);
	itemSet.insert(1985);
	itemSet.insert(1985);
	itemSet.insert(1986);
	itemSet.insert(1987);
	itemSet.insert(1988);
	itemSet.insert(1988);
	itemSet.insert(1988);
	itemSet.insert(1988);
	itemSet.insert(1989);
	cout << "--------------------------------------------------------------" << endl;

	//Demonstration of top three in set
	cout << "DEMONSTRATION OF TOP THREE IN SET" << endl;
	cout << "--------------------------------------------------------------" << endl;
	itemSet.sortDisplayTopThree();
	cout << "--------------------------------------------------------------" << endl;

	cout << endl;
	//system("PAUSE");
	return 0;
}