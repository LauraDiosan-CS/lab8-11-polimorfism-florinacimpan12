#pragma once
#pragma once
#include <stdexcept>
using namespace std;
class DataError :public runtime_error {
private:
	string message;
public:
	DataError(string msg) : runtime_error(msg), message(msg) {};
	string what() {
		return this->message;
	}
};