#pragma once
#include <vector>
#include <string>

using namespace std;

// function prototype in the header .h file
class Resources
{
public:							// public access modifier, Class properties are private by default
	void getAppDescription();	// declare a function
	void iterThruVect();
	vector<string> booklist;
};
