#include "auto.h"

using namespace std;

autoturism::autoturism()
{
	_comb = nullptr;
	_contor = _pret = _kWatt = 0;
	_dataLansare = nullptr;

	cout << "auto() ";

}

autoturism::autoturism(char * comb, int contor, float pret, Data *dataLansare, int kWatt)
{
	if (comb)
	{
		_comb = new char[strlen(comb) + 1];
		strcpy_s(_comb, strlen(comb) + 1, comb);

	}
	else
		_comb = nullptr;

	if (dataLansare)
	{
		_dataLansare = dataLansare;
	}
	else
		_dataLansare = nullptr;

	_pret = pret;
	_kWatt = kWatt;
	_contor = contor;
	cout << "auto(int)";
}

autoturism::autoturism(const autoturism & a)
{
	if (this->_comb)
		delete[]this->_comb;

	this->_comb = new char[strlen(a._comb) + 1];
	strcpy_s(this->_comb, strlen(a._comb) + 1, a._comb);

	if (this->_dataLansare)
		delete this->_dataLansare;

	this->_dataLansare = a._dataLansare;
	this->_contor = a._contor;
	this->_pret = a._pret;
	this->_kWatt = a._kWatt;

	cout << "auto_constructor+cop(int)";
}

void autoturism::citire(const char *filename)
{
	cout << "citire elemente: ";
}

void autoturism::citireAuto(ifstream &inData)
{
		Data d;
		d.citireData(inData);
		Data *d1 = new Data(d.getZi(), d.getLuna(), d.getAn());
		_dataLansare = d1;

		inData.get();
		
		char aux[30];
		int i = 0;
		while ((aux[i]=inData.get())!='\n')
		{
			i++;
		}
		aux[i ] = '\0';
			_comb = new char[i + 1];
		strcpy_s(_comb, i+1, aux);
		
		inData >> _contor;
		inData >> _pret;
		inData >> _kWatt;

}

void autoturism::afisare(const char *filename)
{
	cout << "afisareAuto fisier virtual";
}

void autoturism::afisareOutAuto(ofstream & outData)
{
	outData << "<autoturism>\n";
	outData <<  "<combustibilul>" << _comb <<"</combustibilul>";
	outData << "<Kilometri>" << _contor << "</Kilometri>";
	outData << "<Pret_fara_TVA>" << _pret << "</Pret_fara_TVA>";
	
	outData << "<Data_Lansarii>";
	outData << "<Zi>" << _dataLansare->getZi() << "</Zi>";
	outData << "<Luna>" << _dataLansare->getLuna() << "</Luna>";
	outData << "<An>" << _dataLansare->getAn() << "</An>";
	outData<< "</Data_Lansarii>";
	outData << "<Puterea >" << _kWatt << "</Puterea>";
	
	outData << "</autoturism>\n";
}

void autoturism::afisareAuto()
{
	cout << setw(50) << "combustibilul folosit: " << setw(15) << _comb << endl;
	cout << setw(50) << "numarul de km parcursi: " << setw(15) << _contor << endl;
	cout << setw(50) << "pretul porneste de la : " << setw(15) << _pret << endl;
	cout << setw(50) << "data lansarii modelului: " << setw(15) << _dataLansare->getZi() << '-' << _dataLansare->getLuna() << '-' << _dataLansare->getAn() << endl;
	cout << setw(50) << "puterea masinii: " << setw(15) << _kWatt << endl;


}

autoturism::~autoturism()
{
	if (_comb)
		delete[]_comb;
	if (_dataLansare)
		delete[] _dataLansare;
//		_dataLansare = 0; // nu este o stergere propriuzisa a adresei 
	cout << "~auto() ";
}




void autoturism::afisare()
{
	cout<<"apel functie virtuala din autoturism";
}

autoturism & autoturism::operator=(const autoturism & a)
{
	if (this->_comb)
		delete[]this->_comb;

	this->_comb = new char[strlen(a._comb) + 1];
	strcpy_s(this->_comb, strlen(a._comb) + 1, a._comb);

	if (this->_dataLansare)
		delete this->_dataLansare;
	this->_dataLansare = new Data();
	(*this->_dataLansare) = (*a._dataLansare); //dereferentiere 
	//atribuire la noua adresa _dataLansare valoarea din a._dataLansare


//	this->_dataLansare = a._dataLansare;
	this->_contor = a._contor;
	this->_pret = a._pret;
	this->_kWatt = a._kWatt;

	cout << "auto_asignare()    ";
	return *this;
	// TODO: insert return statement here
}
