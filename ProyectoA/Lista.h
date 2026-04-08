#pragma once
#include "nodo.h"
using namespace System;
template <typename T>
class Lista {
private:
	int tamaño;
	nodo<T>* cabeza;
public:
	Lista() : cabeza(nullptr), tamaño(0) {}

	int getTamaño() { return tamaño; }
	nodo<T>* getCabeza() { return this->cabeza; }


	
	void agregarValorInicio(T valor) {
		nodo<T>* nuevo = new nodo<T>(valor, cabeza);
		cabeza = nuevo;
		tamaño++;
	}


	T buscarInd(std::string codigo) {
		if (!cabeza) { return nullptr; }
		nodo<T>* actual = cabeza;
		bool encontrado = false;
		while (actual && !encontrado) {
			if (actual->getDato()->getCodigo() == codigo) {
				encontrado = true;
				return actual->getDato();
			}
			actual = actual->getSiguiente();
		}
		return nullptr;
	}


	void mostrarListaElectrodomestico() {
		system("color 6");
		if (!cabeza) {
			std::cout << "-------------------------------------" << std::endl;
			std::cout << "----NO HAY PRODUCTOS POR MOSTRAR-----" << std::endl;
			std::cout << "-------------------------------------" << std::endl;
	
			return;
		}
		nodo<T>* actual = cabeza;

		while (actual) {
			actual->getDato()->mostrarElectro();
			actual = actual->getSiguiente();
		}
		std::cout << std::endl;
	}

	void mostrarListaCliente() {
		system("color 6");
		if (!cabeza) {
			std::cout << "-------------------------------------" << std::endl;
			std::cout << "----NO HAY ELEMENTOS POR MOSTRAR-----" << std::endl;
			std::cout << "-------------------------------------" << std::endl;
		
			return; 
		}
		nodo<T>* actual = cabeza;

		while (actual) {
			actual->getDato()->mostrarDatosUsuario();
			actual = actual->getSiguiente();
		}
		std::cout << std::endl;
	}



	void modificarLista(T valorAntes, T valorNuevo) {
		if (!cabeza) { return; }
		nodo<T>* actual = cabeza;
		while (actual) {
			if (actual->getDato() == valorAntes) {
				actual->setDato(valorNuevo);
				return;
			}
			actual = actual->getSiguiente();
		}
	}


	
	void ordenarPorStock() {
		if (!tamaño) {
			return;
		}
		bool cambiado = true;

		for (nodo<T>* i = this->cabeza; i != nullptr; i = i->getSiguiente()) {
			for (nodo<T>* j = i->getSiguiente(); j != nullptr; j = j->getSiguiente()) {
				if (i->getDato()->getStock() > j->getDato()->getStock()) {
					T temporal = i->getDato();
					i->setDato(j->getDato());
					j->setDato(temporal);
					cambiado = false;
				}
			}
		}
	}

	//ordenamiento por insercion xd
	void ordenarPorPrecio() {
		if (!cabeza || !cabeza->getSiguiente()) return; // Lista vacía o un solo nodo

		nodo<T>* ordenada = nullptr; 
		nodo<T>* actual = cabeza;

		while (actual) {
			nodo<T>* siguiente = actual->getSiguiente();

			if (!ordenada || actual->getDato()->getPrecio() < ordenada->getDato()->getPrecio()) {
				actual->setSiguiente(ordenada);
				ordenada = actual;
			}
			else {
				nodo<T>* temp = ordenada;
				while (temp->getSiguiente() && temp->getSiguiente()->getDato()->getPrecio() < actual->getDato()->getPrecio()) {
					temp = temp->getSiguiente();
				}
				actual->setSiguiente(temp->getSiguiente());
				temp->setSiguiente(actual);
			}

			actual = siguiente;
		}

		cabeza = ordenada; 
	}

};



/*	void eliminarInicio() {
		if (!cabeza) { return; }
		nodo<T>* actual = cabeza;
		cabeza = cabeza->getSiguiente();
		delete actual;
		tamaño--;
		}


		void eliminarFinal() {
		if (!cabeza) { return; }
		nodo<T>* actual = cabeza;
		nodo<T>* previo = nullptr;

		while (actual->getSiguiente()) {
			previo = actual;
			actual = actual->getSiguiente();
		}if (actual == cabeza) {
			cabeza = nullptr;
		}
		else {
			previo->setSiguiente(nullptr);
		}
		delete actual;
		tamaño--;
	}

	void eliminarPos(T valor){
		if (!cabeza) { return; }

		nodo<T>* actual = cabeza;
		nodo<T>* previo = nullptr;

		while (actual) {
			if (actual->getDato() == valor) {
				if (actual == cabeza) {
					eliminarInicio();
				}
			}
			else if (actual->getSiguiente() == nullptr) {
				eliminarFinal();
			}
			else {
				previo->setSiguiente(actual->getSiguiente());
				delete actual;
				tamaño--;
				return;
			}

		}
		previo = actual;
		actual = actual->getSiguiente();

	}

	void buscarIndice() {
		if (!cabeza) {
			return; }
		nodo<T>* actual = cabeza;
		bool encontrado = false;
		int nodoEncontrado;
		int indice = 0;
		std::cout << "Introduce el valor a encontrar: "; std::cin >> nodoEncontrado;

		while (actual) {
			if (actual->getDato() == nodoEncontrado) {
				std::cout << "VALOR ENCONTRADO... " << std::endl;
				encontrado = true;
			}
			actual = actual->getSiguiente();
			indice++;
		}
		if (!encontrado) std::cout << "VALOR NO ENCONTRADO..." << std::endl;
	}
	}*/