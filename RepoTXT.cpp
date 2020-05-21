#include "RepoTXT.h"
RepoTXT::RepoTXT()
{
	this->filename = "";
}

RepoTXT::RepoTXT(string filename)
{
	this->filename = filename;
	this->load_from_file();
	this->save_to_file();
}

RepoTXT::RepoTXT(const RepoTXT& repo)
{
	this->filename = repo.filename;
	this->load_from_file();
	this->save_to_file();
}

RepoTXT::~RepoTXT()
{
	this->clearRepo();
}

void RepoTXT::setFilename(string filename)
{
	this->filename = filename;
	this->load_from_file();
	this->save_to_file();
}

void RepoTXT::addElem(Resursa& param)
{
	Repo::addElem(param);
	this->save_to_file();
}

vector<Resursa*> RepoTXT::getAll()
{
	return this->elem;
}

void RepoTXT::update(Resursa& r1, Resursa& r2)
{
	int size = this->elem.size();
	for (int i = 0; i < size; i++)
	{
		if (this->elem[i]->toString() == r1.toString())
			this->elem[i] = r2.clone();
	}
	this->save_to_file();
}

void RepoTXT::deleteLastObj()
{
	Repo::deleteLastObj();
	this->save_to_file();
}

void RepoTXT::deleteObject(Resursa* r)
{
	this->deleteObj(r);
	this->save_to_file();

}

void RepoTXT::load_from_file()
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

void RepoTXT::save_to_file()
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

RepoTXT& RepoTXT::operator=(const RepoTXT& repo)
{
	this->setFilename(repo.filename);
	this->load_from_file();
	this->save_to_file();
	return *this;
}