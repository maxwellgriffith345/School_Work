/**
 *@author Maxwell Griffith
 *@file lab2_1.cpp
 */

#include <iostream>
#include <cmath>
using namespace std;
int main( )
{

    double a;
    double b;
    double c;
    double s;
    double perimeter;
    double area;
    
    // get lengths of sides from user
    cout << "enter the lengths of 3 sides of a triangle in ascending order";
    cin >> a;
    cin >> b;
    cin >> c;
    
    perimeter = a + b + c;
    s = 0.5 * perimeter;
    area = sqrt (s*(s-a)*(s-b)*(s-c));

    // displays side lengths, perimeter, and area
    cout << "side a=" << a <<"\n";
    cout << "side b=" << b <<"\n";
    cout << "side c=" << c <<"\n";
    cout << "perimeter=" << perimeter << "\n";
    cout << "area=" << area << "\n";
    
    // tests and displays if triangle is right triangle
    if ((c*c - (a*a+b*b)) == 0)
    {
        cout << "the triangle is right a triangle" << "\n";
    }
    else
    {
        cout << "the triangle is not a right triangle" << "\n";
    }
    
    return 0;
}

/*
 
 enter the lengths of 3 sides of a triangle in ascending order 3.0 4.0 5.0
 side a=3
 side b=4
 side c=5
 perimeter=12
 area=6
 the triangle is right a triangle
 Program ended with exit code: 0
 
 enter the lengths of 3 sides of a triangle in ascending order 5.0 6.0 7.0
 side a=5
 side b=6
 side c=7
 perimeter=18
 area=14.6969
 the triangle is not a right triangle
 Program ended with exit code: 0
 
 */
