#pragma once
#include <stdexcept>
using namespace std;
class SearchError :public runtime_error
{
private:
	string message;
public:
	SearchError(string msg) :runtime_error(msg), message(msg) {};
	string what()
	{ 
		return this->message;
	}



};