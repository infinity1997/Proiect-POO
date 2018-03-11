#pragma once
#include"Volkswagen.h"
#include<fstream>
class VolksArteon:public Volks {
private:
	int _lungime;
	int _latime;
	int _rezervor;
	int _nrSenzori;
	bool _camera_fata_spate;
	char *_numeModel;
	// pretul masini este calculat: pretul de pornite * TVA+(o valoarea , daca este cazul)
	float _pret_arteon;
	
public:
	VolksArteon();
	VolksArteon(int nrScaune, int nrPortiere, int capacitate, char *tara, char *comb, int contor, double pret, Data *dataLansare, int kWatt, int lungime, int latime, int rezervor, int nrSenzori, bool camera_fata_spate, char *numeModel, int TVA);
	~VolksArteon() { if (_numeModel) delete[]_numeModel; }
	void setPret();
	void citire(const char*filename);
	void citireDateArteon();
	void afisareDateArteon(ofstream &outData);
	void afisareGenerala();
	void afisare();

	void generareFunctii();
};
