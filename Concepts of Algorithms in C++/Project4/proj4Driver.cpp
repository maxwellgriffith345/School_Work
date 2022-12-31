
/**
*@author Maxwell Griffith
*@file proj4Driver.cpp
*/

#include <iostream>
#include <fstream>
#include "inventory.h"

using namespace::std;

bool  loadArray(char fileName[], inventory invList[],
                          int & count, int maxCells);

void printArray(ostream & where, const inventory invList[], int count);

bool extractData(char newFileName[],int requestId, int baseQty,
               const inventory invList[], int  count, int & newcount);

const int ORDER_NUMBER = 500;
int main()
{

	char fileName[80];
	char newFileName[80];

	int count;
	int newcount; 
	int requestID;
	
	inventory invList[ORDER_NUMBER];

	//open files and load array
	cout <<"Enter the name of the file to read : ";
	cin >> fileName;

	if( loadArray(fileName, invList, count, ORDER_NUMBER))
		cout << "Data loaded" <<endl;
	else
		cout <<"Not able to load all of the record. " <<endl;
	cout << count <<" cells loaded" <<endl;

	printArray(cout, invList, count);

	cout <<"Enter the name of the output file : ";
	cin >>  newFileName;
	
	cout <<"Enter ID number to search : ";
	cin >>requestID;
	

	if(extractData(newFileName, requestID, ORDER_NUMBER, invList, count, newcount))
		cout<< newcount <<" records to file " <<newFileName <<endl;
	else
		cout<<"Output file not opened" <<endl; 


	return 0;
}

void printArray(ostream & where, const inventory invList[], int count)
{
     for ( int i = 0; i < count; i++)
	 {
		 where << invList[i].getId() << ' ' << invList[i].getStoreNr()
			 << ' ' << invList[i].getQuantity() << endl;
	 }
}

bool  loadArray(char fileName[], inventory invList[], int & count, int maxCells)
{
	ifstream input;
	input.open(fileName);
	if(!input)
	{
		cout << "can not open fie" <<endl;
		exit(8);
	}

	int i=0; 
	int workId, workStore, workQty;

	while(i<maxCells && input >> workId >>workStore >> workQty)
	{
		invList[i].setId(workId);
		invList[i].setStoreNr(workStore);
		invList[i].setQuantity(workQty);
	
		i++;
	}
	count =i; 
	
	if(input.good())
	{
		input.close();
		return false;
	}
	else
	{
		input.close();
		return true;
	}

}

bool extractData(char newFileName[],int requestId, int baseQty,
               const inventory invList[], int  count, int & newcount)
{
	ofstream output;
	output.open(newFileName);
	if(!output)
	return false;
	
	newcount=0;

	for(int i=0; i<count; i++)
	{	
	if(invList[i].getId()==requestId && invList[i].getQuantity()<baseQty)
	{
		output <<invList[i].getId() <<invList[i].getStoreNr() <<invList[i].getQuantity()
		<<endl;
	
		newcount++;
	}
	else
	continue;
	}
	
	output.close();
	return true; 
}


/*
Enter the name of the file to read : info.txt
Data loaded
20 cells loaded
222 1 111
222 3 64
222 3 111
444 3 800
222 2 111
222 5 89
222 3 111
222 3 600
444 3 111
222 3 462
555 3 111
222 4 30
222 4 111
222 2 100
444 3 111
222 5 114
222 3 111
678 6 354
222 6 111
678 3 76
Enter the name of the output file : newinfo.txt
Enter ID number to search : 444
2 records to file newinfo.txt

Enter the name of the file to read : info.txt
Not able to load all of the record. 
1 cells loaded
222 1 111
Enter the name of the output file : newinfo.txt
Enter ID number to search : 444
0 records to file newinfo.txt


*/
