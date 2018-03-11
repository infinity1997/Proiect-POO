#pragma once

#include"dacia.h"
#include"Volks_Arteon.h"
#include"Volks_Tiguan.h"

class Element {
private:
	autoturism *produs;
	Element *urm;
	Element *ant;
public:
	Element() {}
	Element(autoturism *prd);
	autoturism *getAutoturism() { return produs; }
	friend class Lista;
	~Element();
}; 

class Lista {
	Element *coada;
	Element *cap;
	int nrElem; 
	//nrElem va retine numarul de elemente din lista
	// acesta ne ajuta la verificarea listei daca este Vida sau NU
public:
	Lista();
	~Lista();
	
	void add(Lista *&e, Element *p);
	void addNodeAsTail(Lista *&e,Element *p);
	void addNodeAsHead(Lista *&e,Element * p);
	Element* cautareDupaPret(Lista *e,int pretDorit);

	Element *getCap();
	Element *getCoada();
	int getNrElem();
	void sterge();
	void afisare();
	Element* next(Element *curent);
	Element* prev(Element *curent);
	int afisare2(int nr);
	void afisareF(const char *filename);
};