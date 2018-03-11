#include<iostream>
#include"Lista.h"
#include"Meniu-Submeniu.h"
#include"OperatiiSimple.h"


using namespace std;
int main()
{
//	cout << __DATE__;    // Tdata la care se face compilarea;
//	cout<<' '<< __TIME__;
//	//cout << endl << __cplusplus;  //se genereaza ptr compilatorul de c++;
//
//	//ClasConfort *c1= new ClasConfort(10, 4, "Hight");
//	ClasConfort c1(10, 4, "Hight");
//	Facilitati *f1= new Facilitati(4, 5, c1);
//	
//
//	VolksArteon a3;
//	a3.citireDateArteon();
//	a3.setPret();
//	a3.afisareGenerala();
//
//	VolksTiguan t;
//	t.citireDateTiguan();
//	t.setPret();
//	t.afisareGenerala();
//
//	cout << endl;
//	dacia d;
//	//d.citireDate();
//	d.afisareDacia();
//
//	//VolksArteon a2 (5, 4, 2000, "germania", "defalut", 10000, 15000, new Data(01, 01, 2017), 100, 0, 0, 0, 0, false, "das", 9);
//
//	//a1.afisare();
//	Data *pdata = new Data(12, 12, 2012);
//	dacia d2("disel", 123124, 12000, pdata, 105, "dacia papuc", "manual", 20, f1);
//	dacia d1;
////	autoturism *pa= new dacia(	"disel", 123124, 12000, new Data(12, 12, 2012), 105, "dacia papuc", "manual", 20, f1);
//	
////	pa->afisare();
//	d1 = d2;
//	//d2.afisare();
//	cout << "---------------------------------------------" << endl;
//	d1.afisareDacia();
//	dacia d3;
//	//d3.citireDate();
//	d3.afisareDacia();
////	delete c1;
////	delete f1;
////	delete pdata;
//
	Meniu *meniu = new Meniu("Parc auto ");

	Lista *list1=new Lista;
	
	Meniu *submeniuEchipamentA = new Meniu("Volkswagen Arteon");
	meniu->adaugaElement(submeniuEchipamentA);
	submeniuEchipamentA->adaugaElement(new OpIncarcareListaArteon("Adaugare produse", list1));
	submeniuEchipamentA->adaugaElement(new OpAfisareLista1("Afisare produse", list1));
	submeniuEchipamentA->adaugaElement(new OpCautareDupaPret("Cautare produs", list1));
	
	Lista *list2 = new Lista;

	Meniu *submeniuEchipamentT = new Meniu("Volkswagen Tiguan");
	meniu->adaugaElement(submeniuEchipamentT);
	submeniuEchipamentT->adaugaElement(new OpIncarcareListaTiguan("Adaugare produse", list2));
	submeniuEchipamentT->adaugaElement(new OpAfisareLista2("Afisare produse", list2));
	submeniuEchipamentT->adaugaElement(new OpCautareDupaPret("Cautare produs", list2));
	submeniuEchipamentT->adaugaElement(new OpAfisareListaXML("Afisare XML", list2));


	Lista *list3 = new Lista;

	Meniu *submeniuEchipamentD = new Meniu("Dacia");
	meniu->adaugaElement(submeniuEchipamentD);
	submeniuEchipamentD->adaugaElement(new OpIncarcareListaDacia("Adaugare produse", list3));
	submeniuEchipamentD->adaugaElement(new OpAfisareLista3("Afisare produse", list3));
	submeniuEchipamentD->adaugaElement(new OpCautareDupaPret("Cautare produs", list3));
	
	meniu->executa();
	system("Pause");


	return 0;
}