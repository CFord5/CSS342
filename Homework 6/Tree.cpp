/*
 Tree.cpp
 Author: Chandler Ford
 Description: This is the implementation file for the Tree class. This class stores
			  Nodes along with methods for the Ski School.
*/

#include "Tree.h"

//Default constructor
//Precondition: None
//Postcondition: Creates new Tree object
Tree::Tree()
{
	Node *newRoot = new Node;  //Make new node

	Instructor supervisor("Supervisor");  //Set it as supervisor
	newRoot->theInstructor = supervisor; //Initialize
	newRoot->left = NULL;
	newRoot->right = NULL;

	root = newRoot;  //Set as root
	superVector.push_back(root);
}

//Destructor
//Precondition: Tree object exists
//Postcondition: Delete Tree object
Tree::~Tree()
{
	cout << "*Deleting Tree*" << endl;
}

//insertInstructor
//Precondition: Instructor exists and is valid
//Postcondition: New node created with Instructor object
void Tree::insertInstructor(Instructor newInstructor)
{
	Node *newInstructorNode = new Node;  //Create new node
	newInstructorNode->theInstructor = newInstructor;  //Initialize
	
	Node *temp = root;  //Temporary pointer to traverse through Tree object
	while (temp != NULL)
	{
		temp = temp->right;
	}
	temp = newInstructorNode;

	superVector.push_back(newInstructorNode);
}

//insertStudent
//Precondition: Student exists and is valid
//Postcondition: Student added to appropriate Instructor node
void Tree::insertStudent(Student newStudent)
{
	int lowestNumStudents = 1000;

	for (int i = 0; i < (int)superVector.size(); i++)  //Loop through to find lowest number of students in a class
	{
		if ((int)superVector[i]->theStudents.size() < lowestNumStudents && superVector[i]->theInstructor.getName() != "Supervisor")
		{
			lowestNumStudents = superVector[i]->theStudents.size();
		}
	}
	
	if (lowestNumStudents < 5)  //Lowest number determines which funtion gets called 
	{
		fourLess(newStudent, lowestNumStudents);
	}
	else if (lowestNumStudents > 4 && lowestNumStudents < 8)
	{
		fiveEight(newStudent, lowestNumStudents);
	}
	else if (lowestNumStudents > 7)
	{
		eightPlus(newStudent, lowestNumStudents);
	}
	else
	{
		cout << "Error in insertStudent method" << endl;
	}
}

//fourLess
//Precondition: Student exists and is valid
//Postcondition: If Instructor with smallest class has four or less students, use this formula 
void Tree::fourLess(Student newStudent, int lowestNumStudents)
{
	bool inserted = false;
	while (inserted == false) 
	{
		for (int i = 0; i < (int)superVector.size(); i++)  //Add evenly
		{
			if ((int)superVector[i]->theStudents.size() == lowestNumStudents && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
		}
	}
}

//fiveEight
//Precondition: Student exists and is valid
//Postcondition: If Instructor class size is between five and eight students, use this formula
void Tree::fiveEight(Student newStudent, int lowestNumStudents)
{
	bool inserted = false;
	while (inserted == false) 
	{
		for (int i = 0; i < (int)superVector.size(); i++)  //Fill them up to eight one at a time
		{
			if ((int)superVector[i]->theStudents.size() == 7 && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
			if ((int)superVector[i]->theStudents.size() == 6 && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
			if ((int)superVector[i]->theStudents.size() == 5 && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
			/*else
			{
				cout << "Error in sixEight method. Size: " << lowestNumStudents << " At vector index: " << i << endl;
				inserted = true;
			}*/
		}
	}
}

//eightPlus
//Precondition: Student exists and is valid
//Postcondition: If Instructor with smallest class has eight or more students, use this formula 
void Tree::eightPlus(Student newStudent, int lowestNumStudents)
{
	bool inserted = false;
	while (inserted == false) 
	{
		for (int i = 0; i < (int)superVector.size(); i++)  //Add evenly
		{
			if ((int)superVector[i]->theStudents.size() == lowestNumStudents && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}

		}
	}
}

//insertStudentSpecified
//Precondition: Student and instructor exist and are valid
//Postcondition: Student will be inserted to the Instructor of their choice
void Tree::insertStudentSpecified(Student newStudent, Instructor targetInstructor)
{
	bool instructorFound = false;
	for (int i = 0; i < (int)superVector.size(); i++)  //Loop through until match found
	{
		if (superVector[i]->theInstructor.getName() == targetInstructor.getName() && superVector[i]->theInstructor.getName() != "Supervisor")
		{
			if (superVector[i]->theStudents.size() < 5)  //Size of match determines function called
			{
				fourLessSpecified(newStudent, superVector[i]->theStudents.size(), targetInstructor);
				instructorFound = true;
			}
			else if (superVector[i]->theStudents.size() > 4 && superVector[i]->theStudents.size() < 8)
			{
				fiveEightSpecified(newStudent, superVector[i]->theStudents.size(), targetInstructor);
				instructorFound = true;
			}
			else if (superVector[i]->theStudents.size() > 7)
			{
				eightPlusSpecified(newStudent, superVector[i]->theStudents.size(), targetInstructor);
				instructorFound = true;
			}
			else
			{
				cout << "Error in insertStudentSpecified method" << endl;
			}
		}
	}	
	if (instructorFound == false)
	{
		cout << "NOTICE: The instructor requested (" << targetInstructor.getName() << ") was not found in our records. Please try another instructor." << endl;
		cout << endl;
	}
}

//fourLessSpecified
//Precondition: Student and instructor exist and are valid
//Postcondition: If Instructor has four or less students, use this formula 
void Tree::fourLessSpecified(Student newStudent, int size, Instructor targetInstructor)
{
	bool inserted = false;
	while (inserted == false)
	{
		for (int i = 0; i < (int)superVector.size(); i++)  //Add evenly
		{
			if ((int)superVector[i]->theStudents.size() == size && superVector[i]->theInstructor.getName() == targetInstructor.getName() && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
		}
	}
}

//fiveEightSpecified
//Precondition: Student and instructor exist and are valid
//Postcondition: If Instructor has five to eight students, use this formula 
void Tree::fiveEightSpecified(Student newStudent, int size, Instructor targetInstructor)
{
	bool inserted = false;
	while (inserted == false)
	{
		for (int i = 0; i < (int)superVector.size(); i++)  //Fill them up to eight one at a time
		{
			if ((int)superVector[i]->theStudents.size() == 7 && superVector[i]->theInstructor.getName() == targetInstructor.getName() && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
			if ((int)superVector[i]->theStudents.size() == 6 && superVector[i]->theInstructor.getName() == targetInstructor.getName() && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
			if ((int)superVector[i]->theStudents.size() == 5 && superVector[i]->theInstructor.getName() == targetInstructor.getName() && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
			/*else
			{
			cout << "Error in sixEight method. Size: " << lowestNumStudents << " At vector index: " << i << endl;
			inserted = true;
			}*/
		}
	}
}


//eightPlusSpecified
//Precondition: Student and instructor exist and are valid
//Postcondition: If Instructor has eight or more students, use this formula 
void Tree::eightPlusSpecified(Student newStudent, int size, Instructor targetInstructor)
{
	bool inserted = false;
	while (inserted == false)
	{
		for (int i = 0; i < (int)superVector.size(); i++)  //Add evenly
		{
			if ((int)superVector[i]->theStudents.size() == size && superVector[i]->theInstructor.getName() == targetInstructor.getName() && superVector[i]->theInstructor.getName() != "Supervisor" && inserted == false)
			{
				superVector[i]->theStudents.push_back(newStudent);
				inserted = true;
			}
		}
	}
}

//removeStudent
//Precondition: Student exists and is valid
//Postcondition: Student will be removed from Instructor node
void Tree::removeStudent(Student targetStudent)
{
	for (int i = 0; i < (int)superVector.size(); i++)
	{
		for (int j = 0; j < (int)superVector[i]->theStudents.size(); j++)  //Loop through to find match
		{
			if (superVector[i]->theStudents[j].getName() == targetStudent.getName())
			{
				superVector[i]->theStudents.erase(superVector[i]->theStudents.begin() + j);  //Remove
			}
		}
	}
}

//removeInstructor
//Precondition: Instructor exists and is valid
//Postcondition: Instructor node will be deleted and Students will be redistributed
void Tree::removeInstructor(Instructor targetInstructor)
{
	vector<Student> tempHolder;
	for (int i = 0; i < (int)superVector.size(); i++)   //Loop through to find match
	{
		if (superVector[i]->theInstructor.getName() == targetInstructor.getName())
		{
			for (int j = 0; j < (int)superVector[i]->theStudents.size(); j++)
			{
				tempHolder.push_back(superVector[i]->theStudents[j]);
			}

			superVector.erase(superVector.begin() + i);
		}
	}
	for (int i = 0; i < (int)tempHolder.size(); i++)
	{
		insertStudent(tempHolder[i]);
	}
}

//findWithStudent
//Precondition: Student exists and is valid
//Postcondition: Will return statement if teacher with target Student found
void Tree::findWithStudent(Student targetStudent)
{
	bool found = false;
	for (int i = 0; i < (int)superVector.size(); i++)  //Loop through to find match
	{
		for (int j = 0; j < (int)superVector[i]->theStudents.size(); j++)
		{
			if (superVector[i]->theStudents[j].getName() == targetStudent.getName())
			{
				found = true;
				cout << "Found student " << targetStudent.getName() << " in the class taught by Instructor " << superVector[i]->theInstructor.getName() << "." << endl;
			}
		}
	}
	if (found == false)
	{
		cout << "Student not found." << endl;
	}
}

//findWIthInstructor
//Precondition: Instructor exists and is valid
//Postcondition: Will return statement if Instructor name matches target name
void Tree::findWIthInstructor(Instructor targetInstructor)
{
	bool found = false;
	for (int i = 0; i < (int)superVector.size(); i++)  //Loop through to find match
	{
		if (superVector[i]->theInstructor.getName() == targetInstructor.getName())
		{
			found = true;
			cout << "Instructor " << targetInstructor.getName() << " exists." << endl;
		}
	}
	if (found == false)
	{
		cout << "Instructor not found." << endl;
	}
}

//display
//Precondition: Tree object exists and is valid
//Postcondition: Print Instructor and Student objects
void Tree::display()
{
	cout << superVector[0]->theInstructor.getName() << endl;
	for (int i = 0; i < (int)superVector.size(); i++)  //Loop through and print
	{
		if (superVector[i]->theInstructor.getName() != "Supervisor")
		{
			cout << "Instructor: " << superVector[i]->theInstructor.getName() << endl;
			for (int j = 0; j < (int)superVector[i]->theStudents.size(); j++)
				cout << "\tStudent: " << superVector[i]->theStudents[j].getName() << endl;
		}
	}
}
