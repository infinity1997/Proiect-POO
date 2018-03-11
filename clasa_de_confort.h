#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>

class ClasConfort {
private:
	int _nrAirbag;
	int _nrScauneIncalzite;
	char *_nivelSiguranta;   // Low,Hight, Medium

public:
	ClasConfort() { _nrAirbag = _nrScauneIncalzite = 0; _nivelSiguranta = nullptr; }
	ClasConfort(int nrAirbag, int nrScauneIncalzite, char *nivelSiguranta);
	~ClasConfort() {
		if (_nivelSiguranta)
		{
			//	delete[]_nivelSiguranta;
			_nivelSiguranta = nullptr;
		}

		std::cout << "~clasconfort()";
	}

	ClasConfort & operator=(const ClasConfort &obj);
	int getNrAirbag() { return _nrAirbag; }
	int getScauneIncalzite() { return _nrScauneIncalzite; }
	char *getNivelSiguranta() { return _nivelSiguranta; }
	//void afisareConfort(ofstream  &out);
	//void citireConfort(ifstream &in);
	void afisareConfort();
};