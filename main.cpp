#include <iostream>
#include "Resources.h"
#include "Processing.h"
#include "Quotes.h"
#include <memory>

using namespace std;

int main()
{	
	// ---------------------------- START OF UNIQUE PTRS ---------------------------

	// Intro screen;
	cout << "\n\n\t*** Books on Surveillance ***\n\n";
	cout << "  Reading data from an external file...\n\n";
	system("pause >nul | echo.  Continue...");
	system("CLS");

	// display to console a list of books (read from a file)
	Resources source;			// instantiating an object of Resource class
	source.getAppDescription();	// invoke function from Resources class
	source.iterThruVect();		// display list of books from external file
	system("pause >nul | echo. Continue...");
	system("CLS");

	// display to console a list, one entry at a time, of books (using unique_ptr)
	cout << "\n\n\t*** Books on Surveillance ***\n\n";
	cout << "  Allocating heap memory...\n\n";
	Processing process;			// instantiating an object from Processing class
	process.BookVector();		// invoking function from Processing class
	system("pause >nul | echo. 'Enter' to view ownership transfer of unique_ptr with 'move'?");
	system("CLS");

	// create a new unique_ptr w/ a new object using 'make_unique'
	cout << "  Creating a unique_ptr to a new object (using parameters)\n";
	// type varName = make_unique(keyword)<of type class Processing>(parameters)
	auto unique_book = make_unique<Processing>("Lyon, D. and E. Zureik.","(1998)","Computers, Surveillance and Privacy.","Minneapolis: University of Minnesota Press.");
	
	// display to console the values the unique_ptr points to
	// using arrow operator '->' to invoke functions of the object pointed to (unique_book of class Processing)
	cout << "\n  Values in unique_ptr 'unique_book' BEFORE ownership transfer...\n\n";
	cout << "  Author: " << unique_book->getAuthor()
			<< "\n" << "  Year: " << unique_book->getYear()
			<< "\n" << "  Title: " << unique_book->getTitle()
			<< "\n" << "  Publisher Info: " << unique_book->getPublisher()
			<< "\n\n";
	system("pause >nul | echo. Continue...");
	system("CLS");

	unique_ptr<Processing> moved_ptr = move(unique_book);	// transfer ownership of 'unique_book' ptr to 'moved_ptr' ptr

	if (!unique_book)									// verify unique_book is null
	{ 
		cout << "  *** Ownership is transferred from unique_ptr\n";
		cout << "  *** 'unique_book' is now a nullptr ->\t" << unique_book << "\n\n";
	}

	cout << "  Values of unique_ptr 'unique_book' have been transferred\n  to 'moved_ptr' AFTER ownership transfer...\n\n";
	cout << "  Value of 'moved_ptr' after changes:\n";
	cout << "\n" << "  Author: " << moved_ptr->getAuthor()
		<< "\n" << "  Year: " << moved_ptr->getYear()
		<< "\n" << "  Title: " << moved_ptr->getTitle()
		<< "\n" << "  Publisher Info: " << moved_ptr->getPublisher()
		<< "\n\n";

	system("pause >nul | echo. Continue...");
	cout << "\n\n";

	// using reset method for a unique_ptr
	// reset method relinquishes ownership and resets pointers values
	cout << "  Using 'reset' method on moved_ptr.\n";
	moved_ptr.reset(new Processing("Coleman, R.","(2004)","Reclaiming the Streets: Surveillance, Social Control and the City.","Cullompton, UK: Willan."));
	cout << "  Values of unique_ptr 'moved_ptr' have been reset.\n\n";
	cout << "  Value of 'moved_ptr' after changes:\n";
	cout << "\n" << "  Author: " << moved_ptr->getAuthor()
		<< "\n" << "  Year: " << moved_ptr->getYear()
		<< "\n" << "  Title: " << moved_ptr->getTitle()
		<< "\n" << "  Publisher Info: " << moved_ptr->getPublisher()
		<< "\n\n";
	system("pause >nul | echo. Continue...");
	system("CLS");

	// creating a local unique_ptr
	{
		cout << "  Creating a locally-scoped unique_ptr...\n";
		unique_ptr<Processing> localScope_ptr{ new Processing("Bogard, W.","(1996)","The Simulation of Surveillance: Hypercontrol in Telematic Societies.","Cambridge: Cambridge University Press.") };

		cout << "  Values of unique_ptr 'localScope_ptr':\n";
		cout << "\n" << "  Author: " << localScope_ptr->getAuthor()
			<< "\n" << "  Year: " << localScope_ptr->getYear()
			<< "\n" << "  Title: " << localScope_ptr->getTitle()
			<< "\n" << "  Publisher Info: " << localScope_ptr->getPublisher()
			<< "\n\n";

		cout << "  Leaving scope...\n";
		system("pause >nul | echo. Continue...");
		system("CLS");
	}

	 // ---------------------------- START OF SHARED_PTRS ------------------------

	cout << "\n\t  *** Moving on to shared_pointers...\n\n";
	cout << "  Creating a new shared pointer.\n";
	// create a new shared_ptr using 'make_shared'
	shared_ptr<Quotes> sayeth1 = make_shared<Quotes>();
	cout << "  Address of shared_ptr 'sayeth1':\t" << sayeth1.get() << "\n";  // using get() method, to print to display, pointed-to-object's address
	cout << "  Number of shared_ptr references in control block:\t";
	cout << sayeth1.use_count() << "\n";
	string aQuote = sayeth1->getQuote();
	cout << "  Quote:\n" << aQuote << "\n\n";
	system("pause >nul | echo. Continue...");

	// creating a copy of a shared pointer from an existing pointer
	cout << "  Creating a copy of a shared pointer...\n";
	shared_ptr<Quotes> sayeth2(sayeth1);	// using copy initialization
	cout << "  Address of shared_ptr 'sayeth2':\t" << sayeth2.get() << "\n";  // using get() method, to print to display, pointed-to-object's address
	cout << "  Number of shared_ptr references in control block:\t";
	cout << sayeth2.use_count() << "\n";
	aQuote = sayeth2->getQuote();
	cout << "  Quote:\n" << aQuote << "\n\n";
	system("pause >nul | echo. Continue...");

	// make a copy of shared_ptr sayeth1 (different way)
	cout << "  Creating a copy of a shared pointer (alternate)...\n";
	shared_ptr<Quotes> sayeth3 = sayeth1;  // creating new shared_ptr out of an existing shared_ptr
	cout << "  Address of shared_ptr 'sayeth3':\t" << sayeth3.get() << "\n";  // using get() method, to print to display, pointed-to-object's address
	cout << "  Number of shared_ptr references in control block:\t";
	cout << sayeth3.use_count() << "\n";
	aQuote = sayeth3->getQuote();
	cout << "  Quote:\n" << aQuote << "\n\n";
	system("pause >nul | echo. Continue...");

	// make a copy of shared_ptr using 'new'
	cout << "  Creating a NEW shared pointer, copy of existing shared_ptr...\n";
	shared_ptr<Quotes> sayeth4(new Quotes());
	sayeth4 = sayeth1;
	cout << "  Address of shared_ptr 'sayeth4':\t" << sayeth4.get() << "\n";  // using get() method, to print to display, pointed-to-object's address
	cout << "  Number of shared_ptr references in control block:\t";
	cout << sayeth4.use_count() << "\n";
	aQuote = sayeth4->getQuote();
	cout << "  Quote:\n" << aQuote << "\n\n";
	system("pause >nul | echo. Continue...");

	// using .reset() method to make shared_ptr object de-attach it's pointer
	cout << "  Using reset() method to relinquish ownership from sayeth1...\n";
	sayeth1.reset();	// release ownership of sayeth1 object (becomes nullptr)
	cout << "  sayeth1 address after using .reset():\t\t\t  ";
	cout << sayeth1.get() << "\n";	// show address of sayeth1 after reset method
	cout << "  sayeth2 address after using reset() method on sayeth1:  ";
	cout << sayeth2.get() << "\n";
	cout << "  sayeth3 address after using reset() method on sayeth1:  ";
	cout << sayeth3.get() << "\n";
	cout << "  sayeth4 address after using reset() method on sayeth1:  ";
	cout << sayeth4.get() << "\n";
	cout << "  Number of shared_ptr references in control block after reset:\t";
	cout << sayeth4.use_count() << "\n";
	system("pause >nul | echo. Continue...");
	system("CLS");

	// ---------------------------- START OF WEAK PTRS -------------------------------

	// A std::weak_ptr is simply a std::shared_ptr that is allowed to dangle
	cout << "\t  *** Moving on to shared_pointers...\n";
	cout << "  A weak_ptr is simply a shared_ptr that is allowed to dangle.\n\n";

	cout << "  Creating a weak_ptr...\n";
	cout << "\t *** no heap memory initialized.\n";
	weak_ptr<Quotes> w_sayeth2(sayeth2);	// w_sayeth2 is weak ptr to sayeth2
	cout << "  Converting a weak_ptr to a shared_ptr to access data...\n";
	shared_ptr<Quotes> convw_sayeth2 = w_sayeth2.lock();	// null if expired
	cout << "  Address of weak_ptr w_sayeth2:\t";
	cout << convw_sayeth2.get() << "\n\n";
	cout << "  Number of shared_ptr references in control block (after\n";
	cout << "  converting a weak_ptr to a shared_ptr for data access): \t";
	cout << sayeth4.use_count() << "\n\n";
	cout << "  Pointing sayeth2 to nullptr...\n\n";
	sayeth2 = nullptr;			// make a shared_ptr point to null
	cout << "  Number of shared_ptr references in control block (after\n";
	cout << "  pointing sayeth2 to null): \t\t\t\t\t";
	cout << sayeth4.use_count() << "\n\n";
	if (w_sayeth2.expired())	// is data pointed to by weak_ptr valid?
	{
		cout << "  sayeth2 is nullptr.\n";
		cout << "  Value of sayeth2:\t" << sayeth2.get() << "\n";
		cout << "  weak_ptr w_sayeth2 is now a dangling pointer.\n\n";
	}
	else
	{
		cout << "  Reference count remains greater than zero.\n\n";
	}

	system("pause >nul | echo. Continue...");
	system("CLS");

	cout << "\n\n  You have seen examples of smart pointers.  More specifically,\n";
	cout << "  unique_ptrs, shared_ptrs and weak_ptrs as well as a few of\n";
	cout << "  their methods.  Quite a bit of the allocated heap memory has been\n";
	cout << "  deallocated already.  Much of it still exists in the heap, but\n";
	cout << "  will be deallocated when leaving the program scope.\n\n";
	system("pause >nul | echo. Press any key to leave program scope...\n\n");

	return 0;
}	// END OF MAIN