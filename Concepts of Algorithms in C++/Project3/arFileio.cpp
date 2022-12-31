//  CS 200 - 
//  Example of:    -  Loading parallel arrays from a disk file
//                 -  Writing selected data to a new disk file
//  My source input file : "c:\InOutFile\score.txt"
//      NOTE:  if the file name is read from an input device,
//               single '\' are needed
//             if the file name is listed in the C++ source file,
//               because '\' is a special character, two '\' characters
//               are needed:
//                     file.open("c:\\InOutFile\\score.txt");

//  My destination output file : "c:\InOutFile\scoreOut.txt"

#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace::std;

bool loadData(const char [], int id[], int scores[],
			  int & count, int maxSize);

bool writeFile(const char [], const int id[], const int scores[],
			   int count, int level, int & written);

int search( const int [], int count, int key);

const int MAXSIZE= 15;
const int LOW_CUTOFF= 80;

void main()
{
	int idNumbers[MAXSIZE],  scores[MAXSIZE],  howMany;
	char fileName[80];
	cout << "Enter the name of the file to read : ";
	cin >> fileName;
	if( loadData(fileName,idNumbers,scores,howMany,MAXSIZE) )
		cout << "Data loaded" << endl;
	else
		cout << "Not able to load all of the records. " << endl;
	cout << howMany << " cells loaded \n";
	int find;
	cout << "Enter the score your are looking for : ";
	cin >> find;
	int whereF;
	whereF = search(scores,howMany,find);
	if (whereF != -1) 
		cout << "Score found for student " << idNumbers[whereF] << endl;
	else
		cout <<"Score not found\n";

	char outFileName[80];
	cout << "Enter the name of the output file : " ;
	cin >> outFileName;

	int written;
	if ( writeFile( outFileName,idNumbers,scores,howMany,LOW_CUTOFF,written) )
		cout << written << " records to the file " << outFileName << endl;
	else
		cout << "Output file not opened\n";
	return;

}

bool loadData(const char name[], int id[], int sc[], int & count,
			  int howMuchRoom)
{
	ifstream in;
	in.open(name);
	if ( ! in ) 
	{
		cout << " Can not open file ! \n";
		exit(8);  // terminate program
	}
	int i = 0;
	while ( i < howMuchRoom  &&  in >> id[i] >> sc[i] )
	{
		i++;
	}
	count = i;
	if(in.good())  // still more data in the file if the stream is good
	{
		in.close();
		return false;
	}
	else
	{
		in.close();
		return true;
	}
}

int search( const int d[], int c, int look)
{
	for(int i = 0; i < c; i++)
		if ( look == d[i] ) return i;
	return -1;
}

bool writeFile(const char name[], const int id[], const int scores[],
			   int count, int level, int & written)
{
   ofstream out;
   out.open(name);
   if (!out) return false;
   written = 0;
   for( int i = 0; i < count ; i++ )
   {
	   if ( scores[i ] <= level )
	   {
		   out << id[i] << ' ' << scores[i] << endl;
		   written++;
	   }
   }
   out.close();
   return true;
}

/*
Enter the name of the file to read : c:\InOutFile\score.txt
Data loaded
4 cells loaded
Enter the score your are looking for : 90
Score found for student 1224
Enter the name of the output file : c:\InOutFile\scoreOut.txt
2 records to the file c:\InOutFile\scoreOut.txt
Press any key to continue
*/

/*--------My input file : score.txt---------
1234    76
1224    90
1244    85
1254    68
*/

/*--------My output file : scoreOut.txt-------
1234 76
1254 68
*/
