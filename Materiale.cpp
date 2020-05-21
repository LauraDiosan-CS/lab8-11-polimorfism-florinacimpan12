#include "Materiale.h"
#include <sstream>
#include <string.h>
using namespace std;
//materiale(numele, data
//	intrării în companie, valoarea, durata de viață, număr de exemplare)
Materiale::Materiale()
{
	this->durataDeViata = 0;
	this->numarDeExemplare = 0;
}

Materiale::Materiale(string nume, string data, int valoare, int durataDeViata, int numarDeExemplare) :Resursa(nume, data, valoare)
{
	this->durataDeViata = durataDeViata;
	this->numarDeExemplare = numarDeExemplare;

}

Materiale::Materiale(const Materiale& f) :Resursa(f)
{
	this->durataDeViata = f.durataDeViata;
	this->numarDeExemplare = f.numarDeExemplare;
}

Materiale::~Materiale()
{//nu avem nimic de sters
}

int Materiale::getDurataDeViata()
{
	return this->durataDeViata;
}

int Materiale::getNumarDeExemplare()
{
	return this->numarDeExemplare;
}

void Materiale::setDurataDeViata(int durataDeViata)
{
	this->durataDeViata = durataDeViata;
}

void Materiale::setNumarDeExemplare(int numarDeExemplare)
{
	this->numarDeExemplare = numarDeExemplare;
}

Materiale* Materiale::clone()
{
	Materiale* newMateriale = new Materiale();
	newMateriale->setNume(this->nume);
	newMateriale->setData(this->data);
	newMateriale->setValoare(this->valoare);
	newMateriale->setDurataDeViata(this->durataDeViata);
	newMateriale->setNumarDeExemplare(this->numarDeExemplare);
	return newMateriale;
}

string Materiale::toString()
{
	string s = "MAT," + this->nume + "," + this->data + "," + to_string(this->valoare) + "," + to_string(this->durataDeViata) + "," + to_string(this->numarDeExemplare);
	return s;
}


void Materiale::informatiiDinString(string str)
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
	this->durataDeViata = stoi(out[4], nullptr, 10);
	this->numarDeExemplare = stoi(out[5], nullptr, 10);


}

string Materiale::getHtmlVersion()
{
	string s;
	s = "Aceasta este resursa materiala :";
	s.append("<br>");
	s.append("Nume: ");
	s.append(this->nume);
	s.append("<br>");
	s.append("Data: ");
	s.append(this->data);
	s.append("<br>");
	s.append("Valoare: ");
	s.append(to_string(this->valoare));
	s.append("<br>");
	s.append("Durata de viata: ");
	s.append(to_string(this->durataDeViata));
	s.append("<br>");
	s.append("Numar de exemplare: ");
	s.append(to_string(this->numarDeExemplare));
	s.append("<br>");

	return s;
}

bool Materiale::conditieAfisare()
{
	if (this->valoare == 0 || this->numarDeExemplare == 0)
		return true;
	return false;
}


Materiale& Materiale::operator=(const Materiale& f)
{
	Resursa::operator=(f);
	this->durataDeViata = f.durataDeViata;
	this->numarDeExemplare = f.numarDeExemplare;
	return *this;

}

bool Materiale::compare(const Materiale& a)
{
	return (this->nume == a.nume) && (this->valoare == a.valoare) && (this->data == a.data) && (this->durataDeViata == a.durataDeViata) && (this->numarDeExemplare == a.numarDeExemplare);
}

