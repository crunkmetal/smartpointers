#include "Resources.h"
#include <iostream>		// for console input/output 
#include <fstream>		// for file streaming
#include <string>		// for getline

using namespace std;									// using standard namespace
// function to display a description of the program
void Resources::getAppDescription()
{
	string line;										// declare a variable
	ifstream introduction("books.txt", ios::in);		// declare/open a filestream from an external txt doc

	if (introduction.is_open())							// verify file is open and if so...
	{
		string tempString;

		// cout << "\n";
		while (getline(introduction, line))				// for each line of text in txt doc...
		{
			if (!line.empty())
			{
				tempString += line;
			}
			else
			{
				booklist.push_back(tempString);			// push file contents to a vector
				tempString = "";
			}
								
		}
		introduction.close();							// close file stream document to prevent corruption of doc
	}
	else												// if file is unable to open, let user know
	{
		cout << "\n  Unable to open input file.\n" << endl;
		system("pause");
		system("CLS");
	}
}

void Resources::iterThruVect()
{
	cout << "\n  A list of books on surveillance.  Using stack memory...\n\n";
	for (int i = 0; i < booklist.size(); i++)
	{
		cout << booklist[i] << "\n\n";
	}
}






