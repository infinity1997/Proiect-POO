#include "facilitati.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


Facilitati::Facilitati(int nrLocuri, int normaPoluare, ClasConfort  clasaConfort)
{
	_nrLocuri = nrLocuri;
	_normaPoluare = normaPoluare;
	//if (clasaConfort.getNrAirbag()!=0 && clasaConfort.getScauneIncalzite()!=0 && clasaConfort.getNivelSiguranta()!=nullptr)
	_clasaConfort = clasaConfort;
	//else
	//	_clasaConfort = nullptr;// atribuire pointer valoare
}

Facilitati & Facilitati::operator=(const Facilitati & obj)
{
	this->_nrLocuri = obj._nrLocuri;
	this->_normaPoluare = obj._normaPoluare;
	this->_clasaConfort = obj._clasaConfort;

	return *this;
}



void Facilitati::citireDate(ifstream & in)
{
	in >> _nrLocuri;
	in >> _normaPoluare;
//	_clasaConfort.citireConfort(in);

}

void Facilitati::afisareFacilitati(ofstream& out)
{
	
	out << setw(50) << "nr de locuri prevazute: " << setw(15) << _nrLocuri << endl;
	out<< setw(50) << "Norma de poluare: " << setw(15) << _normaPoluare << endl;
//_clasaConfort.afisareConfort(out);
}

void Facilitati::afisareFacilitati()
{
	
	cout << setw(50) << "nr de locuri prevazute: " << setw(15) << _nrLocuri << endl;
	cout << setw(50) << "Norma de poluare: " << setw(15) << _normaPoluare << endl;
	_clasaConfort.afisareConfort();
}
