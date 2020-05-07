//Qinying Wu
//20783213
//q227wu
//ECE250
//Project 4: MST using Kruskal's Algorithm
//this is the header for the exception class object
#pragma once
#include <string>

using std::string;
class illegal_argument {
public:
	const string FAILEDSTR = "failure";
	const int FAILEDINT = -1;
	illegal_argument(); //constructor
	~illegal_argument(); //destructor

};
//constructor
illegal_argument::illegal_argument() {}
//destructor
illegal_argument::~illegal_argument() {}

