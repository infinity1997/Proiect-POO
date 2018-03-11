#pragma once
#include"Volkswagen.h"
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
class VolksTiguan :public Volks {

private:
	bool _tractiune4X4;
	int _pret_tiguan;
public:
	VolksTiguan();
	VolksTiguan(int nrScaune, int nrPortiere, int capacitate, char * tara, char * comb, int contor, double pret, Data * dataLansare, int kWatt,bool tractiune, int TVA);
	~VolksTiguan() = default;
	void setPret();
	void citire(const char *filename);
	void afisare(const char *filename);
	void generareFunctii();
	void afisare();
	int getPretTiguan() { return _pret_tiguan; }


};