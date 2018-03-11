#pragma once
#include"DataLansare.h"
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>


class autoturism {
	char *_comb;
	int _contor;
	float _pret;
	Data *_dataLansare;										 // class Data witch Save day.mounth.year 
	int _kWatt;
	
public:
	autoturism();
	autoturism( char *comb, int contor, float pret, Data *dataLansare, int kWatt);
	autoturism(const autoturism &a);
	
	char *getTipCombustibil() { return _comb; }
	int getNrContor() { return _contor; }
	Data *getDataLansare() { return _dataLansare; }
	float getPret() { return _pret; }
	int getKwatt() { return _kWatt; }
	void setData(Data a);
	
	virtual void citire(const char *filename);
	virtual void afisare();

	//citire scriere in fisier
	void citireAuto(ifstream &inData);
	virtual void afisare(const char *filename);
	void afisareOutAuto(ofstream &outData);
	
	//afisare consola
	void afisareAuto();
	
	virtual ~autoturism();
	autoturism &operator =(const autoturism & a);
	


};