#include "Processing.h"
#include <iostream>

void Processing::BookVector()
{
	books.push_back(make_unique<Processing>("Ball, K. and Webster, F.", "(2003)", "The Intensification of Surveillance: Crime, Terrorism and Warfare in the Information Era.", "London: Pluto Press."));

	books.push_back(make_unique<Processing>("Gould, B and Neyland, D.", "(2009)", "New Directions in Surveillance and Privacy.", "Collumpton: Willan."));

	books.push_back(make_unique<Processing>("Haggerty, K. and Ericson, R.", "(2006)", "The New Politics of Surveillance and Visibility.", "Toronto: University of Toronto Press.."));

	books.push_back(make_unique<Processing>("Levin, T. Y., Frohe, U. and Weibel, P.", "(2002)", "CTRL [Space]: Rhetorics of Surveillance from Bentham to Big Brother.", "Cambridge, MA and London: MIT Press."));

	books.push_back(make_unique<Processing>("Lyon, D.", "(2003)", "Surveillance as Social Sorting: Privacy, Risk, and Digital Discrimination.", "London and New York: Routledge."));
	
	for (const auto& book : books)	// unique_ptr passed by reference.
	{
		cout << "\n" << "  Author:\t  " << book->getAuthor() 
			<< "\n" << "  Year:\t\t  " << book->getYear() 
			<< "\n" << "  Title:\t  " << book->getTitle() 
			<< "\n" << "  Publisher Info: " << book->getPublisher() << "\n\n";
		system("pause >nul | echo. View more...");
		system("CLS");
	}
}

string Processing::getAuthor()
{
	return author;
}
string Processing::getYear()
{
	return year;
}
string Processing::getTitle()
{
	return title;
}
string Processing::getPublisher()
{
	return publisher;
}

