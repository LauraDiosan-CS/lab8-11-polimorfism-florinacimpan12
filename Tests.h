#pragma once
#include "Resursa.h"
#include "Financiare.h"
#include "Materiale.h"
#include "Repo.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "Service.h"
#include <cassert>

class Test
{
private:
	void testMateriale();
	void testGetMateriale();
	void testSetMateriale();
	void testOperatorMateriale();
	void testCloneMateriale();

	void testResursa();
	void testGetResursa();
	void testOperatorResursa();
	void testSetResursa();


	void testFinanciare();
	void testGetFinanciare();
	void testSetFinanciare();
	void testOperatorFinanciare();
	void testCloneFinanciare();


	void testRepoCSVFinanciare();
	void testRepoCSVMateriale();
	void testRepoTXTFinanciare();
	void testRepoTXTMateriale();
	void testRepoTXTBothResursa();
	void testRepoCSVBothResursa();

	void testAddService();
	void getByParamService();
	void testupdateMatService();
	void testUpdateFinService();

	void testEntitati();
	void testRepo();
	void testService();
public:
	void testMain();


};