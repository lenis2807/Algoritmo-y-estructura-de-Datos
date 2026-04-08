#pragma once
#include "Lista.h"
#include "Cliente.h"
#include "Electrodomestico.h"
#include "Boleta.h"


template<typename T>
class Tienda {
private:
	Lista<Electrodomestico<T>*> producto;
	Lista<Cliente*> cliente;
	Pila<Boleta<T>*> boleta;

	double total;
	int cantidad;

public:
	Tienda() : total(0), cantidad(0) {}

	double getTotal() { return total; }

	void registrarElectro() {

		Electrodomestico<T>* nuevo = new Electrodomestico<T>();
		nuevo->registrarElectro();
		producto.agregarValorInicio(nuevo);
		std::cout << "ELECTRODOMESTICO REGISTRADO \n";
	}


	void registrarCliente() {
		Cliente* nuevo = new Cliente();
		nuevo->registrarClienteSinParametros();
		cliente.agregarValorInicio(nuevo);
		std::cout << "CLIENTE REGISTRADO \n";
	}

	//lo agregue a la funcion venderProducto
	void registrarBoleta(Cliente* cliente, Electrodomestico<T>* producto) {
		Boleta<T>* nuevo = new Boleta<T>(cliente, producto, producto->getPrecio());
		boleta.push(nuevo);
		nuevo->guardarHistorial("H.txt");
		nuevo->guardarUltimaBoleta("U.txt");
		std::cout << std::endl;
		std::cout << "BOLETA EMITIDA...";
	}


	void ordenarPorStock() {
		producto.ordenarPorStock();
		producto.mostrarListaElectrodomestico();
	}

	void ordenarPorPrecio() {
		producto.ordenarPorPrecio();
		producto.mostrarListaElectrodomestico();
	}


	void mostrarProductos() {
		producto.mostrarListaElectrodomestico();
	}

	void mostrarCliente() {
		cliente.mostrarListaCliente();
	}

	void compraProducto() {


		if (producto.getTamaño() == 0) {
			std::cout << "NO HAY PRODUCTOS REGISTRADOS..";
			return;
		}
		std::string codigo;
		std::cout << "INTRODUCE CODIGO DEL PRODUCTO: "; std::cin >> codigo;
		Electrodomestico<T>* electrodo = producto.buscarInd(codigo);
		if (!electrodo) {
			std::cout << "NO HAY PRODUCTO MENCIONADO..." << std::endl;
			return;
		}
		if (cliente.getTamaño() == 0) {
			std::cout << "PARA COMPRAR DEBE REGISTRASE..." << std::endl;
			return;
		}

		std::string dni;
		do {
			std::cout << "INTRODUZCA SU DNI:  "; std::cin >> dni;
			if (dni.length() < 8) { std::cout << "INTRODUCIR CORRECTAMENTE, GRACIAS.."; }
		} while (dni.length() < 8);

		Cliente* c = cliente.buscarInd(dni);
		if (c == nullptr) {
			std::cout << "NO SE ENCONTRO EL DNI...";
			return;
		}

		Boleta<T>* bol = new Boleta<T>();
		bol->setCliente(c);
		bol->setElectro(electrodo);

		int cantidad = 0;
		do {
			std::cout << "INTRODUCE LA CANTIDAD A COMPRAR: ";
			std::cin >> cantidad;
			if (cantidad < 0) {
				std::cout << std::endl;
				std::cout << "NO PUEDE COMPRAR VALORES NEGATIVOS.";
			}
		} while (cantidad < 0);

		bol->setCantidad(cantidad);

		double total = electrodo->getPrecio() * cantidad;
		int nuevoStock = electrodo->getStock() - cantidad;

		bol->setPrecio(total);
		electrodo->setStock(nuevoStock);

		registrarBoleta(c,electrodo);
		std::cout << "COMPRA REALIZADA CON EXITO. " << std::endl;
		std::cout << "VUELVA PRONTO. GRACIAS" << std::endl;
		boleta.top();
	}



};



