#include "RepoCSV.h"
RepoCSV::RepoCSV()
{
	this->filename = "";
}

RepoCSV::RepoCSV(string filename)
{
	this->filename = filename;
	this->load_from_file();
	this->save_to_file();
}

RepoCSV::RepoCSV(const RepoCSV& repo)
{
	this->filename = repo.filename;
	this->load_from_file();
	this->save_to_file();
}

RepoCSV::~RepoCSV()
{
	this->clearRepo();
}

void RepoCSV::setFilename(string filename)
{
	this->filename = filename;
	this->load_from_file();
	this->save_to_file();
}

void RepoCSV::addElem(Resursa& param)
{
	Repo::addElem(param);
	this->save_to_file();
}

vector<Resursa*> RepoCSV::getAll()
{
	return this->elem;
}

void RepoCSV::update(Resursa& r1, Resursa& r2)
{
	int size = this->elem.size();
	for (int i = 0; i < size; i++)
	{
		if (this->elem[i]->toString() == r1.toString())
			this->elem[i] = r2.clone();
	}
	this->save_to_file();
}

void RepoCSV::deleteLastObj()
{
	Repo::deleteLastObj();
	this->save_to_file();
}

void RepoCSV::deleteObject(Resursa* r)
{
	this->deleteObj(r);
	this->save_to_file();
}


void RepoCSV::load_from_file()
{
	if (this->filename != "")
	{
		Repo::clearRepo();
		ifstream f(this->filename);
		string s;
		while (f >> s)
		{
			string resursaType = s.substr(0, s.find(","));
			Resursa* res;
			if (resursaType == "FIN")
				res = new Financiare();
			else
				res = new Materiale();
			res->informatiiDinString(s);
			Repo::addElem(*res);

		}
		f.close();
	}
}

void RepoCSV::save_to_file()
{
	if (this->filename != "")
	{
		ofstream f(this->filename);

		for (Resursa* resursa : this->elem)
		{
			f << resursa->toString();
			f << '\n';
		}
		f.close();
	}
}

RepoCSV& RepoCSV::operator=(const RepoCSV& repo)
{
	this->setFilename(repo.filename);
	this->load_from_file();
	this->save_to_file();
	return *this;
}