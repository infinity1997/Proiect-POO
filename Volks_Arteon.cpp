#include "Volks_Arteon.h"
#include<string.h>
#include<iostream>
#include<iomanip>

using namespace std;

VolksArteon::VolksArteon()
	:Volks()
{
	_lungime = _latime = _rezervor = _nrSenzori = 0;
	_camera_fata_spate = false;
	_numeModel = nullptr;
}

VolksArteon::VolksArteon(int nrScaune, int nrPortiere, int capacitate, char * tara, char * comb, int contor, double pret, Data * dataLansare, int kWatt, int lungime, int latime, int rezervor, int nrSenzori, bool camera_fata_spate, char * numeModel, int TVA)
	:Volks(nrScaune,nrPortiere,capacitate,tara,comb,contor,pret,dataLansare,kWatt,TVA)
{
	 _lungime=lungime;
	 _latime=latime;
	 _rezervor=rezervor;
	 _nrSenzori=nrSenzori;
	 _camera_fata_spate=camera_fata_spate;

	 if( numeModel)
		 {
			 _numeModel = new char[strlen(numeModel) + 1];
			 strcpy_s(_numeModel, strlen(numeModel) + 1, numeModel);
		 }
}

void VolksArteon::setPret()
{
	_pret_arteon = getPret();
	double a=0;
	if (verificareCapacitate() == false)
	{
		a = getPret()*getTVA()*0.001;
		_pret_arteon = _pret_arteon+a;
	}
		//daca verificarea este falsa pretul se calculeaza cu valoarea TVA actuala
	else
	{
		a = getPret()*((getTVA() + 2) / 100);
		_pret_arteon = _pret_arteon + a;
	}
		//la TvA  se mai adauga un 2% la cel existent daca masina nu respecta reglementarile intrate in vigoare;


}

void VolksArteon::citire(const char* filename)
{
	ifstream file;
	file.open(filename);
	if (file.fail())
	{
		// file.is_open
		cout << "\n\t\t eroare la deschiderea fisierului! \n";
		EXIT_FAILURE;

	}
	else
	{
		citireAuto(file);
		citireVolkswagen(file);

		file.get();
		char aux_char[255];
		file.getline(aux_char, 25);
		_numeModel = new char[strlen(aux_char) + 1];
		strcpy_s(_numeModel, strlen(aux_char) + 1, aux_char);

		file >> _lungime;
		file >> _latime;
		file >> _rezervor;
		file >> _nrSenzori;
		file >> _camera_fata_spate;
	}
	file.close();
}


void VolksArteon::citireDateArteon()
{

	ifstream file;
	file.open("citireArteon.txt");
	if (file.fail())
	{
		// file.is_open
		cout << "\n\t\t Eroare la deschiderea fisierului! \n";
		EXIT_FAILURE;
	}
	else
	{
		citireAuto(file);
		citireVolkswagen(file);


		char aux_char[255];
		file.getline(aux_char, 25);
		_numeModel = new char[strlen(aux_char) + 1];
		strcpy_s(_numeModel, strlen(aux_char) + 1, aux_char);

		file >> _lungime;
		file >> _latime;
		file >> _rezervor;
		file >> _nrSenzori;
		file >> _camera_fata_spate;
	}
	file.close();
}

void VolksArteon::afisareDateArteon(ofstream &outData)
{
	outData << setw(50) << "lungimea: " << setw(15) << _lungime << endl;
	outData << setw(50) << "_latime: " << setw(15) << _latime<<endl;
	outData << setw(50) << "_rezervor " << setw(15) << _rezervor << endl;
	outData << setw(50) << "_nr de Senzori: " << setw(15) << _nrSenzori << endl;
	outData << setw(50) <<"Masina are inclusa camera fata-spate " << setw(15) <<(bool)_camera_fata_spate<<endl;
	outData << setw(50) << "Numele complet al modelului: " << setw(15) << _numeModel << endl;
	outData << setw(50) << "pretul masini tot cu TV este: " << setw(15) << _pret_arteon << endl;
}

void VolksArteon::afisareGenerala()
{
	ofstream outFile;
	outFile.open("outDataArteon.txt");
	if (outFile.fail())
	{
		cout << "eroare la afisare in fisier " << endl << endl;
		EXIT_FAILURE;
	}
	else
	{
		afisareVolkswagen(outFile);
		afisareDateArteon(outFile);
	}

}

void VolksArteon::afisare()
{
	generareFunctii();
	afisareAuto();
	afisareVolkswagen();
	cout << setw(50) << "lungimea: " << setw(15) << _lungime << endl;
	cout << setw(50) << "_latime: " << setw(15) << _latime << endl;
	cout << setw(50) << "_rezervor " << setw(15) << _rezervor << endl;
	cout << setw(50) << "_nr de Senzori: " << setw(15) << _nrSenzori << endl;
	cout << setw(50) << "Masina are inclusa camera fata-spate " << setw(15) << (bool)_camera_fata_spate << endl;
	cout << setw(50) << "Numele complet al modelului: " << setw(15) << _numeModel << endl;
	cout << setw(50) << "pretul masini tot cu TV este: " << setw(15) << _pret_arteon << endl;

}

void VolksArteon::generareFunctii()
{
	setPret();
}
