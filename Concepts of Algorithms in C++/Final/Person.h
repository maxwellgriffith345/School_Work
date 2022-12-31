
/** @author Mark Van Gorp */

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
  Person(void);
  Person(string newName);

  void setName(string newName);
  string getName() const;

private:
  string name;
};

#endif

