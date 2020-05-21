#pragma once
#include <stdexcept>
using namespace std;
class MyInputException :public runtime_error {
private:
	string message;
public:
	MyInputException(string msg) : runtime_error(msg), message(msg) {};
	string what() {
		return this->message;
	}
};