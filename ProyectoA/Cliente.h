#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "Lista.h"

class Cliente {
private:
	
	std::string nombre;
	std::string apellido;
	int edad;
	std::string dni;
	

public:
	Cliente(std::string nombre = "", std::string apellido = "", int edad = 0, std::string dni = "") : nombre(nombre),
		apellido(apellido), edad(edad), dni(dni) {}



	std::string getCodigo() { return dni;}
	int getEdad() { return edad; }
	std::string getDni() { return dni; }
	std::string getNombre() { return nombre; }
	std::string getApellido() { return apellido; }


	
	bool soloLetras(std::string & palabra) {
		for (char i : palabra ) {
			if (!isalpha(i) && i != ' ') {
				return false;
			}
		}
		return true;
	}

	bool validarDni(std::string & dni) {
		
		if (dni.size() != 8) {
			return false;
		}
		for (char c : dni) {
			if (!isdigit(c)) return false;
		}
		return true;
	}


	void registrarClienteSinParametros() {
		std::cout << "-------------------------------------" << std::endl;
		std::cin.ignore();

		do {
			std::cout << "INGRESE SU NOMBRE: "; std::getline(std::cin, nombre);
			if (!soloLetras(nombre)) {
				std::cout << "INTRODUZCA CORRECTAMENTE SU NOMBRE" << std::endl;
			}
		} while (!soloLetras(nombre));

		do {
			std::cout << "INGRESE SU APELLIDO: "; std::getline(std::cin, apellido);
			if (!soloLetras(apellido)) {
				std::cout << "INTRODUZCA CORRECTAMENTE SU NOMBRE" << std::endl;
			}
		} while (!soloLetras(apellido));

		do {
			std::cout << "INGRESE SU EDAD: "; std::cin >> edad;
			std::cin.ignore();
			if (edad < 0 || edad > 100) {
				std::cout << "INTRODUZCA SU EDAD MAYOR QUE 1" << std::endl;
			}
		} while (edad <= 0 || edad >= 100);

		do {
			std::cout << "INGRESE SU DNI: "; std::cin >> dni;
			std::cin.ignore();
			if (!validarDni(dni)) {
				std::cout << "REGISTRE CORRECTAMENTE SU DNI" << std::endl;
			}

		} while (!validarDni(dni));

		std::cout << "-------------------------------------" << std::endl;
	}

	void mostrarDatosUsuario() {
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Nombre del usuario: " << nombre << std::endl;
		std::cout << "Apellido del usuario: " << apellido << std::endl;
		std::cout << "Edad del usuario: " << edad << std::endl;
		std::cout << "DNI del usuario: " << dni << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
	}

	void mostrarDatosArchivo(std::ofstream& archivo) {
		archivo << "NOMBRE: " << nombre << " " << "APELLIDO: " << apellido << std::endl
			<< "EDAD: " << edad << " " << "DNI: " << dni;
	}



	

};

