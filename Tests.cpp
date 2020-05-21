#pragma once
#include "Tests.h"

void Test::testMateriale()
{
	this->testGetMateriale();
	this->testSetMateriale();
	this->testOperatorMateriale();
	this->testCloneMateriale();

}

void Test::testGetMateriale()
{
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	assert(ev->getNume() == "Carbune");
	assert(ev->getData() == "12/12/2019");
	assert(ev->getValoare() == 200);
	assert(ev->getDurataDeViata() == 15);
	assert(ev->getNumarDeExemplare() == 100);
	delete ev;
}

void Test::testSetMateriale()
{
	Materiale* ev2 = new Materiale("Carbune_2", "12/12/2012", 210, 16, 200);
	ev2->setNume("Carbune");
	ev2->setData("12/12/2019");
	ev2->setValoare(200);
	ev2->setDurataDeViata(15);
	ev2->setNumarDeExemplare(100);
	assert(ev2->getNume() == "Carbune");
	assert(ev2->getData() == "12/12/2019");
	assert(ev2->getValoare() == 200);
	assert(ev2->getDurataDeViata() == 15);
	assert(ev2->getNumarDeExemplare() == 100);
	delete ev2;
}

void Test::testOperatorMateriale()
{
	Materiale* ev2 = new Materiale("Carbune_2", "12/12/2012", 210, 16, 200);
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	ev2 = ev;

	assert(ev2->getNume() == "Carbune");
	assert(ev2->getData() == "12/12/2019");
	assert(ev2->getValoare() == 200);
	assert(ev2->getDurataDeViata() == 15);
	assert(ev2->getNumarDeExemplare() == 100);
	delete ev;

}

void Test::testCloneMateriale()
{
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	Materiale* ev2 = ev->clone();
	assert(ev2->getNume() == "Carbune");
	assert(ev2->getData() == "12/12/2019");
	assert(ev2->getValoare() == 200);
	assert(ev2->getDurataDeViata() == 15);
	assert(ev2->getNumarDeExemplare() == 100);
	delete ev;
	delete ev2;
}



void Test::testResursa()
{
	this->testGetResursa();
	this->testOperatorResursa();
	this->testSetResursa();
}

void Test::testGetResursa()
{
	Resursa* ev = new Resursa("Diamant", "12/12/2012", 200);
	assert(ev->getNume() == "Diamant");
	assert(ev->getData() == "12/12/2012");
	assert(ev->getValoare() == 200);
	delete ev;

}

void Test::testOperatorResursa()
{
	Resursa* ev1 = new Resursa("Diamant", "12/12/2012", 200);
	Resursa* ev2 = new Resursa("Nope", "12/10/1956", 200);
	ev2 = ev1;
	assert(ev2->getNume() == "Diamant");
	assert(ev2->getData() == "12/12/2012");
	assert(ev2->getValoare() == 200);
	delete ev1;

}

void Test::testSetResursa()
{


	Resursa* ev2 = new Resursa("Carbune", "12/12/2013", 100);
	ev2->setData("12/12/2012");
	ev2->setNume("Diamant");
	ev2->setValoare(200);

	assert(ev2->getNume() == "Diamant");
	assert(ev2->getData() == "12/12/2012");
	assert(ev2->getValoare() == 200);
	delete ev2;
}



void Test::testFinanciare()
{
	this->testGetFinanciare();
	this->testSetFinanciare();
	this->testCloneFinanciare();
}

void Test::testGetFinanciare()
{
	Financiare* ev2 = new Financiare("Diamant", "12/12/2012", 200, "RON");
	assert(ev2->getNume() == "Diamant");
	assert(ev2->getData() == "12/12/2012");
	assert(ev2->getValoare() == 200);
	assert(ev2->getMoneda() == "RON");
	delete ev2;
}

void Test::testSetFinanciare()
{
	Financiare* ev2 = new Financiare("Carbune", "12/12/2019", 300, "EURO");
	ev2->setNume("Diamant");
	ev2->setData("12/12/2012");
	ev2->setValoare(200);
	ev2->setMoneda("RON");
	assert(ev2->getNume() == "Diamant");
	assert(ev2->getData() == "12/12/2012");
	assert(ev2->getValoare() == 200);
	assert(ev2->getMoneda() == "RON");
	delete ev2;
}

void Test::testOperatorFinanciare()
{
	Financiare* ev1 = new Financiare("Diamant", "12/12/2012", 200, "RON");
	Financiare* ev2 = new Financiare("Carbune", "12/12/2019", 300, "EURO");
	ev2 = ev1;
	assert(ev2->getNume() == "Diamant");
	assert(ev2->getData() == "12/12/2012");
	assert(ev2->getValoare() == 200);
	assert(ev2->getMoneda() == "RON");
	delete ev1;

}

void Test::testCloneFinanciare()
{
	Financiare* ev1 = new Financiare("Diamant", "12/12/2012", 200, "RON");
	Financiare* ev2;
	ev2 = ev1->clone();
	assert(ev2->getNume() == "Diamant");
	assert(ev2->getData() == "12/12/2012");
	assert(ev2->getValoare() == 200);
	assert(ev2->getMoneda() == "RON");
	delete ev1;
	delete ev2;
}







void Test::testRepoCSVFinanciare()
{

	RepoCSV repo = RepoCSV("TestCSV.csv");
	repo.clearRepo();
	Financiare* ev2 = new Financiare("Carbune", "12/12/2019", 300, "EURO");
	repo.addElem(*ev2);
	Financiare* fin = (Financiare*)repo.getAll()[0];
	assert(fin->getNume() == "Carbune");
	assert(fin->getData() == "12/12/2019");
	assert(fin->getValoare() == 300);
	assert(fin->getMoneda() == "EURO");
	Financiare* ev3 = new Financiare("Diamant", "12/12/2030", 300, "RON");
	repo.update(*ev2, *ev3);
	Financiare* fin2 = (Financiare*)repo.getAll()[0];
	assert(fin2->getNume() == "Diamant");
	assert(fin2->getData() == "12/12/2030");
	assert(fin2->getValoare() == 300);
	assert(fin2->getMoneda() == "RON");
	assert(repo.getAll().size() == 1);
	repo.deleteObj(ev3);
	assert(repo.getAll().size() == 0);
	delete ev2;
	delete ev3;

}

void Test::testRepoCSVMateriale()
{
	RepoCSV repo = RepoCSV("TestCSV.csv");
	repo.clearRepo();
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	repo.addElem(*ev);
	Materiale* fin = (Materiale*)repo.getAll()[0];
	assert(fin->getNume() == "Carbune");
	assert(fin->getData() == "12/12/2019");
	assert(fin->getValoare() == 200);
	assert(fin->getDurataDeViata() == 15);
	assert(fin->getNumarDeExemplare() == 100);
	Materiale* ev2 = new Materiale("Diamant", "12/12/2030", 300, 20, 100);
	repo.update(*ev, *ev2);
	Materiale* fin2 = (Materiale*)repo.getAll()[0];
	assert(fin2->getNume() == "Diamant");
	assert(fin2->getData() == "12/12/2030");
	assert(fin2->getValoare() == 300);
	assert(fin2->getDurataDeViata() == 20);
	assert(fin2->getNumarDeExemplare() == 100);
	repo.deleteObj(fin2);
	assert(repo.getAll().size() == 0);
	delete ev2;
	delete ev;
}

void Test::testRepoTXTFinanciare()
{
	RepoTXT repo = RepoTXT("TestTXT.txt");
	repo.clearRepo();
	Financiare* ev2 = new Financiare("Carbune", "12/12/2019", 300, "EURO");
	repo.addElem(*ev2);
	Financiare* fin = (Financiare*)repo.getAll()[0];
	assert(fin->getNume() == "Carbune");
	assert(fin->getData() == "12/12/2019");
	assert(fin->getValoare() == 300);
	assert(fin->getMoneda() == "EURO");
	Financiare* ev3 = new Financiare("Diamant", "12/12/2030", 300, "RON");
	repo.update(*ev2, *ev3);
	Financiare* fin2 = (Financiare*)repo.getAll()[0];
	assert(fin2->getNume() == "Diamant");
	assert(fin2->getData() == "12/12/2030");
	assert(fin2->getValoare() == 300);
	assert(fin2->getMoneda() == "RON");
	assert(repo.getAll().size() == 1);
	repo.deleteObj(ev3);
	assert(repo.getAll().size() == 0);
	delete ev2;
	delete ev3;
}

void Test::testRepoTXTMateriale()
{
	RepoTXT repo = RepoTXT("TestTXT.txt");
	repo.clearRepo();
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	repo.addElem(*ev);
	Materiale* fin = (Materiale*)repo.getAll()[0];
	assert(fin->getNume() == "Carbune");
	assert(fin->getData() == "12/12/2019");
	assert(fin->getValoare() == 200);
	assert(fin->getDurataDeViata() == 15);
	assert(fin->getNumarDeExemplare() == 100);
	Materiale* ev2 = new Materiale("Diamant", "12/12/2030", 300, 20, 100);
	repo.update(*ev, *ev2);
	Materiale* fin2 = (Materiale*)repo.getAll()[0];
	assert(fin2->getNume() == "Diamant");
	assert(fin2->getData() == "12/12/2030");
	assert(fin2->getValoare() == 300);
	assert(fin2->getDurataDeViata() == 20);
	assert(fin2->getNumarDeExemplare() == 100);
	repo.deleteObj(fin2);
	assert(repo.getAll().size() == 0);
	delete ev2;
	delete ev;
}

void Test::testRepoTXTBothResursa()
{
	RepoTXT repo = RepoTXT("TestTXT.txt");
	repo.clearRepo();
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	repo.addElem(*ev);
	Financiare* ev2 = new Financiare("Carbune", "12/12/2019", 300, "EURO");
	repo.addElem(*ev2);
	assert(repo.getAll().size() == 2);
	Financiare* ev3 = new Financiare("Diamant", "12/12/2030", 300, "RON");
	Materiale* mat = new Materiale("Diamant", "12/12/2030", 300, 20, 100);
	repo.update(*ev2, *ev3);
	repo.update(*ev, *mat);
	assert(repo.getAll()[0]->toString() == mat->toString());
	assert(repo.getAll()[1]->toString() == ev3->toString());
	repo.deleteObj(ev3);
	assert(repo.getAll().size() == 1);
	repo.clearRepo();
	delete ev2;
	delete ev3;
	delete mat;
	delete ev;
}

void Test::testRepoCSVBothResursa()
{
	RepoCSV repo = RepoCSV("TestTXT.csv");
	repo.clearRepo();
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	repo.addElem(*ev);
	Financiare* ev2 = new Financiare("Carbune", "12/12/2019", 300, "EURO");
	repo.addElem(*ev2);
	assert(repo.getAll().size() == 2);
	Financiare* ev3 = new Financiare("Diamant", "12/12/2030", 300, "RON");
	Materiale* mat = new Materiale("Diamant", "12/12/2030", 300, 20, 100);
	repo.update(*ev2, *ev3);
	repo.update(*ev, *mat);
	assert(repo.getAll()[0]->toString() == mat->toString());
	assert(repo.getAll()[1]->toString() == ev3->toString());
	repo.deleteObj(ev3);
	assert(repo.getAll().size() == 1);
	repo.clearRepo();
	delete ev2;
	delete ev3;
	delete mat;
	delete ev;
}



void Test::testService()
{
	this->testAddService();
	this->getByParamService();
	this->testupdateMatService();
	this->testUpdateFinService();
}

void Test::testAddService()
{
	Service service;
	service.addMateriale("Carbune", "12/12/2019", 200, 15, 100);
	service.addFinanciare("Carbune", "12/12/2019", 300, "EURO");
	assert(service.getAll().size() == 2);
	Materiale* mat = (Materiale*)service.getAll()[0];
	assert(mat->getNume() == "Carbune");
	assert(mat->getData() == "12/12/2019");
	assert(mat->getValoare() == 200);
	assert(mat->getDurataDeViata() == 15);
	assert(mat->getNumarDeExemplare() == 100);
	Financiare* fin = (Financiare*)service.getAll()[1];
	assert(fin->getNume() == "Carbune");
	assert(fin->getData() == "12/12/2019");
	assert(fin->getValoare() == 300);
	assert(fin->getMoneda() == "EURO");
	delete fin;
	delete mat;
}

void Test::getByParamService()
{
	Service service;
	service.addMateriale("Carbune", "12/12/2019", 200, 15, 100);
	service.addFinanciare("Diamant", "12/12/2019", 300, "EURO");
	service.addFinanciare("Carbune", "12/12/2019", 300, "EURO");
	vector<Resursa*> vec = service.get_by_param("Carbune", 2);
	assert(vec.size() == 2);
	Materiale* mat = (Materiale*)vec[0];
	assert(mat->getNume() == "Carbune");
	assert(mat->getData() == "12/12/2019");
	assert(mat->getValoare() == 200);
	assert(mat->getDurataDeViata() == 15);
	assert(mat->getNumarDeExemplare() == 100);
	Financiare* fin = (Financiare*)vec[1];
	assert(fin->getNume() == "Carbune");
	assert(fin->getData() == "12/12/2019");
	assert(fin->getValoare() == 300);
	assert(fin->getMoneda() == "EURO");

}

void Test::testupdateMatService()
{
	Service service;
	service.addMateriale("Diamant", "12/12/2019", 200, 15, 100);
	service.addFinanciare("Carbune", "12/12/2019", 300, "EURO");
	Materiale* ev = new Materiale("Carbune", "12/12/2019", 200, 15, 100);
	Materiale* ev2 = (Materiale*)service.getAll()[0];
	service.updateMateriala("Diamant", "Carbune", "12/12/2019", 200, 15, 100);
	Materiale* mat = (Materiale*)service.getAll()[0];
	assert(mat->getNume() == "Carbune");
	assert(mat->getData() == "12/12/2019");
	assert(mat->getValoare() == 200);
	assert(mat->getDurataDeViata() == 15);
	assert(mat->getNumarDeExemplare() == 100);
	delete mat;
	delete ev;

}

void Test::testUpdateFinService()
{
	Service service;
	service.addMateriale("Carbune", "12/12/2019", 200, 15, 100);
	service.addFinanciare("Diamant", "12/12/1995", 200, "RON");
	Financiare* ev = new Financiare("Carbune", "12/12/2019", 300, "EURO");
	Financiare* ev2 = (Financiare*)service.getAll()[1];
	service.updateFinanciara("Diamant", "Carbune", "12/12/2019", 300, "EURO");
	Financiare* fin = (Financiare*)service.getAll()[1];
	assert(fin->getNume() == "Carbune");
	assert(fin->getData() == "12/12/2019");
	assert(fin->getValoare() == 300);
	assert(fin->getMoneda() == "EURO");
	delete fin;
	delete ev;
}


void Test::testMain()
{
	this->testEntitati();
	this->testRepo();
	this->testService();
}

void Test::testEntitati()
{
	this->testResursa();
	this->testMateriale();

	this->testFinanciare();
}

void Test::testRepo()
{

	this->testRepoCSVFinanciare();
	this->testRepoCSVMateriale();
	this->testRepoTXTFinanciare();
	this->testRepoTXTMateriale();
	this->testRepoTXTBothResursa();
	this->testRepoCSVBothResursa();
}