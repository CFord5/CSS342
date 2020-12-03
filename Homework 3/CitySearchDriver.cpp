/*
	CitySearchDriver.cpp
	Author: Chandler Ford
	Description: This is the driver file for the City class that uses templates. This driver creates several objects
	             and allows the user to search city names to find their populations and similarly sized cities. This
				 class makes use of vectors (for the data structure) and templates. City population data from the
				 following link: https://en.wikipedia.org/wiki/Largest_cities_in_the_Americas
*/

#include "City.h"
#include "City.cpp"

//printVector(): Prints out contents of vector
//Precondition: Vector input is a valid vector
//Postcondition: Contents of vector will be printed to screen
template <class T>
void printVector(vector<T> inputVector);

//searchSuggest(): Allows user to search city names to see population and similarly sized cities
//Precondition: Vector input is a valid vector
//Postcondition: City object population will be returned along with three similarly sized cities
template <class T>
void searchSuggest(vector<T> inputVector);

int main()
{
	//Introduction
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "HOMEWORK 3: SUGGESTIONS" << endl;
	cout << "Created by Chandler Ford for CSS 342 B." << endl;

	//Create City objects, use int as template parameter
	City<int> saoPaulo, mexicoCity, lima, newYork, bogota, rioDeJaneiro, santiago, losAngeles, caracas, buenosAires;

	//Intitialize City objects with name and population
	saoPaulo.setName("Sao Paulo");
	saoPaulo.setPopulation(11967825);

	mexicoCity.setName("Mexico City");
	mexicoCity.setPopulation(8918653);

	lima.setName("Lima");
	lima.setPopulation(8894412);

	newYork.setName("New York");
	newYork.setPopulation(8550495);

	bogota.setName("Bogota");
	bogota.setPopulation(7862277);

	rioDeJaneiro.setName("Rio de Janeiro");
	rioDeJaneiro.setPopulation(6476631);

	santiago.setName("Santiago");
	santiago.setPopulation(5507282);

	losAngeles.setName("Los Angeles");
	losAngeles.setPopulation(3971883);

	caracas.setName("Caracas");
	caracas.setPopulation(3289886);

	buenosAires.setName("Buenos Aires");
	buenosAires.setPopulation(3054267);

	//Create new vector that takes in City objects with a template parameter of int
	vector<City<int> > myVector;

	//Fill vector with city objects
	myVector.push_back(saoPaulo);
	myVector.push_back(mexicoCity);
	myVector.push_back(lima);
	myVector.push_back(newYork);
	myVector.push_back(bogota);
	myVector.push_back(rioDeJaneiro);
	myVector.push_back(santiago);
	myVector.push_back(losAngeles);
	myVector.push_back(caracas);
	myVector.push_back(buenosAires);

	//Display contents of vector
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "These are the largest cities in the Americas as of 2015:" << endl;
	printVector(myVector);
	cout << "---------------------------------------------------------------------------------" << endl;
	
	//Demonstration of search where search term is found
	cout << "Demonstration of Search Where Search Term is Found" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "Type a name as it appears on the list to search for the city's population and see" << endl;
	cout << "other cities of similar sizes: " << endl;
	searchSuggest(myVector);
	cout << "---------------------------------------------------------------------------------" << endl;

	//Demonstration of search where term is NOT found
	cout << "Demonstration of Search Where Term is NOT Found" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "Type a name that does NOT appear on the list (like Seattle): " << endl;
	searchSuggest(myVector);
	cout << "---------------------------------------------------------------------------------" << endl;

	//Demonstration of search after items in the data structure have been added
	cout << "Demonstration of Search After Item Has Been Added to the Data Structure" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	City<int> salvador;  //Create new City object with template parameter set to int
	salvador.setName("Salvador");  //Set the City object name
	salvador.setPopulation(2921087);  //Set the City population
	myVector.push_back(salvador);  //Add new City object to vector
	cout << "The city of " << salvador.getName() << " has been added to the vector." << endl;  //Notify user
	cout << "Type a name as it appears on the list to search for the city's population and see" << endl;
	cout << "other cities of similar sizes: " << endl;
	searchSuggest(myVector);
	cout << "---------------------------------------------------------------------------------" << endl;

	//Search algorithm analysis
	cout << "Search Algorithm Analysis" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "The Big-O notation of my search function is O(n) because it contains only a single for-loop." << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << endl;

	//system("PAUSE");
	return 0;
}

//printVector(): Prints out name of City objects in vector
//Precondition: Vector input is a valid vector
//Postcondition: Name of City objects in vector will be printed 
template <class T>
void printVector(vector<T> inputVector)
{
	for (int i = 0; i < (int)inputVector.size(); i++)  //Loop through the vector
	{
		cout << inputVector[i].getName() << endl;  //Print out the name of the City object
	}
}

//searchSuggest(): Allows user to search city names to see population and similarly sized cities
//Precondition: Vector input is a valid vector
//Postcondition: City object population will be returned along with three similarly sized cities
//The Big-O notation of my search function is O(n) because it contains only a single for-loop
template <class T>
void searchSuggest(vector<T> inputVector)
{
	string input;  //Take in a search term from the user
	getline(cin, input);
	cout << endl;

	bool found = false;  //Keep track of if the value is found or not

	for (int i = 0; i < (int)inputVector.size(); i++)  //Loop through the vector
	{
		if (input == inputVector[i].getName())  //If the name of the City object matches the input
		{
			cout << inputVector[i].getName() << " has a population of " << inputVector[i].getPopulation() << "." << endl;  //Notify user
			if (i == 0)  //If the match is at the beginning of the vector
			{
				cout << "Cities with a similar population include:" << endl;  //Return contents of similar index locations
				cout << "1) " << inputVector[i + 1].getName() << " with a population of " << inputVector[i + 1].getPopulation() << endl;
				cout << "2) " << inputVector[i + 2].getName() << " with a population of " << inputVector[i + 2].getPopulation() << endl;
				cout << "3) " << inputVector[i + 3].getName() << " with a population of " << inputVector[i + 3].getPopulation() << endl;
				found = true;  //Set boolean to true as a match has been found
			}
			else if (i == 1)  //If the match is near the front of the vector
			{
				cout << "Cities with a similar population include:" << endl;  //Return contents of similar index locations
				cout << "1) " << inputVector[i - 1].getName() << " with a population of " << inputVector[i - 1].getPopulation() << endl;
				cout << "2) " << inputVector[i + 1].getName() << " with a population of " << inputVector[i + 1].getPopulation() << endl;
				cout << "3) " << inputVector[i + 2].getName() << " with a population of " << inputVector[i + 2].getPopulation() << endl;
				found = true;  //Set boolean to true as a match has been found
			}
			else if (i == (inputVector.size() - 2))  //If the match is near the end of the vector
			{
				cout << "Cities with a similar population include:" << endl;  //Return contents of similar index locations
				cout << "1) " << inputVector[i + 1].getName() << " with a population of " << inputVector[i + 1].getPopulation() << endl;
				cout << "2) " << inputVector[i - 1].getName() << " with a population of " << inputVector[i - 1].getPopulation() << endl;
				cout << "3) " << inputVector[i - 2].getName() << " with a population of " << inputVector[i - 2].getPopulation() << endl;
				found = true;  //Set boolean to true as a match has been found
			}
			else if (i == inputVector.size() - 1)  //If the match is at the end of the vector
			{
				cout << "Cities with a similar population include:" << endl;  //Return contents of similar index locations
				cout << "1) " << inputVector[i - 1].getName() << " with a population of " << inputVector[i - 1].getPopulation() << endl;
				cout << "2) " << inputVector[i - 2].getName() << " with a population of " << inputVector[i - 2].getPopulation() << endl;
				cout << "3) " << inputVector[i - 3].getName() << " with a population of " << inputVector[i - 3].getPopulation() << endl;
				found = true;  //Set boolean to true as a match has been found
			}
			else  //If the match is in the middle of the vector
			{
				cout << "Cities with a similar population include:" << endl;  //Return contents of similar index locations
				cout << "1) " << inputVector[i - 1].getName() << " with a population of " << inputVector[i - 1].getPopulation() << endl;
				cout << "2) " << inputVector[i - 2].getName() << " with a population of " << inputVector[i - 2].getPopulation() << endl;
				cout << "3) " << inputVector[i + 1].getName() << " with a population of " << inputVector[i + 1].getPopulation() << endl;
				found = true;  //Set boolean to true as a match has been found
			}
		}
	}  //End loop

	if (found == false)  //If no match was found
	{
		cout << "The city you searched is not listed in the vector." << endl;  //Notify user
	}

	cout << endl;
}