/** @author Maxwell Griffith */

#include "Student.h"
using namespace std;
// ** ADD CODE
// Define each of the member function 
// prototypes/declarations in Student.h
// NOTE: The default value for the tuition will be 0

Student::Student(void): Person()
{
	tuition=0;

}

Student::Student(string newName, double newTuition): Person(newName)
{
	tuition= newTuition;
}

void Student::setTuition(double newTuition)
{
	tuition=newTuition;
}

double Student::getTuition() const
{
	return tuition;
}
