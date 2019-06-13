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
} 
