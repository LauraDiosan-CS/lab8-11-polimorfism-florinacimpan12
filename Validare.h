#pragma once
#include "Utilizator.h"
#include "ServiceUtilizator.h"
#include "MyInputException.h"
#include "DataError.h"
#include <string>
#include <sstream>
class Validare
{
public:
	void dacaExistaUtilizatorul(Utilizator* ut, ServiceUtilizator service_ut)
	{
		if (not service_ut.elementExistent(*ut))
			throw MyInputException("Utilizatorul nu exista");

	}
	void optiuneValida(string optiune)
	{
		if (optiune != "da" && optiune != "nu")
			throw MyInputException("Ati introdus o optiune invalida");
	}
	void exceptionRepo(string optiune)
	{
		if (optiune != "CSV" && optiune != "TXT")
			throw  MyInputException("Tipul de fisier trebuie sa fie CSV sau TXT");

	}

	void validareData(string data) {
		vector<string> out;
		stringstream ss(data);

		string s;

		while (getline(ss, s, '/')) {
			out.push_back(s);
		}
		int zi = stoi(out[0], nullptr, 10);
		int luna = stoi(out[1], nullptr, 10);
		int an = stoi(out[2], nullptr, 10);
		if (zi <= 0 || zi >= 32)
			throw DataError("Ziua trebuie sa fie intre 1 si 31");
		if (luna <= 0 || luna >= 13)
			throw DataError("Luna trebuie sa fie intre 1 si 12");
		if (an <= 0)
			throw DataError("Anul trebuie sa fie mai mare ca 0");

	}
	//void inputOption(int option)
	//{
	//	if (option != '1' && option != '2')
	//		throw MyInputException("Optiunea trb sa fie 1 sau 2");
	//}


};