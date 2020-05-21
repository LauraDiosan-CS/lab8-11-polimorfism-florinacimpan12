#pragma once
#include <iostream>
#include <string>
#include "ServiceUtilizator.h"
#include "Service.h"
#include "Validare.h"
#include <iostream>
#include <windows.h>
using namespace std;
class Console
{
	string filename_1 = "Html_1.htm";
	string filename_2 = "Html_2.htm";
	string filename_csv = "Resurse.csv";
	string filename_txt = "Resurse.txt";
private:
	Validare validare;
	ServiceUtilizator service_ut;
	Service service;
	string untilGivenCorectOption();
	int cautare();
	void showVectorFinanciare(vector<Financiare*> vector_s);
	void showVectorMateriale(vector <Materiale*> vector_s);
public:
	Console() {};
	Console(ServiceUtilizator service_ut);
	void menu();
	void menu_2();
	int run();

	void modificareResursaFinanciara();
	void modificaResursaMateriala();
	string untilGivenCorectData();

	template<typename T>
	void print_HTML(vector<T*> vector_obj, string fileName)
	{

		ofstream myfile;
		myfile.open(fileName);
		myfile << "<!DOCTYPE html><html><head><link href='https://fonts.googleapis.com/css2?family=Dancing+Script:wght@562;700&family=Righteous&display=swap' rel='stylesheet'><link href ='StyleSheet.css' rel = 'stylesheet'></head><body>";

		int n = vector_obj.size();

		for (int i = 0; i < n; i++)
		{
			/*(nr bucăti = 0 sau valoare = 0),*/
			if (vector_obj[i]->conditieAfisare())
			{
				myfile << "<p>" << vector_obj[i]->getHtmlVersion() << "</p>";
			}
			else
				myfile << "<h>" << vector_obj[i]->getHtmlVersion() << "<br><br></h>";

		}


		myfile << "</body></html>";
		myfile.close();

		ShellExecute(NULL, "open", fileName.c_str(), NULL, NULL, SW_SHOWNORMAL);

	};



};