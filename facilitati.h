#pragma once
#include"clasa_de_confort.h"
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class Facilitati {

private:
	int _nrLocuri;
	int _normaPoluare;
	ClasConfort _clasaConfort;
public:
	Facilitati() { _nrLocuri = _normaPoluare = 0; ClasConfort _clasaConfort(); }
	Facilitati(int nrLocuri, int normaPoluare, ClasConfort clasaConfort);
	~Facilitati() { 
		/*if (_clasaConfort)
		{delete _clasaConfort;}*/
		//_clasaConfort = 0;
				std::cout << "~facilitati()"; }
	
	Facilitati & operator=(const Facilitati &obj);
	void citireDate(ifstream &in);
	void afisareFacilitati(ofstream &out);
	void afisareFacilitati();
};