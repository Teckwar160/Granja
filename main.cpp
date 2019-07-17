#include "Modulos/terreno.hpp"

using namespace std;

ofstream e;
ifstream l;


int main(){

	Terreno p = Terreno("campo",10,10,10.50);

	p.Imprimir();

	p.Construir(8,2,'C');

	p.Imprimir();

	



	return 0;
}