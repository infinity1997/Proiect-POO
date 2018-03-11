#include "Volks_Tiguan.h"



VolksTiguan::VolksTiguan()
	:Volks()
{
	_tractiune4X4 = false;
	_pret_tiguan = 0;
}

VolksTiguan::VolksTiguan(int nrScaune, int nrPortiere, int capacitate, char * tara, char * comb, int contor, double pret, Data * dataLansare, int kWatt, bool tractiune,int TVA)
	:Volks(nrScaune, nrPortiere, capacitate, tara, comb, contor, pret, dataLansare, kWatt,TVA)
{
	_tractiune4X4 = tractiune;
}

void VolksTiguan::setPret()
{
	if (verificareCapacitate() == false)
		_pret_tiguan = getPret()*(getTVA() / 100);
	//daca verificarea este falsa pretul se calculeaza cu valoarea TVA actuala
	else
		_pret_tiguan = getPret()*((getTVA() + 3) / 100);
	//la TvA  se mai adauga un 3% la cel existent daca masina nu respecta reglementarile intrate in vigoare;

}

void VolksTiguan::citire(const char *filename)
{
	ifstream file;
	file.open(filename);
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
		file >> _tractiune4X4;
	}
	file.close();
}

void VolksTiguan::afisare( const char *filename)
{
	
	ofstream outData;
	outData.open(filename);
	if (outData.fail())
	{
		cout << "eroare la afisare in fisier Tiguan " << endl << endl;
		EXIT_FAILURE;
	}
	else
	{
	//	outData << " <?xml version=\"1.0\" encoding=\"utf - 8\"?> ";
		outData << "<Tiguan>\n";
		generareFunctii();
		afisareOutAuto(outData);
		afisareVolkswagen(outData);

		outData << "<Tractiune>" << _tractiune4X4 << "</Tractiune>";
		outData << "<Pret_Final>" << _pret_tiguan << "</Pret_Final>";
		outData << "</Tiguan>\n";

	}
	outData.close();
	
}


void VolksTiguan::generareFunctii()
{
	setPret();

}

void VolksTiguan::afisare()
{
	generareFunctii();
	afisareAuto();
	afisareVolkswagen();
	cout << setw(50) << "tractiunea masinii: " << setw(15) << _tractiune4X4 << endl;
	cout << setw(50) << "Pretul tot cu tva al masinii este: " << setw(15) << _pret_tiguan << endl;


}
