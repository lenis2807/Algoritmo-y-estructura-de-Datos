#include <iostream>
#include <locale>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "Tienda.h"

using namespace System;


void mostrarIntro() {
	system("color e");
	Console::SetCursorPosition(10, 5);
	std::cout << R"(
  _____ _     _____ ____ _____ ____   ___ _____ ___ _____ _   _ ____    _    
 | ____| |   | ____/ ___|_   _|  _ \ / _ \_   _|_ _| ____| \ | |  _ \  / \   
 |  _| | |   |  _|| |     | | | |_) | | | || |  | ||  _| |  \| | | | |/ _ \  
 | |___| |___| |__| |___  | | |  _ <| |_| || |  | || |___| |\  | |_| / ___ \ 
 |_____|_____|_____\____| |_| |_| \_\\___/ |_| |___|_____|_| \_|____/_/   \_\)";
	std::this_thread::sleep_for(std::chrono::seconds(5));

}


void mostrarMenu(Tienda<std::string>* valor) {
	system("color 3");
	Console::SetCursorPosition(10, 10);
	int opc = 0;

	do {
		std::cout << std::endl;
		std::cout << "---------BIENVENIDO-----------" << std::endl;
		std::cout << "ELIJA SU OPCION" << std::endl;
		std::cout << "1. REGISTRAR CLIENTE " << std::endl;  //nuevos clientes ingresan sus datos
		std::cout << "2. REGISTRAR PRODUCTO " << std::endl; //registrar producto para ver si hay stock
		std::cout << "3. MOSTRAR CLIENTES REGISTRADOS" << std::endl;
		std::cout << "4. MOSTRAR PRODUCTOS REGISTRADOS" << std::endl;
		std::cout << "5. COMPRAR PRODUCTO " << std::endl; // se ingresa datos del producto y se devuelve una boleta
		std::cout << "6. ORDENAR PRODUCTOS POR STOCK" << std::endl;
		std::cout << "7. ORDENAR PRODUCTOS POR PRECIO " << std::endl;
		std::cout << "8. SALIR " << std::endl;
		std::cout << "Ingrese su opcion: "; std::cin >> opc;
		
		Console::Clear();
		system("color");

		switch (opc)
		{
		case 1: valor->registrarCliente(); break;  //listo

		case 2: valor->registrarElectro(); break;  //listo

		case 3: valor->mostrarCliente();
			std::cout << "Presionar cualquier letra para continuar ";
			std::cin.ignore();
			std::cin.get();
			break;

		case 4: valor->mostrarProductos();
			std::cout << "Presionar cualquier letra para continuar ";
			std::cin.ignore();
			std::cin.get(); 
			break;  //listo

		case 5: valor->compraProducto(); break; 

		case 6: valor->ordenarPorStock(); break;  //listo

		case 7: valor->ordenarPorPrecio(); break;

		case 8: std::cout << "GRACIAS POR USARNOS XD "; break;

		default: std::cout << "No se encontro su opcion"; break;
		}

	} while (opc != 8);

}

int main() {
	setlocale(LC_ALL, "spanish");
	Tienda<std::string>* miTienda = new Tienda<std::string>();

	mostrarIntro();
	mostrarMenu(miTienda);
	delete miTienda;
	system("color");

	return 0;
}


//hay partes o pasajes del codigo que le pase a chatpgt porque aveces
//se me iban las comas o algunas cosas no las escribia bien
//