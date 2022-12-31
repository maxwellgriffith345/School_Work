/**
 *@author Maxwell Griffith
 *@file lab2_3.cpp
 */


#include <iostream>
using namespace std;

int main() {
    
    char choice;
    
    // get trip code from user
    cout << "enter trip code" ;
    cin >> choice;
    
    //displays countries in selected trip
    switch (choice)
    {
        case '1' : cout << "England,Netherlands,";
            
        case '2' : cout << "Germany,";
            
        case '3' : cout << "France,Italy" << "\n";
        break;
            
        default: cout << "not a valid trip code" << "\n";
        break;
    }
   
    return 0;
}


/*
 
 enter trip code 1
 England,Netherlands,Germany,France,Italy
 Program ended with exit code: 0
 
 enter trip code 2
 Germany,France,Italy
 Program ended with exit code: 0
 
 enter trip code 3
 France,Italy
 Program ended with exit code: 0
 
 enter trip code 4
 not a valid trip code
 Program ended with exit code: 0
 
 */
