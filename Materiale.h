#pragma once
#include <string>
#include "Resursa.h"

class Materiale :public Resursa {
private:
	int durataDeViata;
	int numarDeExemplare;
public:
	Materiale();
	Materiale(string nume, string data, int valoare, int durataDeViata, int numarDeExemplare);
	Materiale(const Materiale& f);
	~Materiale();

	int getDurataDeViata();
	int getNumarDeExemplare();

	void setDurataDeViata(int);
	void setNumarDeExemplare(int);


	Materiale* clone();
	string toString();
	void informatiiDinString(string s);
	string getHtmlVersion();
	bool conditieAfisare();
	Materiale& operator=(const Materiale& f);
	bool compare(const Materiale& f);
};