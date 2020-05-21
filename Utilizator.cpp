#include "Utilizator.h"
Utilizator::Utilizator()
{
	this->username = "";
	this->parola = "";
}

Utilizator::Utilizator(string username, string parola)
{
	this->username = username;
	this->parola = parola;
}

Utilizator::Utilizator(const Utilizator& ut)
{
	this->username = ut.username;
	this->parola = ut.parola;
}

void Utilizator::setUsername(string username)
{
	this->username = username;
}

void Utilizator::setParola(string parola)
{
	this->parola = parola;
}

string Utilizator::getUsername()
{
	return this->username;
}

string Utilizator::getParola()
{
	return this->parola;
}

Utilizator* Utilizator::clone()
{
	Utilizator* ut = new Utilizator();
	ut->setUsername(this->username);
	ut->setParola(this->parola);
	return ut;
}

Utilizator& Utilizator::operator=(const Utilizator& ut)
{
	this->username = ut.username;
	this->parola = ut.parola;
	return *this;
}

bool Utilizator::operator==(const Utilizator& ut)
{
	return (this->parola == ut.parola && this->username == ut.username);
}

string Utilizator::toString()
{
	return this->username + ',' + this->parola;
}

void Utilizator::informatiiDinString(string str)
{
	vector<string> out;
	stringstream ss(str);

	string s;

	while (getline(ss, s, ',')) {
		out.push_back(s);
	}
	this->username = out[0];
	this->parola = out[1];
}


istream& operator>>(istream& is, Utilizator& ut)
{
	string username;
	string parola;
	is >> ut.username >> ut.parola;
	return is;
}

ostream& operator<<(ostream& os, const Utilizator& ut)
{
	os << ut.username << ' ' << ut.parola;
	return  os;
}
