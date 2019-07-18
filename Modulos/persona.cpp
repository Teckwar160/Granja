#include "persona.hpp"


Persona::Persona(string _nombre){

	/*Se asigna el nombre a la persona*/
	nombre = _nombre;

	/*Se asigna uuna longitud inicial para el arreglo de Terrenos*/
	longitud = 1;

	/*Dinero inicial del jugador*/
	dinero = 100;

	/*Contador que indica en que casilla se debe guardar un Terreno Comprado*/
	contador = 0;

	/*Arreglo de Terrenos de la paersona*/
	papeles = new Terreno[longitud];

}

Persona::~Persona(){

	/*Se libera la memoria solicitada para el arreglo de Terrenos*/
	delete[] papeles;

	cout << "Murio la persona" << endl;
}

bool Persona::Comprar(int precio,Terreno *papel){

	/*Bandera que indica di todo salio bien*/
	bool done = false;

	/*Condicion de compra*/
	if(dinero >= precio){
		dinero -= precio;
		papeles[contador] = *papel;
		contador++;
		
	}


	return done;
}

bool Persona::Redimensionar(){

}

void Persona::Mostrar(){
	
	/*Mostrar todos los datos de una persona*/
	cout << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Dinero: " << dinero << endl << endl;

	for(int i=0; i<contador; i++){
		cout <<"Nombre del Terreno: " << papeles[i].Get_Nombre() << endl;
		cout <<"Precio del Terreno: " << papeles[i].Get_Precio() << endl;
		papeles[i].Imprimir();
	}

}

