#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
template <class T>
class RepoS
{
protected:
	string filename;
	vector<T> elem;
public:
	RepoS()
	{
		this->filename = "";
	}

	RepoS(string filename)
	{
		this->filename = filename;
		this->load_from_file();

	};

	RepoS(const RepoS& repo) {
		this->filename = repo.filename;
		this->load_from_file();

	};

	~RepoS()
	{
	};


	void addElem(T& t) {
		this->elem.push_back(t);
	}
	vector<T> getAll()
	{
		return this->elem;
	}

	void load_from_file()
	{

		if (this->filename != "")
		{
			ifstream f(this->filename);
			string s;
			T element;
			while (f >> s)
			{
				element.informatiiDinString(s);
				this->addElem(element);
			}

			f.close();
		}

	}
};