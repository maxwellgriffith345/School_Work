/**
 * @author Maxwell Griffith
 *@file numbercompare.cpp
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
   int number1; // first integer read from user
   int number2; // second integer read from user
   int number3; // third integer read from user
   int smallest; // smallest integer read from user
   int largest; // largest integer read from user

   // gets values for number1, number2, number 3 from user
   cout << "Input three different integers: ";
   cin >>number1
       >>number2
       >>number3;
    
   largest = number1; // assume first integer is largest

   //determine if number2 is greater than largest. If so assign number2 to largest
   if (number2>largest)
   {
      largest=number2;
   }
   
   //determine if number3 is greater than largest. If so assign number3 to largest
   if (number3>largest)
   {
      largest=number3;
   }
   
   smallest = number1; // assume first integer is smallest

   //determine if number2 is less than smallest. If so assign number2 to smallest
   if (number2<smallest)
   {
      smallest = number2;
   }

   //determine if number3 is less than smallest. If so assign number3 to smallest
   if (number3<smallest)
   {
      smallest = number3;
   }

   //prints the sum, average,product, largest and smallest
   cout << "sum "
        << number1+number2+number3 <<endl
        << "average "
        << (number1+number2+number3)/3.0 <<endl
        << "product "
        << number1*number2*number3 << endl
        << "largest "
        << largest <<endl
        << "smallest "
        << smallest <<endl;

   return 0; // indicate successful termination

} // end main

/*
 Input three different integers: 45 38 42
 sum 125
 average 41.6667
 product 71820
 largest 45
 smallest 38
 Program ended with exit code: 0
 
 Input three different integers: 28 47 36
 sum 111
 average 37
 product 47376
 largest 47
 smallest 28
 Program ended with exit code: 0
 
 Input three different integers: 10 10 10
 sum 30
 average 10
 product 1000
 largest 10
 smallest 10
 Program ended with exit code: 0
 */

