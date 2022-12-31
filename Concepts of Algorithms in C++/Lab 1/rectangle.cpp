/**
 *@author Maxwell Griffith
 *@file rectangle.cpp
 */

#include <iostream>

using std::cout; // program uses cout
using std::endl; // program uses endl
using std::cin; // program uses cin

int main()
{
    double length;
    double width;
    double area;
    double perimeter;
    
    // gets length and width values from user
    cout << "Enter length and width:";
    cin >>length;
    cin >>width;
    
    // defines how area and perimeter will be calculated
    area = length*width;
    perimeter = 2*length + 2*width;
    
    // displays length, width, area, and perimeter
    cout << "length ";
    cout <<length <<endl;
    cout << "width ";
    cout <<width <<endl;
    cout << "area ";
    cout <<area <<endl;
    cout << "perimeter ";
    cout <<perimeter <<endl;
    
   return 0; // indicate successful termination

} // end main
 
/*
  Enter length and width:2.5 3.4
  length 2.5
  width 3.4
  area 8.5
  perimeter 11.8
  Program ended with exit code: 0
  */



