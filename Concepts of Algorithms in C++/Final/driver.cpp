/** @author Maxwell Griffith */

#include <iostream>
#include <exception>
#include <fstream>
#include <iomanip> 
#include <string>
using namespace std;
#include "Student.h"

/**
 * getStudents reads student data and creates an array of Student objects
 * from that data
 * @param fileName The name of the input file for student data
 * @param students Will eventually contain a pointer to an array of
 *    Student objects that is dynamically created by this method.
 * @return The size of the array which is the number of students read.*/
int getStudents(string fileName, Student* & students);

/**
 * showStudents displays to standard output (the console window) the
 * students with tuition data greater than or equal to tuitionCutoff.
 * The format for display is:
 *     's tuition is $
 * Example:
 *     Andrew's tuition is $1230.50
 * The tuition is always displayed with 2 digits of precision.
 * @param students The array of student objects
 * @param numStudents The number of students in the array
 * @param tuitionCutoff The amount for which all student's having tuition
 *    greater than or equal to that amount are displayed. */
void showStudents(Student* students, int numStudents, double tuitionCutoff);

int main()
{
  Student* students = nullptr; // Will contain an array of Student objects
  int numStudents; // The number of students read from file
  string fileName = "students.txt"; // Adjust to a different path if needed

  // **ADD CODE 
  // Insert a try catch to catch an exception object. The exception
  // object is already built into C++ and includes a public what()
  // member function that returns the message stored into the exception
  // In the try portion, include the following statement
  //    numStudents = getStudents(fileName, students);
  // In the catch portion, catch the exception object, use what() to
  // display the message stored, and either return or exit with a value
  // (error code) of 1.
	try
	{
		numStudents = getStudents(fileName, students);

	}

	catch(exception a)
	{
		a.what();
		exit(1);
	}

  cout << "Show all students owing tuition at or above what value? $";
  double tuitionCutoff;
  cin >> tuitionCutoff;

  // **ADD CODE
  // Call the showStudents function with the students array, the number of
  // students in the array, and the tuition cutoff just retrieved from the
  // user
	showStudents(students, numStudents, tuitionCutoff);

  return 0;
}

/* **ADD CODE INSIDE FUNCTION
 * Read the comments above the getStudents declaration/prototype above.
 * Then complete the method. */
int getStudents(string fileName, Student* & students) //throw (exception)
{
  // **ADD CODE
  // Attempt to open the file stored in the fileName parameter. Your code
  // should work for any file name sent from main. In other words, use
  // the parameter rather than typing in something literal like "students.txt"

  // ** ADD CODE
  // If the file does not open, then throw an exception object with the
  // message of "Cannot open input file". This is just like the Exceptions
  // lab, except the class named exception is thrown rather than InputError

	
	ifstream input;
	input.open(fileName);
	if(!input)
	{
		throw exception("Cannot open iput file");
	}



  // ** ADD CODE
  // Read the first line of the file, which is the number of remaining lines
  // (i.e. students) in the file. Store this into a variable such as 
  // numStudents. Then assign to the students parameter a dynamically
  // allocated array of Student objects that has numStudents cells.

	int numstudents;
	input>>numstudents;

	students = new Student[numstudents];

  // ** ADD CODE
  // Loop numStudents times to read each of the remaining lines of the
  // file. In each loop iteration, you'll read the name and tuition and
  // then set the student's name and tuition in the array slot.
  // For example, the first loop iteration with store the name and tuition
  // read into students[0], the second loop iteration into students[0],
  // etc. Of course, you will be looping, so students[i] is used as your
  // code so it will even work for thousands of students if the input
  // file were that big.

	int i=0;
	string name;
	int tuition;
	
	while(i<numstudents && input>>name >>tuition)
	{
		students[i].setName(name);
		students[i].setTuition(tuition);

	}
	

  // ** ADD CODE
  // Close the input file and return the number of students read.
	input.close();
		
  return numstudents ; // CHANGE THIS LINE, INSERTED ONLY TO GET CODE TO COMPILE
}

/* **ADD CODE INSIDE FUNCTION
 * Read the comments above the getStudents declaration/prototype above.
 * Then complete the method. Remember to match the output format
 * exactly and use a precision of two for the tuition. */
void showStudents(Student* students, int numStudents, double tuitionCutoff)
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	for(int i=0; i<numStudents; i++)
	{
		if(students[i].getTuition() >= tuitionCutoff)
		{
			cout<<students[i].getName() <<"'s tuition is " <<students[i].getTuition();
		}
	}		


}


/*
Get this error when trying to compile. Don't know what it means. Never used the exception class, wasn't covered in course materials. 

driver.cpp:94:9: error: no matching conversion for functional-style cast from 'const char [22]' to
      'std::exception'
                throw exception("Cannot open iput file");
                      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/exception:97:29: note: candidate
      constructor (the implicit copy constructor) not viable: no known conversion from
      'const char [22]' to 'const std::exception' for 1st argument
class _LIBCPP_EXCEPTION_ABI exception
                            ^
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/exception:100:31: note: candidate
      constructor not viable: requires 0 arguments, but 1 was provided
    _LIBCPP_INLINE_VISIBILITY exception() _NOEXCEPT {}
                              ^
1 error generated.



*/
