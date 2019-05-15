#ifndef INDICE_INVERTIDO_H
#define INDICE_INVERTIDO_H
#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class indice_invertido {
private:
	//Cria o mapa de string para um set de string que contém os documentos (Indice invertido) 
	map<string, set<string>> my_map_;

public:
	//Inicializa um indice invertido vazio
	indice_invertido();

	//Insere o elemento no mapa
	void inserir(string a, string documento);

	//Imprime o indice invertido
	void imprimirIndice();
};












#endif //INDICE_INVERTIDO_H