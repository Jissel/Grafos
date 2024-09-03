#ifndef NODO_H_
#define NODO_H_

#include <iostream>

template <class T>
class Nodo
{
protected:
	T info;
	Nodo<T> *prox;
public:
	Nodo(T e, Nodo<T> *p);
	Nodo(Nodo<T> *p);
	~Nodo();
	
	void setInfo(T e);
	void setProx(Nodo<T> *p);
	T getInfo();
	Nodo<T> *getProx();
};

template <class T>
Nodo<T>::Nodo(T e, Nodo<T> *p)
{
	info = e;
	prox = p;
}

template <class T>
Nodo<T>::Nodo(Nodo<T> *p)
{
	prox = p;
}

template <class T>
Nodo<T>::~Nodo()
{
}

template <class T>
void Nodo<T>::setInfo(T e)
{
	info = e;
}

template <class T>
void Nodo<T>::setProx(Nodo<T> *p)
{
	prox = p;
}

template <class T>
T Nodo<T>::getInfo()
{
	return info;
}

template <class T>
Nodo<T> *Nodo<T>::getProx()
{
	return prox;
}
#endif /*NODO_H_*/
