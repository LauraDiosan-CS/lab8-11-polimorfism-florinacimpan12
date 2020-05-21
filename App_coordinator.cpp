#include "Tests.h"
#include "Repo.h"
#include "ServiceUtilizator.h"
#include "Service.h"
#include "RepoSimpleUtilizator.h"
#include "Console.h"
#include <iostream>
using namespace std;
int main()
{
	Test test = Test();
	test.testMain();
	cout << "Merg testele" << endl;

	RepoS<Utilizator> repo = RepoS<Utilizator>("Autorizati.txt");
	ServiceUtilizator service = ServiceUtilizator(repo);
	Console c = Console(service);
	c.run();

	return 0;

}