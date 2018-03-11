
#include "clasa_de_confort.h"
using namespace std;

ClasConfort::ClasConfort(int nrAirbag, int nrScauneIncalzite, char * nivelSiguranta)
{
	_nrAirbag = nrAirbag;
	_nrScauneIncalzite = nrScauneIncalzite;

	if (_nivelSiguranta)
		delete[]_nivelSiguranta;
	_nivelSiguranta = new char[strlen(nivelSiguranta)+1];
	
	strcpy_s(_nivelSiguranta, strlen(nivelSiguranta) + 1, nivelSiguranta);
}

ClasConfort & ClasConfort::operator=(const ClasConfort & obj)
{
	this->_nrAirbag = obj._nrAirbag;
	this->_nrScauneIncalzite = obj._nrScauneIncalzite;
	
	if (obj._nivelSiguranta)
	{
		this->_nivelSiguranta = new char[strlen(obj._nivelSiguranta) + 1];
		strcpy_s(this->_nivelSiguranta, strlen(obj._nivelSiguranta) + 1, obj._nivelSiguranta);
	}
	return *this;
}
void ClasConfort::afisareConfort()
{
	cout << setw(50) << "numarul de Airbag-uri: " << setw(15) << _nrAirbag << endl;
		cout<< setw(50) << "nr de scaune Incalzite: " << setw(15) << _nrScauneIncalzite << endl;
		cout << setw(50) << "Nivelul de Siguranta: " << setw(15) << _nivelSiguranta << endl;
	
}
//
//void ClasConfort::citireConfort(ifstream &in)
//{
//	in >> _nrAirbag;
//	in >> _nrScauneIncalzite;
//	char aux[10];
//	int i = 0;
//	while ((aux[i] = in.get()) != '\n')
//		i++;
//	aux[i] = '\0';
//	_nivelSiguranta = new char[i + 1];
//	strcpy_s(_nivelSiguranta, i + 1, aux);
//}

//
//void ClasConfort::afisareConfort(ofstream &out)
//{
//	out<< setw(50) << "numarul de Airbag-uri: " << setw(15) << _nrAirbag << endl;
//	out<< setw(50) << "nr de scaune Incalzite: " << setw(15) << _nrScauneIncalzite << endl;
//	out << setw(50) << "Nivelul de Siguranta: " << setw(15) << _nivelSiguranta << endl;
//
//}
