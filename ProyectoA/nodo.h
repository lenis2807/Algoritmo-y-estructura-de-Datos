#pragma once
#include <iostream>

template <typename T>
class nodo {
private:
	T dato;
	nodo<T>* siguiente;
public:
	nodo(T dato, nodo* siguiente) : dato(dato), siguiente(siguiente) {}

	T getDato() { return dato; }
	void setDato(T dato) { this->dato = dato; }

	nodo<T>* getSiguiente() const { return siguiente; }
	void setSiguiente(nodo<T>* siguiente) { this->siguiente = siguiente; }

};