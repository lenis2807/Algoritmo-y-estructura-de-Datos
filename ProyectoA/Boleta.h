#pragma once
#include <fstream>
#include "Cliente.h"
#include "Electrodomestico.h"
#include "Pila.h"
#include "Lista.h"

template <typename T>
class Boleta {
private:
	Cliente* cliente;
	Electrodomestico<T>* electro;
	double precio;
	int cantidad;
public:

	Boleta(Cliente* cliente, Electrodomestico<T>* electro, double precio) 
		: cliente(cliente), electro(electro), precio(precio) {}
	Boleta() {}

	Cliente* getCliente() { return cliente; }
	Electrodomestico<T>* getElectro() { return electro; }
	double getPrecio() { return precio; }
	void setCliente(Cliente* cliente) { this->cliente = cliente; }
	void setCantidad(int cantidad) { this->cantidad = cantidad; }
	void setElectro(Electrodomestico<T>* electro) { this->electro = electro; }
	void setPrecio(double precio) { this->precio = precio; }
	double cantidadTotal() {
		return electro ? electro->getPrecio() : 0.0;
	}

	void mostrarBoleta() {
		
		auto mostrar = [this]() {
			std::cout << "-------------------------------------" << std::endl;
			this->cliente->mostrarDatosUsuario();
			this->electro->mostrarElectro();
			std::cout << "TOTAL: " << this->cantidadTotal() << std::endl;
			std::cout << "-------------------------------------" << std::endl;
		};
		mostrar();

	}

	void guardarHistorial(const std::string &nombreArchivo) {
		auto guardar = [this](const std::string& Archivo) {
			std::ofstream miArchivo(Archivo, std::ios::app);

			if (miArchivo.is_open()) {

				cliente->mostrarDatosArchivo(miArchivo);
				electro->mostrarConArchivos(miArchivo);
				miArchivo << "TOTAL COMPRADO: " << cantidadTotal() << std::endl;
				miArchivo.close();
			}
			else {
				std::cout << "No se pudo guardar en el archivo...";
			}
		};
		guardar(nombreArchivo);
	}


	
	void guardarUltimaBoleta(const std::string& nombreArchivo) {
		auto guardar = [this](const std::string& Archivo) {

			std::ofstream archivo(Archivo, std::ios::out);
			if (archivo.is_open()) {

				this->cliente->mostrarDatosArchivo(archivo);

				this->electro->mostrarConArchivos(archivo);

				archivo << "TOTAL COMPRADO: " << cantidadTotal() << std::endl;
				archivo.close();
			}
			else {
				std::cout << "No se pudo guardar en el archivo...";
			}
		};
		
		guardar(nombreArchivo);
	}

};