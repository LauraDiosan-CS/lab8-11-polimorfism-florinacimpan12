#pragma once
#include <vector>
#include <string>
#include "Utilizator.h"
#include "RepoSimpleUtilizator.h"
using namespace std;
class ServiceUtilizator
{
private:
	RepoS<Utilizator> utilizatori;
public:
	ServiceUtilizator();
	ServiceUtilizator(RepoS<Utilizator> repo);
	ServiceUtilizator(const ServiceUtilizator& s);
	~ServiceUtilizator();


	bool elementExistent(Utilizator& ut);

	ServiceUtilizator& operator=(const ServiceUtilizator& ut);
};