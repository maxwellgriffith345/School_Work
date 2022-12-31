/**
 *@author Maxwell Griffith
 *@file Lab2_2.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    
    int wind_speed;
   
    // gets wind speed from
    cout << "enter wind speed in miles per hour";
    cin >> wind_speed;
    
    // displays the category of the hurricane
    if (wind_speed < 74)
        cout << "not a hurricane" <<"\n";
    
    else if (wind_speed <= 95)
        cout << "1" << "\n";
    
    else if (wind_speed <= 110)
        cout << "2" << "\n";
        
    else if (wind_speed <= 130)
        cout << "3" << "\n";
        
    else if (wind_speed <= 155)
        cout << "4" << "\n";
        
    else // above 155 mph
        cout << "5" << "\n";
    
    return 0;
}

/*
 enter wind speed in miles per hour 70
 not a hurricane
 Program ended with exit code: 0
 
 enter wind speed in miles per hour 94
 1
 Program ended with exit code: 0
 
 enter wind speed in miles per hour 100
 2
 Program ended with exit code: 0
 
 enter wind speed in miles per hour 120
 3
 Program ended with exit code: 0
 
 enter wind speed in miles per hour 150
 4
 Program ended with exit code: 0
 
 enter wind speed in miles per hour 160
 5
 Program ended with exit code: 0
 
 */


