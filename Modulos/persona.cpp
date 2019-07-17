#include "persona.hpp"


Persona::Persona(string _nombre){
	nombre = _nombre;

	longitud = 1;

	papeles = new Terreno*[longitud];

	for(int i=0; i<longitud; i++){
		papeles[i] = new Terreno;
	}
	

}

Persona::~Persona(){
	for(int i=0; i<longitud; i++){
		delete papeles[i];
	}

	delete[] papeles;

	cout << "Murio la persona" << endl;
}

bool Persona::Redimensionar(){
    longitud++;

    Terreno **aux = new Terreno*[longitud];

    for(int i=0; i<longitud; i++){
    	aux[i] = new Terreno;
    }

    for(int i = 0; i < longitud - 1; i++)
    {
        aux[i] = papeles[i];
    }

    delete[] papeles;

    papeles = aux;
}
