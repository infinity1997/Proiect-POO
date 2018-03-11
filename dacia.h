#pragma once
#include"facilitati.h"
#include"auto.h"
class dacia:public autoturism{
private:
	char *_model;
	char *_motorizare;
	int _nrModele;
	Facilitati *_facilitati;
public :
	dacia();
	dacia(char *comb, int contor, double pret,Data *dataLansare, int kWatt, char *model,char *motorizare, int nrModele, Facilitati *facilitati);
	~dacia();
	dacia(const dacia &a);
	dacia &operator=(const dacia &a);
	void citire();
	void afisareDacia();
	void afisare();

};