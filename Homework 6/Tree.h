/*
 Tree.h
 Author: Chandler Ford
 Description: This is the header file for the Tree class. This class stores
			  Nodes along with methods for the Ski School.
*/

#include "Person.h"
#include "Instructor.h"
#include "Student.h"

#pragma once
class Tree
{
private:
	//Used to create Nodes holding the Instructor and Student objects
	struct Node
	{
		Node *left;
		Node *right;
		Instructor theInstructor;
		vector<Student> theStudents;
	};
	//Data members
	Node *root;
	vector<Node*> superVector;

public:
	//Default constructor
	//Precondition: None
	//Postcondition: Creates new Tree object
	Tree();

	//Destructor
	//Precondition: Tree object exists
	//Postcondition: Delets Tree object
	~Tree();

	//insertInstructor
	//Precondition: Instructor exists and is valid
	//Postcondition: New node created with Instructor object
	void insertInstructor(Instructor newInstructor);

	//insertStudent
	//Precondition: Student exists and is valid
	//Postcondition: Student added to appropriate Instructor node
	void insertStudent(Student newStudent);

	//fourLess
	//Precondition: Student exists and is valid
	//Postcondition: If Instructor with smallest class has four or less students, use this formula 
	void fourLess(Student newStudent, int lowestNumStudents); 

	//fiveEight
	//Precondition: Student exists and is valid
	//Postcondition: If Instructor class size is between five and eight students, use this formula
	void fiveEight(Student newStudent, int lowestNumStudents);

	//eightPlus
	//Precondition: Student exists and is valid
	//Postcondition: If Instructor with smallest class has eight or more students, use this formula 
	void eightPlus(Student newStudent, int lowestNumStudents);

	//insertStudentSpecified
	//Precondition: Student and instructor exist and are valid
	//Postcondition: Student will be inserted to the Instructor of their choice
	void insertStudentSpecified(Student newStudent, Instructor targetInstructor);

	//fourLessSpecified
	//Precondition: Student and instructor exist and are valid
	//Postcondition: If Instructor has four or less students, use this formula 
	void fourLessSpecified(Student newStudent, int size, Instructor targetInstructor);

	//fiveEightSpecified
	//Precondition: Student and instructor exist and are valid
	//Postcondition: If Instructor has five to eight students, use this formula 
	void fiveEightSpecified(Student newStudent, int size, Instructor targetInstructor);

	//eightPlusSpecified
	//Precondition: Student and instructor exist and are valid
	//Postcondition: If Instructor has eight or more students, use this formula 
	void eightPlusSpecified(Student newStudent, int size, Instructor targetInstructor);


	//removeStudent
	//Precondition: Student exists and is valid
	//Postcondition: Student will be removed from Instructor node
	void removeStudent(Student targetStudent);

	//removeInstructor
	//Precondition: Instructor exists and is valid
	//Postcondition: Instructor node will be deleted and Students will be redistributed
	void removeInstructor(Instructor targetInstructor);

	//findWithStudent
	//Precondition: Student exists and is valid
	//Postcondition: Will return statement if teacher with target Student found
	void findWithStudent(Student targetStudent);

	//findWIthInstructor
	//Precondition: Instructor exists and is valid
	//Postcondition: Will return statement if Instructor name matches target name
	void findWIthInstructor(Instructor targetInstructor);

	//display
	//Precondition: Tree object exists and is valid
	//Postcondition: Print Instructor and Student objects
	void display();
};
