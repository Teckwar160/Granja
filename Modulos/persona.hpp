#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "terreno.hpp"


class Persona{
	public:
		string nombre;
		int dinero;
		Terreno *papeles;
		int longitud;
	//public:
		Persona(string);
		~Persona();
		bool Redimensionar();
};

#endif