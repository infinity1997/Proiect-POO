#pragma once
#include"auto.h"
#include<fstream>
#include<iostream>

class Volks:public autoturism {

private:
	int _nrScaune;
	int _nrPortiere;
	int _capacitateMotor;
	char *_taraOrigine;
	int _TVA;
public:
	Volks();
	Volks(int nrScaune, int nrPortiere, int capacitate, char *tara, char *comb, int contor, double pret, Data *dataLansare, int kWatt, int TVA);
	~Volks() { if (_taraOrigine) delete[]_taraOrigine; }
	Volks &operator=(const Volks &a);
	virtual void setPret()=0;
	int getTVA() { return _TVA; }
	bool verificareCapacitate();

	
	virtual void citire(const char *filename);
	void afisareVolkswagen();


	void citireVolkswagen(ifstream &inData);
	void afisareVolkswagen(ofstream &outData);

	virtual void afisare();
	virtual void afisare(const char *filename);
};

