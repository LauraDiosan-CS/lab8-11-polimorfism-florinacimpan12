#pragma once
#include <string>
#include <vector>
using namespace std;
class Resursa {
protected:
	string nume;
	string data;
	int valoare;

public:
	Resursa();
	Resursa(string, string, int);
	Resursa(const Resursa& e);
	~Resursa();

	void setNume(string);
	void setData(string);
	void setValoare(int);

	string getNume();
	string getData();
	int getValoare();

	virtual Resursa* clone() { return nullptr; };

	Resursa& operator=(const Resursa& e);
	virtual bool compare(const Resursa& r) { return 0; };
	virtual string getHtmlVersion() { return ""; }
	virtual string toString() { return ""; };
	virtual bool conditieAfisare() { return true; };
	virtual void informatiiDinString(string s) {};
};