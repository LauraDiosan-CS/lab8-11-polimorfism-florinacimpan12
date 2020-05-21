#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
class Utilizator
{
private:
	string username;
	string parola;
public:
	Utilizator();

	Utilizator(string username, string parola);
	Utilizator(const Utilizator& ut);
	~Utilizator() {};

	void setUsername(string username);
	void setParola(string parola);

	string getUsername();
	string getParola();
	Utilizator* clone();
	Utilizator& operator=(const Utilizator& ut);
	bool operator==(const Utilizator& ut);

	string toString();
	void informatiiDinString(string s);
	friend istream& operator>>(istream& s, Utilizator& ut);
	friend ostream& operator<<(ostream& s, const Utilizator& ut);




};