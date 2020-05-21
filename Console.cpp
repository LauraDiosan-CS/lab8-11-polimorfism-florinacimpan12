#include "Console.h"
#include "Utilizator.h"
#include "Validare.h"
#include <windows.h>
#include <iostream>
#include <cstddef>
#include "MyInputException.h"
using namespace std;
Console::Console(ServiceUtilizator service_ut)
{
	this->service_ut = service_ut;
}

void Console::menu()
{
	cout << "Alegeti optiunea:" << endl;
	cout << "1.Cautare" << endl;
	cout << "2.Modificare" << endl;
	cout << "x.Iesire din program" << endl;
}

void Console::menu_2()
{
	cout << "Ce doriti sa modificati?: " << endl;
	cout << "1.Resursele financiare" << endl;
	cout << "2.Resursele materiale" << endl;
}

int Console::run()
{
	while (true)
	{
		string username;
		string parola;
		cout << "Introduceti username-ul dummneavoastra: ";
		cin >> username;
		cout << "Introduceti parola dumneavoastra: ";
		cin >> parola;
		Utilizator* ut = new Utilizator(username, parola);
		try {
			validare.dacaExistaUtilizatorul(ut, this->service_ut);
			string optiune_globala;
			cout << "Ce tip de fisier doriti sa folositi pentru resurse?(CSV/TXT):";
			optiune_globala = this->untilGivenCorectOption();
			this->service.setRepo(optiune_globala, this->filename_csv, this->filename_txt);
			this->print_HTML<Resursa>(this->service.getAll(), this->filename_1);
			char option;
			while (true)
			{
				this->menu();
				cin >> option;
				if (option == '1')
				{
					try {
						this->cautare();
					}
					catch (SearchError& exc) {
						cout << exc.what() << endl;
						cout << "Veti reveni la meniu" << endl;
					}
				}
				else if (option == '2')
				{
					this->menu_2();
					char option_2;
					cin >> option_2;
					if (option_2 == '1')
						this->modificareResursaFinanciara();
					else if (option_2 == '2')
						this->modificaResursaMateriala();
					else
					{
						cout << "Ati introdus o optiune invalida,veti reveni la logare: " << endl;
						break;
					}
				}
				else if (option == 'x')
					return 0;
				else
				{
					cout << "Ati introdus o optiune invalida,veti reveni la logare: " << endl;
					break;
				}


			}

		}
		catch (MyInputException& exc) {
			cout << exc.what() << endl;
			string alternativa;
			cout << "Doriti sa mai incercati o data?(da/nu)" << endl;
			cin >> alternativa;
			try {
				validare.optiuneValida(alternativa);
				if (alternativa == "nu")
					return 0;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
				cout << "Se va inchide aplicatia de la sine";
				return 0;
			}


		}
	}

}

void Console::modificareResursaFinanciara()
{
	cout << "Introduceti numele resursei pe care vreti sa o modificati " << endl;
	string str;
	cin >> str;
	string str_mod;
	cout << "Introduceti toate atributele cu care vreti sa o modificati: " << endl;
	cin >> str_mod;

	vector<string> out;
	stringstream ss(str);

	string s;

	stringstream st(str_mod);
	while (getline(st, s, ',')) {
		out.push_back(s);
	}
	this->service.updateFinanciara(str, out[0], out[1], stoi(out[2], nullptr, 10), out[3]);


}

void Console::modificaResursaMateriala()
{
	cout << "Introduceti numele resursei pe care vreti sa o modificati: " << endl;
	string str;
	cin >> str;
	string str_mod;
	cout << "Introduceti toate atributele cu care vreti sa o modificati: " << endl;
	cin >> str_mod;

	vector<string> out;
	stringstream ss(str);

	string s;

	stringstream st(str_mod);
	while (getline(st, s, ',')) {
		out.push_back(s);
	}

	this->service.updateMateriala(str, out[0], out[1], stoi(out[2], nullptr, 10), stoi(out[3], nullptr, 10), stoi(out[4], nullptr, 10));

}

string Console::untilGivenCorectData()
{
	string data;
	cin >> data;
	while (true)
	{
		try
		{
			validare.validareData(data);
			break;
		}
		catch (DataError& exc) {
			cout << exc.what() << endl;
			cout << "Introduceti din nou data:" << endl;
			cin >> data;
		}

	}
	return data;
}

string Console::untilGivenCorectOption()
{
	string optiune_financiare;
	cin >> optiune_financiare;
	while (true)
	{
		try
		{
			validare.exceptionRepo(optiune_financiare);
			break;
		}
		catch (MyInputException& exc) {
			cout << exc.what() << endl;
			cout << "Introduceti inca o data:" << endl;
			cin >> optiune_financiare;
		}

	}
	return optiune_financiare;
}


int Console::cautare()
{
	string searchedWord;
	int input;
	cout << "Doriti sa cautati dupa data sau dupa nume?" << endl;
	cout << "1.Data sau 2.Nume" << endl;
	cin >> input;
	int option = 0;
	if (input == 1)
	{
		cout << "Introduceti data: " << endl;
		option = 1;
	}
	else if (input == 2)
		cout << "Introduceti numele:" << endl;
	else
	{
		cout << "Ati introdus o optiune invalida, veti reveni la meniu" << endl;
		return 0;
	}
	if (option == 1)
		searchedWord = this->untilGivenCorectData();
	else
		cin >> searchedWord;
	vector<Resursa*> vector_f = this->service.get_by_param(searchedWord, input);
	if (vector_f.size() != 0) {
		this->print_HTML<Resursa>(vector_f, this->filename_1);
	}
	return 0;
}

void Console::showVectorFinanciare(vector<Financiare*> vector_s)
{
	for (int i = 0; i < vector_s.size(); i++)
		cout << vector_s[i]->toString() << endl;
}

void Console::showVectorMateriale(vector<Materiale*> vector_s)
{
	for (int i = 0; i < vector_s.size(); i++)
		cout << vector_s[i]->toString() << endl;
}