#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "terreno.hpp"


class Persona{
	private:
		string nombre;
		Terreno *papeles;
		int longitud;
		int dinero;
		int contador;
	public:
		Persona(string);
		~Persona();
		bool Comprar(int,Terreno*);
		bool Redimensionar();
		void Mostrar();
};

#endif