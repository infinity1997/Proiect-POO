#include "Volkswagen.h"
#include<string.h>
#include<iomanip>
using namespace std;

Volks::Volks()
	:autoturism()
{
	_nrPortiere = _nrScaune = _capacitateMotor = _TVA = 0;
	_taraOrigine = nullptr;
}

Volks::Volks(int nrScaune, int nrPortiere, int capacitate, char * tara, char * comb, int contor, double pret, Data * dataLansare, int kWatt,int TVA)
	:autoturism(comb, contor, pret, dataLansare, kWatt)
{
	_nrScaune = nrScaune;
	_nrPortiere = nrPortiere;
	_capacitateMotor = capacitate;
	_TVA = TVA;

	
	if (tara != nullptr)
	{
		_taraOrigine = new char[strlen(tara) + 1];
		strcpy_s(_taraOrigine, strlen(tara) + 1, tara);
	}
	
}

Volks & Volks::operator=(const Volks & a)
{
autoturism::operator=(a);
_nrScaune = a._nrScaune;
_nrPortiere = a._nrPortiere;
_capacitateMotor = a._capacitateMotor;
_TVA = a._TVA;
if (a._taraOrigine != nullptr)
{
	_taraOrigine = new char[strlen(a._taraOrigine) + 1];
	strcpy_s(_taraOrigine, strlen(a._taraOrigine) + 1, a._taraOrigine);
}

return *this;
}

bool Volks::verificareCapacitate()
{
	//capacitatea motorului <2000 
	// si km parcursi <1500 se va returna false
	if (_capacitateMotor < 2000 && getNrContor() < 150000)
		return false;
	else
		//in cazul in care nu se respecta primul if si totusi anul de lansare al masinii este >=2012
		//atunci return false
		if (getDataLansare()->getAn() >= 2012)
			return false;

	return true;
}

void Volks::citire(const char *filename)
{
	ifstream file;
	file.open(filename);
	if (file.fail())
	{
		cout << endl << "Eroare la deschiderea fisierului volkswagen !!" << endl;
		EXIT_FAILURE;
	}
	else
	{
		char aux[255];
		file.getline(aux, 20);
		if (aux)
		{
			_taraOrigine = new char[strlen(aux) + 1];
			strcpy_s(_taraOrigine, strlen(aux) + 1, aux);
		}
		file >> _nrScaune;
		file >> _nrPortiere;
		file >> _capacitateMotor;
		file >> _TVA;
	}
	file.close();
}

void Volks::afisareVolkswagen()
{
	cout << setw(50) << "nr de scaune sunt: " << setw(15) << _nrScaune << endl;
	cout << setw(50) << "nr de portiere sunt: " << setw(15) << _nrPortiere << endl;
	cout << setw(50) << "capacitatea cilindrica a motorului este: " << setw(15) << _capacitateMotor << endl;
	cout << setw(50) << "_tara de fabricare: " << setw(15) << _taraOrigine << endl;
	cout << setw(50) << "valoarea TVA-ului este: " << setw(15) << _TVA << endl;

}

void Volks::citireVolkswagen(ifstream &inData)
{
	inData.get();
		char aux[255];
		inData.getline(aux, 20);
		if (aux)
		{
			_taraOrigine = new char[strlen(aux) + 1];
			strcpy_s(_taraOrigine, strlen(aux) + 1, aux);
		}
		inData >> _nrScaune;
		inData >> _nrPortiere;
		inData >> _capacitateMotor;
		inData >> _TVA;
	
}

void Volks::afisareVolkswagen(ofstream & outData)
// argumentul  functiei trebuie sa fie fisierul in care se va scrie datele
{
	
		outData << "<volkswagen>\n";
		outData << "<Nr_Scaune>" << _nrScaune << "</Nr_Scaune>";
		outData << "<Nr_Portiere>" << _nrPortiere << "</Nr_Portiere>";
		outData << "<Motor>" << _capacitateMotor << "</Motor>";
		outData << "<Tara_Origine>" << _taraOrigine << "</Tara_Origine>";
		outData << "<Tva >" << _TVA << "</Tva>";
		outData << "</volkswagen>\n";
		}

void Volks::afisare()
{
	cout << "afisare virtual clasa VOLKS";
}

void Volks::afisare(const char *filename)
{
	cout << "fisier afisare virtual";
}

