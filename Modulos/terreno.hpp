#ifndef TERRENO_hpp
#define TERRENO_hpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class Terreno{
	private:
		char **matriz;
		float precio;
		int filas;
		int columnas;
		string nombre;
		string direccion;
	public: 
		Terreno(string,int,int,float);
		~Terreno();
		void Imprimir();
		bool Guardar();
		bool Leer();
		bool Construir(int,int,char);
};

#endif