#pragma once
#include <iostream>

using namespace std;

class Quotes
{
public:
    // void showQuote(string);
    string getQuote();

    // constructors
    // default constructor
    Quotes() 
    {
        cout << "  *** Memory allocated thru constructor.\n";
    } 
    // destructor
    ~Quotes() { cout << "  *** Memory deallocation from destructor.\n"; }  
private:
    string quote = "\t\"The reason you're reading this book\n\t is that I did a dangerous thing for\n\t a man in my position: I decided to\n\t tell the truth.\"\n";

};
