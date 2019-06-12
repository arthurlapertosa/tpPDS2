#include <iostream>
#include "Busca.h"

int main(){
	bool loop = 1;
	while(loop){
		Busca primeiro;
		primeiro.pesquisa_usuario_digita();
		cout << endl << "Para continuar digite 1. Para sair, digite 0" << endl;
		cin >> loop;
		system("cls");
	}
	//cout << "digite sua busca: " << endl;
	//Busca o("Vejam so para onde os homens casa");
	//o.imprimir_resultado_pesquisa();
} 
