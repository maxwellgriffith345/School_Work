/**
 *@author Maxwell Griffith
 *@file multiples.cpp
 */

#include <iostream> // allows program to perform input and output

using std::cout; // program uses cout
using std::endl; // program uses endl
using std::cin; // program uses cin

int main()
{
   int number1;
   int number2;
   
   // get numbers from user
   cout << "Enter two integers: ";
   cin  >> number1
        >> number2;

   //tests whether number1 is a multiple of number2
   if (number1%number2==0)
   {
      cout << number1
           << " is a multiple of "
           << number2
           << endl;
   }

   //tests whether number1 is not a multiple of number2
   if (number1%number2!=0)
   {
      cout << number1
           << " is not a multiple of "
           << number2
           << endl;
   }

   return 0; // indicate successful termination

} // end main

/*
 Enter two integers: 45 15
 45 is a multiple of 15
 Program ended with exit code: 0
 
 Enter two integers: 12 36
 12 is not a multiple of 36
 Program ended with exit code: 0
 
 Enter two integers: 10 10
 10 is a multiple of 10
 Program ended with exit code: 0
 
 Enter two integers: 12 5
 12 is not a multiple of 5
 Program ended with exit code: 0
 */
