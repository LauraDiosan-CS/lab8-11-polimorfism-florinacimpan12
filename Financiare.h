#pragma once
#include "Resursa.h"
#include <string.h>
#include <sstream>
using namespace std;

class Financiare : public Resursa {
private:
	string moneda;
public:
	Financiare();
	Financiare(string nume, string data, int valoare, string moneda);
	Financiare(const Financiare& a);
	~Financiare();

	void setMoneda(string moneda);
	string getMoneda();
	Financiare* clone();

	Financiare& operator=(const Financiare& a);
	bool compare(const Financiare& a);

	string toString();

	void informatiiDinString(string s);
	string getHtmlVersion();
	bool conditieAfisare();
};