/** @author Maxwell Griffith */

#include <string>
#include "Person.h"
using namespace std;
// ** ADD CODE
// Define each of the member function 
// prototypes/declarations in Person.h
// NOTE: The default value for the name will be "" (the empty string

Person::Person(void)
{
	name="";

}

Person::Person(string newName)
{
	name=newName;
}

void Person::setName(string newName)
{
	name=newName;

}

string Person::getName() const
{
	return name;

}
