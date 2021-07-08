#pragma once
#include "Resources.h"
#include <memory>		// for unique_ptr
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Processing
{
public:
    
    void BookVector();
    vector<unique_ptr<Processing>> books;   // create a unique_ptr to vector of type 'Processing' called 'books'
    
    string getAuthor();
    string getYear();
    string getTitle();
    string getPublisher();

    // constructors
    Processing() { cout << "  *** Memory allocated thru constructor.\n"; }      // default constructor
    
    Processing(string a, string b, string c, string d)                      // constructor taking four params
    {
        cout << "  *** Memory allocated thru parameterized constructor.\n";
        author = a;
        year = b;
        title = c;
        publisher = d;
    }
    ~Processing() { cout << "  *** Memory deallocation from destructor.\n"; }   // destructor
private:
    string author;
    string year;
    string title;
    string publisher;
};
