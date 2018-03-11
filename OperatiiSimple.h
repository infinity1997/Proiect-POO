#pragma once
#include "Meniu-Submeniu.h"
#include "lista.h"

// operatii pentru clasa Arteon

class OpAdaugareInLista :public Operatie
{
protected:
	Lista *lista;
public:
	OpAdaugareInLista(char *nume, Lista *&list);
	 void execOperatie()=0;
};

class OpIncarcareListaArteon :public OpAdaugareInLista
{
public:
	OpIncarcareListaArteon(char *nume, Lista *&list);
	void execOperatie();
};


// operatii pentru clasa tiguan.

class OpIncarcareListaTiguan :public OpAdaugareInLista
{
public:
	OpIncarcareListaTiguan(char *nume, Lista *&list);
	void execOperatie();
};


class OpAfisareLista2 :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista2(char *nume, Lista *list);
	void execOperatie();
};

class OpAfisareListaXML :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareListaXML(char *nume, Lista *list);
	void execOperatie();
};


// operatii pentru clasa dacia

class OpIncarcareListaDacia :public OpAdaugareInLista
{
public:
	OpIncarcareListaDacia(char *nume, Lista *&list);
	void execOperatie();
};


class OpAfisareLista3 :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista3(char *nume, Lista *list);
	void execOperatie();
};

//cautarea unui element dupa pret;
class OpCautareDupaPret :public Operatie
{
private:
	Lista *lista;
public:
	OpCautareDupaPret(char *nume, Lista *lista);
	void execOperatie();
};


// final---------------------------------------------------
class OpAdaugareProdusNou :public OpAdaugareInLista
{
public:
	OpAdaugareProdusNou(char *nume, Lista *&lista);
	void execOperatie();
};


class OpAfisareLista1 :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista1(char *nume, Lista *list);
	void execOperatie();
};



