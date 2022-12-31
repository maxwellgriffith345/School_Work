/** @author Maxwell Griffith */

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

#include "Person.h"

// ** ADD CODE
// Modify the next line of code so that class Student will inherit
// from public Person
class Student : public Person 
{
public:
  Student(void);
  Student(string newName, double newTuition);

  void setTuition(double newTuition);
  double getTuition() const;

private:
  double tuition;
};

#endif
