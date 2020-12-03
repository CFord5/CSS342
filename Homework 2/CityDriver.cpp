/*
 CityDriver.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the LinkedList class. This class stores
			  nodes containing the city object. In addition to a head and next pointers, it
			  features a tail and previous pointer allowing thec lass to implement a doubly
			  linked list.
*/

#include "City.h"
#include "LinkedList.h"

int main()
{
	//Introduction
	cout << "HOMEWORK 2: SEARCHING AND SORTING" << endl;
	cout << "Created by Chandler Ford for CSS 342 B." << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;

	//Object creation and instantiation (City class)
	City one(704352, "Seattle");
	City two(8537673, "New York");
	City three(2704958, "Chicago");
	City four(2303482, "Houston");
	City five(1615017, "Phoenix");
	City six(1567872, "Philadelphia");
	City seven(1492510, "San Antonio");
	City eight(1406630, "San Diego");
	City nine(1317929, "Dallas");
	City ten(1025350, "San Jose");
	
	//Object creation and instatiation (LinkedList class)
	LinkedList listOfCities;
	listOfCities.add(one);
	listOfCities.add(three);
	listOfCities.add(eight);
	listOfCities.add(five);
	listOfCities.add(four);
	listOfCities.add(six);
	listOfCities.add(two);
	listOfCities.add(nine);
	listOfCities.add(seven);
	listOfCities.add(ten);
	
	//Print unsorted list
	cout << endl;
	cout << "UNSORTED LIST:" << endl;
	listOfCities.printLinkedList();
	cout << endl;

	//Print sorted list in ascending order
	cout << "ASCENDING SORT:" << endl;
	listOfCities.sortAscending();
	listOfCities.printLinkedList();
	cout << endl;

	//Print sorted list in descending orders
	cout << "DESCENDING SORT:" << endl;
	listOfCities.sortDescending();
	listOfCities.printLinkedList();
	cout << endl;

	//Basic search function
	cout << "BASIC SEARCH FUNCTION:" << endl;
	cout << "Please enter a city name from above: ";
	string input;
	getline(cin, input);
	listOfCities.linearSearch(input);
	cout << endl;

	//Big-O Analysis
	cout << "BIG-O ANALYSIS:" << endl;
	cout << "Ascending sort has a Big-O of O(n^2) due to two levels of nested for-loops." << endl;
	cout << "Descending sort has a Big-O of O(n^2) due to two levels of nested for-loops." << endl;
	cout << "The search function has a Big-O of O(n) due to its single while loop." << endl;
	cout << endl;
	
	//system("PAUSE");
	return 0;
}