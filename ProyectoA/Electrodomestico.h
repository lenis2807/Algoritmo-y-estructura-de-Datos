#pragma once
#include <iostream>
#include "Lista.h"

template <typename T>

class Electrodomestico
{
private:
	T codigo;
	std::string tipoElectro;
	double precio;
	int stock;


public:
	Electrodomestico(T codigo = T(), std::string tipoElectro = "", double precio = 0.0, int stock = 0) 
		: codigo(codigo), tipoElectro(tipoElectro), precio(precio), stock(stock) {}

	Electrodomestico()  {}
	
	
	std::string getTipoElectro() { return tipoElectro; }
	int getStock() { return stock; }
	double getPrecio() { return precio; }
	T getCodigo() { return this->codigo; }


	void setStock(int stock) { this->stock = stock; }


	void registrarElectro() {
		std::cout << "----------------------------" << std::endl;
		std::cout << "CODIGO DEL PRODUCTO: "; std::cin >> codigo; std::cout << std::endl;
		seleccionarTipoElectro();
		do {
			std::cout << "PRECIO DEL PRODUCTO: "; std::cin >> precio; std::cout << "\n";
			if (precio < 0) std::cout << "PRECIO NO PUEDE SER NEGATIVO.\n";
		} while (precio < 0);
		do {
			std::cout << "STOCK DEL PRODUCTO: "; std::cin >> stock; std::cout << "\n";
			if (stock < 0) std::cout << "STOCK NO PUEDE SER NEGATIVO.\n";
		} while (stock < 0);
		
		std::cout << "----------------------------" << std::endl;
	}

	void mostrarElectro() {
		std::cout << "----------------------------" << std::endl;
		std::cout << "CODIGO DEL PRODUCTO : " << codigo << std::endl;
		std::cout << "TIPO ELECTRO: " << tipoElectro << std::endl;
		std::cout << "PRECIO DEL PRODCUTO: " << precio << std::endl;
		std::cout << "STOCK DEL PRODUCTO : " << stock << std::endl;
		std::cout << "----------------------------" << std::endl;
	}
	

	void mostrarConArchivos(std::ofstream& archivo) {
		archivo << std::endl
			<< "CODIGO: " << codigo << std::endl
			<< "TIPO: " << tipoElectro << std::endl
			<< "PRECIO: " << precio << std::endl;
 	}

	
	void seleccionarTipoElectro() {

		auto seleccion = [this] {
			int opc = 0;

			do {
				std::cout << "...................................." << std::endl;
				std::cout << "1. Refrigeradora..." << std::endl;
				std::cout << "2. Lavadora...." << std::endl;
				std::cout << "3. Cafetera..." << std::endl;
				std::cout << "4. Hervidora..." << std::endl;
				std::cout << "Ingrese opcion de electro: "; std::cin >> opc;

				switch (opc){
				case 1: this->tipoElectro = "Refrigeradora"; break;
				case 2: this->tipoElectro = "Lavadora"; break;
				case 3: this->tipoElectro = "Cafetera"; break;
				case 4: this->tipoElectro = "Hervidora"; break;
				default: 
					std::cout << " No se encontro su opción " << std::endl; opc = 0; break;
				}
			} while(opc < 1 || opc > 4);
		};
	
		
		
		seleccion();
	}

};
