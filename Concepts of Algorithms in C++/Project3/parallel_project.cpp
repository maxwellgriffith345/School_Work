/**
*@author Maxwell Griffith
*@file parallel_project.cpp
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace::std;

//function declarations
bool loadArrays(const char fileName[], long idArray[], int storeArray[], int qtyArray[], int& cout, int maxCells);

void printArrays(ostream& where, const long idArray[], const int storeArray[], const int qtyArray[], int count);

bool extractData(const char newFileName[], int requestId, int baseQty, const long IdArray[], const int storeArray[],
			const int qtyArray[], int count, int& newcount); 


const int ORDER_NUMBER = 500; //quantity value used to extract data

int main()
{
	//Variable Declarations
	char fileName[80]; //name of file w/ information
	char newFileName[80];	//name of the file of extracted records

	int requestID; //product id number used to extract data

	long idArray[ORDER_NUMBER]; //array of id numbers
	int storeArray[ORDER_NUMBER]; //array of store numbers
	int qtyArray[ORDER_NUMBER]; //array of quantities
	
	int count; //acutal number of cells filled in the arrays
	int newcount; //the number of extracted records written to newFileName


	//open files and load array
	cout << "Enter the name of the file to read : ";
	cin >> fileName;

	if( loadArrays(fileName, idArray, storeArray, qtyArray, count, ORDER_NUMBER))
		cout << "Data loaded" <<endl;
	else
		cout << "Not able to load all of the records. " <<endl;
	
	cout << count <<" cells loaded" <<endl;


	printArrays(cout, idArray, storeArray, qtyArray, count);

	//output array to file
	cout <<"Enter the name of the output file : ";
	cin >> newFileName;
	
	cout <<"Enter ID number to search : ";
	cin >> requestID;
	
	if(extractData(newFileName, requestID, ORDER_NUMBER, idArray, storeArray, qtyArray, count, newcount))
		cout<< newcount <<" records to file " <<newFileName <<endl;
	else
		cout <<"Output file not opened" <<endl;

return 0;

}


bool loadArrays(const char fileName[], long idArray[], int storeArray[], int qtyArray[], int& count, int maxCells)
{
	ifstream input;
	input.open(fileName);
	if(!input)
	{
		cout << " Can not open file!" <<endl;
		exit(8); //terminate program
	}
	int i=0;
	while( i <maxCells && input >> idArray[i] >> storeArray[i] >> qtyArray[i])
	{
		i++;
	}
	count = i;
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


void printArrays(ostream& where, const long idArray[], const int storeArray[], const int qtyArray[], int count)
{
	
	for( int i=0; i < count; i++)
	{
		where << idArray[i] << ' ' << storeArray[i] << ' ' << qtyArray[i] <<endl;
	}

}

bool extractData(const char newFileName[], int requestId, int baseQty, const long idArray[], const int storeArray[],
			const int qtyArray[], int count, int& newcount)
{
	ofstream output;
	output.open(newFileName);
	if(!output)
	return false;

	newcount=0;
		
	for( int i=0; i < count; i++)
	{
		if(idArray[i] == requestId && qtyArray[i] < baseQty)
		{
			
			output << idArray[i] << ' ' << storeArray[i] << ' ' << qtyArray[i] <<endl;
			
			newcount++;
		}
		
		else
		continue;
	}

	output.close();
	return true; 
	


}


/*

Enter the name of the file to read : /Users/maxwellgriffith/cs200/Project3/info.txt
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
Enter the name of the output file : /Users/maxwellgriffith/cs200/Project3/newinfo.txt
Enter ID number to search : 444
2 records to file /Users/maxwellgriffith/cs200/Project3/newinfo.txt

Enter the name of the file to read : /Users/maxwellgriffith/cs200/Project3/info.txt
Not able to load all of the records. 
19 cells loaded
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
Enter the name of the output file : /Users/maxwellgriffith/cs200/Project3/newinfo.txt
Enter ID number to search : 444
0 records to file /Users/maxwellgriffith/cs200/Project3/newinfo.txt

*/


