#include "Lista.h"

Element::Element(autoturism * prd)
{
	this->produs = prd;

}

Element::~Element()
{
	delete produs;
	produs = 0;
	urm = 0;
	ant = 0;
}

Lista::Lista()
{
	this->coada= nullptr;
	this->cap = nullptr;
	this->nrElem = 0;
}

Lista::~Lista()
{
	Element *aux;
	while (this->cap != nullptr)
	{
		aux = cap;
		cap = cap->urm;
		nrElem--;
		delete aux;
	}
	
}

Element *Lista::getCap()
{
	return this->cap;
}
Element *Lista::getCoada()
{
	return this->coada;
}


int Lista::getNrElem()
{
	return this->nrElem;
}


void Lista::addNodeAsTail(Lista *&e,Element * p)
{
	p->ant = nullptr;
	p->urm = nullptr;
	if (e->cap == nullptr)
	{
		e->cap = p;
		e->coada = e->cap;
		e->nrElem += 1;

	}
	else
	{
		e->coada->urm = p;
		p->ant = e->coada;
		e->coada = p;
		e->nrElem += 1;
	}
}

void Lista::addNodeAsHead(Lista *& e, Element * p)
{
	p->ant = nullptr;
	p->urm = nullptr;
	if (e->cap == nullptr)
	{
		e->cap = p;
		e->coada = e->cap;
		e->nrElem += 1;

	}
	else
	{
		e->cap->ant = p;
		p->urm = e->cap;
		e->cap = p;
		e->nrElem += 1;
	}
}

Element * Lista::cautareDupaPret(Lista * e, int pretDorit)
{while (e->cap)
	{
		
		if (e->cap->getAutoturism()->getPret() == pretDorit)
			return e->cap;
		else
			e->cap = e->next(e->cap);
	}
	if (e->cap = nullptr)
		return nullptr;
}



void Lista::afisare()
{
	Element *_cap = cap;
	if (_cap == nullptr)
		cout << "nu mai exista elemente li lista";
	else
	{
		while (_cap != nullptr)
		{
			_cap->produs->afisare();
			_cap = _cap->urm;
			cout << endl;
		}
	}
}

Element * Lista::next(Element *curent)
{
	if (curent->urm != nullptr)
		curent = curent->urm;
	return curent;
}

Element * Lista::prev(Element * curent)
{
	if (curent->ant != nullptr)
		curent = curent->ant;
	return curent;
}

void Lista::afisareF(const char *filename)
{
	Element *_coada = coada;
	if (_coada == nullptr)
		cout << "nu mai exista elemente li lista";
	else
	{
		while (_coada != nullptr)
		{
			_coada->produs->afisare(filename);
			_coada = _coada->ant;
			cout << endl;
		}
	}
}
