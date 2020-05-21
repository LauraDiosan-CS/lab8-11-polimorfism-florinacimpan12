#include "Financiare.h"
#include <cstddef>

Financiare::Financiare()
{
	this->moneda = "";
}

Financiare::Financiare(string nume, string data, int valoare, string moneda) :Resursa(nume, data, valoare)
{
	this->moneda = moneda;
}

Financiare::Financiare(const Financiare& a) : Resursa(a)
{
	this->moneda = a.moneda;
}

Financiare::~Financiare()
{
}

void Financiare::setMoneda(string moneda)
{
	this->moneda = moneda;
}

string Financiare::getMoneda()
{
	return this->moneda;
}

Financiare* Financiare::clone()
{

	Financiare* newFinanciare = new Financiare();
	newFinanciare->setMoneda(this->moneda);
	newFinanciare->setData(this->data);
	newFinanciare->setNume(this->nume);
	newFinanciare->setValoare(this->valoare);

	return newFinanciare;


}

Financiare& Financiare::operator=(const Financiare& a)
{
	Resursa::operator=(a);
	this->moneda = a.moneda;
	return *this;
}

bool Financiare::compare(const Financiare& a)
{
	return (this->nume == a.nume) && (this->valoare == a.valoare) && (this->data == a.data) && (this->moneda == a.moneda);
}

string Financiare::toString()
{
	string s = "FIN," + this->nume + "," + this->data + "," + to_string(this->valoare) + "," + this->moneda;
	return s;
}



void Financiare::informatiiDinString(string str)
{

	vector<string> out;
	stringstream ss(str);

	string s;

	while (getline(ss, s, ',')) {
		out.push_back(s);
	}
	this->nume = out[1];
	this->data = out[2];
	this->valoare = stoi(out[3], nullptr, 10);
	this->moneda = out[4];

}

string Financiare::getHtmlVersion()
{
	string s;
	s.append("Aceasta este resursa financiara :<br>");
	s.append("Nume: ");
	s.append(this->nume);
	s.append("<br>");
	s.append("Data: ");
	s.append(this->data);
	s.append("<br>Valoare: ");
	s.append(to_string(this->valoare));
	s.append("<br>Moneda: ");
	s.append(this->moneda);
	s.append("<br>");
	return s;
}

bool Financiare::conditieAfisare()
{
	if (this->valoare == 0)
		return true;
	return false;
}

