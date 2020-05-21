#pragma once
#include "Repo.h"
#include "Resursa.h"
#include "Financiare.h"
#include "Materiale.h"
using namespace std;
class RepoTXT : public Repo
{
public:
	RepoTXT();
	RepoTXT(string filename);
	RepoTXT(const RepoTXT& repo);
	~RepoTXT();

	void setFilename(string filename);

	void addElem(Resursa& param);
	vector<Resursa*> getAll();
	void update(Resursa& r1, Resursa& r2);
	void deleteLastObj();
	void deleteObject(Resursa* r);

	void load_from_file();
	void save_to_file();

	RepoTXT& operator=(const RepoTXT& repo);


};