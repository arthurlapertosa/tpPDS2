#ifndef WVECTOR_H
#define WVECTOR_H
#include <vector>
#include <iostream>
#include <string>
#include "wmap.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

class wvector{
private:
	vector<wmap> w_;
public:
	//Insere um map de w no vetor, cada elemento é a palavra seguido de tf * idf
	void inserir_vetor(wmap documento);

	//Exibe todo o vetor w
	void exibir();

	//Retorna um vetor sem palavras repitidas
	vector<string> vetorNaoRep(vector<string> palavra);

	//Verifica se a string existe dentro de um vetor
	bool existe(vector<string> x, string palavra);

	//Operator que retorna o wmap do documento
	wmap operator[](int documento);

	//retorna o w_
	vector<wmap> w_vector();
};

#endif WVECTOR_H