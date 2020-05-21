
#include <string.h>
#include <string>
#include <sstream>
#include "Resursa.h"
using namespace std;

Resursa::Resursa()
{
	this->nume = "";
	this->data = "";
	this->valoare = 0;

}

Resursa::Resursa(string nume, string data, int valoare)
{
	this->data = data;
	this->nume = nume;
	this->valoare = valoare;

}

Resursa::Resursa(const Resursa& e)
{
	this->nume = e.nume;
	this->data = e.data;
	this->valoare = e.valoare;
}

Resursa::~Resursa()
{//pt string exista un destructor deja implimentat in biblioteca deci nu trb sa apelam nimic
}

void Resursa::setNume(string nume)
{
	this->nume = nume;
}

void Resursa::setData(string data)
{
	this->data = data;
}

void Resursa::setValoare(int valoare)
{
	this->valoare = valoare;
}


string Resursa::getNume()
{
	return this->nume;
}


string Resursa::getData()
{
	return  this->data;

}


int Resursa::getValoare()
{
	return this->valoare;
}



Resursa& Resursa::operator=(const Resursa& e)
{
	this->data = e.data;
	this->nume = e.nume;
	this->valoare = e.valoare;
	return *this;
}




