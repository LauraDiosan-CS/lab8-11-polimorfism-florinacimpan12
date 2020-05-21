#pragma once
#include "Repo.h"
#include "Resursa.h"
#include "Financiare.h"
#include "Materiale.h"
using namespace std;
class RepoCSV : public Repo
{
public:
	RepoCSV();
	RepoCSV(string filename);
	RepoCSV(const RepoCSV& repo);
	~RepoCSV();

	void setFilename(string filename);

	void addElem(Resursa& param);
	vector<Resursa*> getAll();
	void update(Resursa& r1, Resursa& r2);
	void deleteLastObj();
	void deleteObject(Resursa* r);

	void load_from_file();
	void save_to_file();

	RepoCSV& operator=(const RepoCSV& repo);


};