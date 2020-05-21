
#pragma once
#include "Repo.h"
#include "Materiale.h"
#include "Repo.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include "SearchError.h"
#include <iostream>
using namespace std;
class Service
{
protected:
	Repo* repo;
	string optiune;
public:
	Service();
	Service(const Service& s);
	~Service() {};

	void setRepo(string optiune_1, string filename_1, string filename_2);
	void addMateriale(string nume, string data, int valoare, int durataDeViata, int numarDeExemplare);
	void addFinanciare(string nume, string data, int valoare, string moneda);

	template <typename T>
	vector<Resursa*> get_by_param(T param, int option)
	{
		vector<Resursa*> nou_vector;
		vector<Resursa*> vector_toate = this->repo->getAll();
		for (int i = 0; i < vector_toate.size(); i++)
		{
			if (option == 1)
			{
				if (vector_toate[i]->getData() == param)
					nou_vector.push_back(vector_toate[i]);
			}
			else if (vector_toate[i]->getNume() == param)
				nou_vector.push_back(vector_toate[i]);
		}
		if (nou_vector.size() == 0)
			throw SearchError("Nu exista un tip de obiect cu acest atribut");
		return nou_vector;
	}

	void updateMateriala(string nume_vechi, string nume, string data, int valoare, int durataDeViata, int numarDeExemplare);
	void updateFinanciara(string nume_vechi, string nume, string data, int valoare, string moneda);

	vector<Resursa*> getAll();
};