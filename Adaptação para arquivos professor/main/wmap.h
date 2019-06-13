#ifndef WSET_H
#define WSET_H
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>

using std::map;
using std::string;

class wmap {
private:
	map<string, double> wmap_;

	//Norma do vetor
	double norma_vetor_;

	//Nome do documento
	string nome_doc_;
public:

	wmap();
	//Insere no map uma associação de palavras com o valor w dela
	void inserir_no_wmap(string palavra, double valor, string documento);

	//Exibe todos os valores do MAP
	void exibir();

	//Atribui ao operador [] em que o argumênto é a palavra, a função de retornar o w correspondente 
	double operator[](string palavra);

	map<string, double> w_map();

	double norma_vetor();

	string nome_doc();
};

#endif WSET_H
