#include "ServiceUtilizator.h"

ServiceUtilizator::ServiceUtilizator()
{
}

ServiceUtilizator::ServiceUtilizator(RepoS<Utilizator> repo)
{
	this->utilizatori = repo;
}

ServiceUtilizator::ServiceUtilizator(const ServiceUtilizator& s)
{
	this->utilizatori = s.utilizatori;
}

ServiceUtilizator::~ServiceUtilizator()
{
}



bool ServiceUtilizator::elementExistent(Utilizator& ut)
{
	vector<Utilizator> vector_toate = this->utilizatori.getAll();
	for (int i = 0; i < vector_toate.size(); i++)
		if (vector_toate[i] == ut)
			return true;
	return false;
}

ServiceUtilizator& ServiceUtilizator::operator=(const ServiceUtilizator& ut)
{
	this->utilizatori = ut.utilizatori;
	return *this;
}
