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
	//O WMap
	map<string, double> wmap_;

	//Armazena a norma ao quadrado do vetor
	double norma_vetor_;
public:

	wmap();
	//Insere no map uma associa��o de palavras com o valor w dela
	void inserir_no_wmap(string palavra, double valor);

	//Exibe todos os valores do MAP
	void exibir();

	//Atribui ao operador [] em que o argum�nto � a palavra, a fun��o de retornar o w correspondente 
	double operator[](string palavra);

	//Retorna o W map do documentos
	map<string, double> w_map();

	//Retorna a norma ao quadrado do vetor
	double norma_vetor();
};

#endif WSET_H
