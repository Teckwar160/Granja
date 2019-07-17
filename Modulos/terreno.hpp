#ifndef TERRENO_HPP
#define TERRENO_HPP

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
		Terreno();
		virtual ~Terreno();
		void Imprimir();
		bool Guardar();
		bool Leer();
		bool Construir(int,int,char);
};

#endif