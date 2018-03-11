#include "DataLansare.h"
#include<fstream>
#include<iostream>

using namespace std;
Data::Data()
{
	_zi = _luna = _an = 0;
}

Data::Data(int zi, int luna, int an)
{
	_zi = zi;
	_luna = luna;
	_an = an;
}

void Data::citireData(ifstream & file)
{
	/*ifstream file;
	file.open(filename);
	if (file.fail())
	{
		cout << endl << "Eroare la deschiderea fisierului testare !!" << endl;
		EXIT_FAILURE;
	}
	else*/
		{
		file >> _zi;
		file >> _luna;
		file >> _an;
		}
	//file.close();

}
