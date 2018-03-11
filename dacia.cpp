#include "dacia.h"
#include<string.h>
using namespace std;

dacia::dacia()
{
	_facilitati=nullptr;
	_model = nullptr;
	_motorizare = nullptr;
	_nrModele = 0;
}

dacia::dacia(char *comb, int contor, double pret, Data *dataLansare, int kWatt, char *model, char *motorizare, int nrModele, Facilitati *facilitati)
	:autoturism(comb, contor,pret,dataLansare,kWatt)
{
	if (model)
	{
		_model = new char[strlen(model) + 1];
		strcpy_s(_model, strlen(model) + 1, model);

	}
	else
		_model = nullptr;

	if (motorizare)
	{
		_motorizare = new char[strlen(motorizare) + 1];
		strcpy_s(_motorizare, strlen(motorizare) + 1, motorizare);

	}
	else
		_motorizare = nullptr;

	_nrModele = nrModele;
	if (facilitati)
	{
		_facilitati = new Facilitati( *facilitati);					//se apeleaza constructorul fara parametri din class Facilitati
	}
	cout << "dacia(int)";

}

dacia::~dacia()
{
	if (_facilitati)
		delete _facilitati;
	//_facilitati = 0;
	if (_model)
		delete []_model;
	if (_motorizare)
		delete []_motorizare;
	cout << "~dacia()";
}
dacia::dacia( const dacia & a):autoturism(a)  // copy constructor call from class of base autoturism
{
	cout << "constructor copy dacia()   ";
	_nrModele = a._nrModele;

	if (this->_model)
		delete[]this->_model;

	this->_model = new char[strlen(a._model) + 1];
	strcpy_s(this->_model, strlen(a._model) + 1, a._model);

	if (this->_motorizare)
		delete[]this->_motorizare;

	this->_motorizare = new char[strlen(a._motorizare) + 1];
	strcpy_s(this->_motorizare, strlen(a._motorizare) + 1, a._motorizare);

	this->_facilitati = a._facilitati;


}

dacia & dacia::operator=(const dacia & a)
{

	cout<<"asignare_dacia() ";
	autoturism::operator=(a);

	if (this->_model)
		delete[]this->_model;
	
		this->_model = new char[strlen(a._model) + 1];
		strcpy_s(this->_model, strlen(a._model) + 1, a._model);


		if (this->_motorizare)
			delete[] this->_motorizare;

		this->_motorizare = new char[strlen(a._motorizare) + 1];
		strcpy_s(this->_motorizare, strlen(a._motorizare) + 1, a._motorizare);

	this->_nrModele = a._nrModele;

	if (this->_facilitati)
		delete[]_facilitati;
	this->_facilitati = new Facilitati;
	(*this->_facilitati)=(*a._facilitati);

	return *this;
}

void dacia::citire()
{
	ifstream file;
	file.open("intrareDacia.txt");
	if (file.fail())
	{
		cout << "eroare la deschiderea fisierului IntrareDacia.txt";
	}
	else
	{
	//	citireAuto("fisierA.txt");
		//citire date clasa de baza
		Facilitati *temporar = new Facilitati;
		// stocare temporara a continutului unei clase 
		temporar->citireDate(file);
		_facilitati=temporar;
		
		file.get();
		char aux[30];
		int i = 0;
		while ((aux[i] = file.get()) != '\n')
		{
			i++;
		}
		aux[i] = '\0';
		_model = new char[i + 1];
		strcpy_s(_model, i + 1, aux);

		

		char aux1[30];
		i = 0;
		while ((aux1[i] = file.get()) != '\n')
		{
			i++;
		}
		aux1[i] = '\0';
		_motorizare = new char[i + 1];
		strcpy_s(_motorizare, i + 1, aux1);

		//citire numar model ;membru al clasei dacia
		file >> _nrModele;

	}
	file.close();
}



void dacia::afisareDacia()
{
	ofstream file;
		file.open("afisareDacia.txt");
	if (file.fail())
		cout << "eroare la crearea fisierului de afisare Dacia!! ";
	else
	{
		//afisare(file);
		file << setw(50) << "modelul complet am masinii: " << setw(15) << _model << endl;
		file << setw(50) << "motorizare: " << setw(15) << _motorizare << endl;
		file << setw(50) << "numarul de modele care exista: " << setw(15) << _nrModele << endl;
		_facilitati->afisareFacilitati(file);
	}
	file.close();
}

void dacia::afisare()
{
	afisareAuto();
	cout << setw(50) << "modelul complet am masinii: " << setw(15) << _model << endl;
	cout << setw(50) << "motorizare: " << setw(15) << _motorizare << endl;
	cout << setw(50) << "numarul de modele care exista: " << setw(15) << _nrModele << endl;
	_facilitati->afisareFacilitati();

}
