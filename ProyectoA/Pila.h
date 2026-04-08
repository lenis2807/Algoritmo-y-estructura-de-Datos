#pragma once
#include <iostream>
#include "nodo.h"

template <typename T>
class Pila {
private:
	nodo<T>* tope;

public:

	Pila() : tope(nullptr) {}

	nodo<T>* getTope() { return tope; }

	bool esVacio() { return tope == nullptr; }

	void push(T valor) {
		nodo<T>* nuevo = new nodo<T> (valor, tope);
		tope = nuevo;
	}

	void pop() {
		if (tope) {
			nodo<T>* temporal = tope;
			tope = tope->getSiguiente();
			delete temporal;
		}
	}

	void top() {
		if (!tope) {
			std::cout << "VACIO..." << std::endl;
			std::cout << "Presionar cualquier letra para continuar..."; 
			std::cin.ignore(); 
			std::cin.get();
			return;
		}
		else {
			tope->getDato()->mostrarBoleta();
		}
	}

};