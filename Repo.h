#pragma once
#include "Resursa.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class Repo
{
protected:
	string filename;
	vector<Resursa*> elem;
public:
	Repo()
	{
		this->filename = "";
	}
	Repo(string filename)
	{
		this->filename = filename;

	};

	Repo(const Repo& repo) {
		this->filename = repo.filename;

	};

	//destructor
	virtual ~Repo()
	{
	};

	void clearRepo()
	{
		for (int i = 0; i < this->elem.size(); i++)
			delete this->elem[i];
		this->elem.clear();
	}

	void addElem(Resursa& param)
	{
		this->elem.push_back(&param);
	}

	bool elementInRepo(Resursa* param)
	{
		int size = this->elem.size();
		for (int i = 0; i < size; i++)
			if (this->elem[i] == param)
				return true;
		return false;
	}

	vector<Resursa*> getAll()
	{
		return this->elem;
	}

	virtual void update(Resursa& r1, Resursa& r2) {
		int size = this->elem.size();
		for (int i = 0; i < size; i++)
		{
			if (this->elem[i]->toString() == r1.toString())
				this->elem[i] = r2.clone();
		}
	};

	void deleteLastObj()
	{
		this->elem.pop_back();

	}

	void deleteObj(Resursa* r)
	{
		bool deleted = 0;
		int size = this->elem.size();
		for (int i = 0; i < size; i++)
		{
			if (this->elem[i]->toString() == r->toString())
			{
				deleted = 1;
				for (int j = i; j < size - 1; j++)
					this->elem[j] = this->elem[j + 1];
			}
		}
		if (deleted)
		{
			this->elem.pop_back();
		}
	};

	Resursa* getAtPosition(int position) {
		return this->elem[position];
	}


	virtual void load_from_file() {};

	virtual void save_to_file() {};

};