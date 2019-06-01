#ifndef WVECTOR_H
#define WVECTOR_H
#include <vector>
#include <iostream>
#include <string>
#include "wmap.h"

using std::vector;
using std::string;

class wvector{
private:
	vector<wmap> w_;
public:
	//Insere um map de w no vetor, cada elemento é a palavra seguido de tf * idf
	void inserir_vetor(wmap documento);

	//Exibe todo o vetor w
	void exibir();

	//Retorna um vetor sem palavras repitidas
	vector<string> vetorNaoRep(vector<string> palavra, string documento);

	//Verifica se a string existe dentro de um vetor
	bool existe(vector<string> x, string palavra);
};

#endif WVECTOR_H