#include "persona.hpp"


Persona::Persona(string _nombre){
	nombre = _nombre;

	longitud = 1;

	papeles = new Terreno[longitud];

	

}

Persona::~Persona(){
	delete[] papeles;
}

bool Persona::Redimensionar(){
    longitud++;

    Terreno *aux = new Terreno[longitud];

    for(int i = 0; i < longitud - 1; i++)
    {
        aux[i] = papeles[i];
    }

    delete[] papeles;

    papeles = aux;
}