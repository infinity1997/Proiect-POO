#include "OperatiiSimple.h"


// operatii pentru clasa Arteon--------------------------------------------------
OpAdaugareInLista::OpAdaugareInLista(char * nume, Lista *& list)
	:Operatie(nume)
{
	lista = list;
}

OpIncarcareListaArteon::OpIncarcareListaArteon(char * nume, Lista *& list)
:OpAdaugareInLista(nume,list){}

void OpIncarcareListaArteon::execOperatie()
{	
	autoturism *a1=new VolksArteon;
	a1->citire("citireArteon1.txt");
	Element *e1 = new Element(a1);

	autoturism *a2 = new VolksArteon;
	a2->citire("citireArteon2.txt");
	Element *e2 = new Element(a2);

	autoturism *a3 = new VolksArteon;
	a3->citire("citireArteon2.txt");
	Element *e3 = new Element(a3);

	autoturism *a4 = new VolksArteon;
	a4->citire("citireArteon3.txt");
	Element *e4 = new Element(a4);

	lista->addNodeAsTail(lista, e1);
	lista->addNodeAsTail(lista, e2);
	lista->addNodeAsHead(lista, e3);
	lista->addNodeAsHead(lista, e4);

}

OpAfisareLista1::OpAfisareLista1(char * nume, Lista * list)
:Operatie(nume)
{
	lista = list;
}

void OpAfisareLista1::execOperatie()
{

	cout << "continutul listei este: \n";
	lista->afisare();
	system("Pause");
}

// operatii clasa tiguan ----------------------------------------------------------
OpIncarcareListaTiguan::OpIncarcareListaTiguan(char * nume, Lista *& list)
	:OpAdaugareInLista(nume,list)
{}

void OpIncarcareListaTiguan::execOperatie()
{
	autoturism *a1 = new VolksTiguan;
	a1->citire("citireTiguan1.txt");
	Element *e1 = new Element(a1);

	autoturism *a2 = new VolksTiguan;
	a2->citire("citireTiguan2.txt");
	Element *e2 = new Element(a2);

	autoturism *a3 = new VolksTiguan;
	a3->citire("citireTiguan3.txt");
	Element *e3 = new Element(a3);

	autoturism *a4 = new VolksTiguan;
	a4->citire("citireTiguan4.txt");
	Element *e4 = new Element(a4);

	lista->addNodeAsTail(lista, e1);
	lista->addNodeAsTail(lista, e2);
	lista->addNodeAsHead(lista, e3);
	lista->addNodeAsHead(lista, e4);

}

OpAfisareLista2::OpAfisareLista2(char * nume, Lista * list)
	:Operatie(nume)
{
	lista = list;
}

void OpAfisareLista2::execOperatie()
{
	cout << "continutul listei este: \n";
	lista->afisare();
	system("Pause");

}

//operatii clasa dacia-------------------------------------------------------

OpIncarcareListaDacia::OpIncarcareListaDacia(char * nume, Lista *& list)
	:OpAdaugareInLista(nume, list)
{}

void OpIncarcareListaDacia::execOperatie()
{
	ClasConfort c1(10, 4, "Hight");
	Facilitati *f1 = new Facilitati(4, 5, c1);

	Data *pdata = new Data(12, 12, 2012);
	autoturism *a1 = new dacia("disel", 123124, 12000, pdata, 105, "dacia papuc", "manual", 20, f1);
	autoturism *a2 = new dacia("benzina", 176124, 10000, pdata, 140, "dacia logan", "manual", 20, f1);
	autoturism *a3 = new dacia("benzina", 200000, 8000, pdata, 170, "dacia sandero", "manual", 20, f1);

	Element *e1 = new Element(a1);
	Element *e2 = new Element(a2);
	Element *e3 = new Element(a3);


	lista->addNodeAsTail(lista, e1);

	lista->addNodeAsTail(lista, e2);

	lista->addNodeAsTail(lista, e3);
}


OpAfisareLista3::OpAfisareLista3(char * nume, Lista * list)
	:Operatie(nume)
{
	lista = list;
}

void OpAfisareLista3::execOperatie()
{
	cout << "Continutul listei este: \n";
	lista->afisare();
	system("Pause");

}

OpCautareDupaPret::OpCautareDupaPret(char * nume, Lista * lista)
	:Operatie(nume)
{
	this->lista = lista;
}


// operatia de cautare este valabila pentru oricare tip de lista (arteon tiguan si dacia)
void OpCautareDupaPret::execOperatie()
{
	cout << "Operatia de cautare isi propune sa afiseze clientului produsul in functie de pretul cautat! \n";
	float pretCautat;
	cout << "introduce pretul pe care vrei sa il aiba produsul: ";
	cin >> pretCautat;
	
	Element *cautat;

		cautat = lista->cautareDupaPret(lista, pretCautat);
		if (cautat == nullptr)
			cout << "Obiectul cu pretul: " << pretCautat << " nu exista!!";
		else
			cautat->getAutoturism()->afisare();
		system("pause");
}

OpAfisareListaXML::OpAfisareListaXML(char * nume, Lista * list)
	:Operatie(nume)
{
	this->lista = list;
}

void OpAfisareListaXML::execOperatie()
{
	 
	cout << "Afisarea listei in format XML: \n";
	lista->afisareF("outDataTiguan.xml");
	system("Pause");
}
