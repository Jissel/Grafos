#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"


template <class T>
class Lista
{
protected:
	Nodo<T> *l;
	
public:
	Lista();
	~Lista();
	bool esvacia();
	void insertar(int pos, T e);
	void eliminar(int pos);
	T consultar(int pos);
	int localizar(T e);
	int longitud();
	void vaciar();
};

template <class T>
Lista<T>::Lista()
{
	l = new Nodo<T>(NULL);
}

template <class T>
Lista<T>::~Lista()
{
	Nodo<T> *aux;

	while(l != NULL)
	{
		aux = l;
		l = l->getProx();
		delete aux;
	}
}

template <class T>
bool Lista<T>::esvacia()
{
	return l->getProx() == NULL;
}

template <class T>
void Lista<T>::insertar(int pos, T e)
{
	int i;
	Nodo<T> *aux, *act;
	
	aux = new Nodo<T>(e, NULL);
	
	act = l;
	i = 1;
	while(i < pos)
	{
		act = act->getProx();
		i++;
	}
	
	aux->setProx(act->getProx());
	act->setProx(aux);
}

template <class T>
void Lista<T>::eliminar(int pos)
{
	int i;
	Nodo<T> *aux, *act;
	
	act = l;
	i = 1;
	while(i < pos)
	{
		act = act->getProx();
		i++;
	}
	
	aux = act->getProx();
	act->setProx(aux->getProx());
	
	delete aux;
}

template <class T>
T Lista<T>::consultar(int pos)
{
	int i;
	Nodo<T> *act;
	
	act = l;
	i = 1;
	while(i <= pos)
	{
		act = act->getProx();
		i++;
	}
	
	return act->getInfo();
}

template <class T>
int Lista<T>::localizar(T e)
{
	int i;
	Nodo<T> *act;
	
	act = l->getProx();
	i = 1;
	while(act != NULL && act->getInfo() != e)
	{
		act = act->getProx();
		i++;
	}
	
	if(act == NULL)
		return 0;
	else
		return i;
}

template <class T>
int Lista<T>::longitud()
{
	int i;
	Nodo<T> *act;
	
	act = l->getProx();
	i = 0;
	while(act != NULL)
	{
		act = act->getProx();
		i++;
	}
	
	return i;
}

template <class T>
void Lista<T>::vaciar()
{
	Nodo<T> *aux, *act;
	
	act = l->getProx();
	while(act != NULL)
	{
		aux = act;
		act = act->getProx();
		delete aux;
	}
	l->setProx(NULL);
}

#endif /*LISTA_H_*/
