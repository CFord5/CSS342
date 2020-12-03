/*
 Tree.cpp
 Author: Chandler Ford
 Description: This is the driver file for the Tree class. This class stores
			  places Instructors and Students into the Tree object and runs
			  some methods.
*/

#include "Tree.h"
#include "Person.h"
#include "Instructor.h"
#include "Student.h"


int main()
{
	//INTRODUCTION
	cout << "HOMEWORK 6: Ski School" << endl;
	cout << "Created by Chandler Ford for CSS 342 B." << endl;
	cout << endl;

	//Create Tree object
	Tree skiSchool;

	//Create and initialize three instructors
	Instructor myInstructor1("Phillipe");
	Instructor myInstructor2("Merlin");
	Instructor myInstructor3("Nancy");

	//Insert instructors
	skiSchool.insertInstructor(myInstructor1);
	skiSchool.insertInstructor(myInstructor2);
	skiSchool.insertInstructor(myInstructor3);

	//Create and initialize nineteen students
	Student myStudent1("Chandler");
	Student myStudent2("Mike");
	Student myStudent3("Jay");
	Student myStudent4("Rich");
	Student myStudent5("Luke");
	Student myStudent6("George");
	Student myStudent7("Steven");
	Student myStudent8("Francis");
	Student myStudent9("Frank");
	Student myStudent10("Jack");
	Student myStudent11("Josh");
	Student myStudent12("Jessi");
	Student myStudent13("Tony");
	Student myStudent14("Bruce");
	Student myStudent15("Natasha");
	Student myStudent16("Peter");
	Student myStudent17("Thor");
	Student myStudent18("Nick");
	Student myStudent19("Harry");

	//Insert students
	skiSchool.insertStudent(myStudent1);
	skiSchool.insertStudent(myStudent2);
	skiSchool.insertStudent(myStudent3);
	skiSchool.insertStudent(myStudent4);
	skiSchool.insertStudent(myStudent5);
	skiSchool.insertStudent(myStudent6);
	skiSchool.insertStudent(myStudent7);
	skiSchool.insertStudent(myStudent8);
	skiSchool.insertStudent(myStudent9);
	skiSchool.insertStudent(myStudent10);
	skiSchool.insertStudent(myStudent11);
	skiSchool.insertStudent(myStudent12);
	skiSchool.insertStudent(myStudent13);
	skiSchool.insertStudent(myStudent14);
	skiSchool.insertStudent(myStudent15);
	skiSchool.insertStudent(myStudent16);
	skiSchool.insertStudent(myStudent17);
	skiSchool.insertStudent(myStudent18);
	skiSchool.insertStudent(myStudent19);

	//Display and space
	cout << "Part 1) Three teachers and nineteen students" << endl;
	cout << "--------------------------------------------" << endl;
	skiSchool.display();
	cout << endl;

	//Remove instructor
	skiSchool.removeInstructor(myInstructor3);

	//Display and space
	cout << "Part 2) Remove instructor" << endl;
	cout << "--------------------------------------------" << endl;
	skiSchool.display();
	cout << endl;

	//Attempt to add new Student to Tree object
	cout << "Part 3) Attempt to add new Student to Tree object" << endl;
	cout << "--------------------------------------------" << endl;
	Student myStudent20("Len");
	skiSchool.insertStudentSpecified(myStudent20, myInstructor3);

	//Display and space
	skiSchool.display();
	cout <<  endl;

	//system("PAUSE");
	return 0;
}