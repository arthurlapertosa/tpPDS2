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
	//Insere valor numerico no final do vetor
	void inserir_vetor(wmap documento);

	void exibir();
};

#endif WVECTOR_H