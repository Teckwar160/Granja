#ifndef TERRENO_HPP
#define TERRENO_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

class Terreno{
	private:
		char **matriz;
		int precio;
		int filas;
		int columnas;
		string nombre;
		string direccion;
	public: 
		Terreno(string,int,int,int);
		Terreno();
		virtual ~Terreno();
		void Imprimir();
		bool Guardar();
		bool Leer();
		bool Construir(int,int,char);
		string Get_Nombre();
		int Get_Precio();

};

#endif