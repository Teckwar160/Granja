#include "terreno.hpp"

Terreno::Terreno() :nombre("NAN"), filas(0), columnas(0), precio(0), direccion("NAN"){
	/*Constructor para arreglos*/
}

Terreno::Terreno(string _nombre,int _filas, int _columnas, int _precio){

	/*Asigna un valor al terreno*/
	precio = _precio;

	/*Asignamos los valor a filas y columnas*/
	filas = _filas +1;
	columnas = _columnas +1;

	/*Nombre*/
	nombre =_nombre;

	/**!<Direccion de guardado*/
	direccion = "Terrenos/"+nombre+"txt";

	/*Creamos la matriz dinamica*/
	matriz = new char*[filas];

	/*Asignamos columnas a cada fila*/
	for(int i=0; i<filas; i++){
		matriz[i] = new char[columnas];
	}

	/*Creamos el terreno*/

	for(int i=0; i<filas; i++){
		for(int j=0; j <columnas; j++){
			#if 0
			if(i == 0 || i == filas -1 || j == 0 || j== columnas -1){
				*(*(matriz+i)+j) = 'X';
			}else{
				*(*(matriz+i)+j) = 'O';
			}
			#endif


			if((i == 1 && j > 0 && j <columnas-1) || (i == filas - 2 && j > 0 && j <columnas -1) || (j== 1 && i>0 && i < filas -1) || (j == columnas -2 && i > 0 && i <filas -1)){
				/*Parte que limita la zona accesible al jugador*/
				*(*(matriz+i)+j) = '|';

			}else if(i == 0 && j < columnas -1){
				/*Da los numeros de las columas*/
				*(*(matriz+i)+j) = j+48;

			}else if(j == 0 && i < filas -1){
				/*Da el numero de las filas*/
				*(*(matriz+i)+j) = i+48;

			}else if(i == filas -1){
				/*Elimina la parte sobrante de columas*/
				*(*(matriz+i)+j) = 32;

			}else if(j == columnas -1){
				/*Elimina la parte sobrante de filas*/
				*(*(matriz+i)+j) = 32;
			}else{
				/*Parte accesible para el jugador*/
				*(*(matriz+i)+j) = 'O';
			}
		}
	}
}

Terreno::~Terreno(){

	/*Liberamos la memoria del arreglo en el arreglo*/
	for(int i=0; i<filas; i++){
		delete[] matriz[i];
	}

	/*Se libera la memoria del arreglo*/
	delete[] matriz;	

	cout << "Murio" << endl;	
}

void Terreno::Imprimir(){

	/*Impresión del terreno*/
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){

			/*Impresion de datos del Terreno*/
			cout << *(*(matriz+i)+j);
		}
		cout << endl;
	}
}

bool Terreno::Guardar(){
	/**!<Variable que abre el fichero*/
	ofstream archivo;

	/**!<Varible que dice el estatus del fichero*/
	bool done;

	/*Abre el fichero*/
	archivo.open(direccion,ios::out);

	/*Si falla retorna false sino continua*/
	if(archivo.fail()){
		done = false;
	}else{
		/*Guarda la matriz caracter por caracter*/
		for(int i=0; i<filas; i++){
			for(int j=0; j<columnas; j++){
				archivo << *(*(matriz+i)+j);
			}
			archivo << endl;
		}
		done = true;	
	}

	/*Se cierra el fichero*/
	archivo.close();

	/*Se retorna el valor del indicador*/
	return done;
}

bool Terreno::Leer(){

	/**!<Variable que abre el fichero*/
	ifstream archivo;

	/**!<Variable que indica el estatus del dichero*/
	bool done;

	/*Se abre el archivo*/
	archivo.open(direccion);

	/*Se verifica la disponibilidad*/
	if(archivo.fail()){

		/*Se cambia el estatus del indicador*/
		done = false;

	}else{

		/*Se lee y actualiza los datos del terreno*/
		for(int i=0; i<filas; i++){
			for(int j=0; j<columnas; j++){

				/*Se cambian los datos del terreno*/
				archivo >> *(*(matriz+i)+j);
			}
		}

		/*Se cambia el estatus del indicador*/
		done = true;		
	}


	/*cierra el fichero*/
	archivo.close();

	/*Retorna el valor del indicador*/
	return done;

}

bool Terreno::Construir(int x,int y,char elemento){

	/*Bandera que indica si se puede construir*/
	bool done;

	/*Ve si se puede construir en esa coordenada*/
	if(matriz[y][x] != 'O'){

		/*Sino se puede cambia el valor de la bandera*/
		done = false;
	}else{

		/*si se puede construlle en la coordenada dada*/
		matriz[y][x] = elemento;

		/*Cambia el valor de la bandera*/
		done = true;
	}

	/*Retorna el valor de la bandera*/
	return done;
}

string Terreno::Get_Nombre(){
	return nombre;
}

int Terreno::Get_Precio(){
	return precio;
}