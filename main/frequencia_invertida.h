#ifndef FREQUENCIA_INVERTIDA
#define FREQUENCIA_INVERTIDA
#include <map>
#include <string>
#include <cmath>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::endl;

class frequencia_invertida
{
private:

	//Frequencia invertida da palavra N na coleção
	map<string, double> frequencia_invertida_palavra_;

public:
	//Inicializa um dicionario de palavra vazio
	frequencia_invertida();

	//Insere novas palavras na frequencia invertida
	void inserir(map<string, map<string, int>> frequencia_palavra_, int num_docs_total);


	//Imprime a frequencia invertida
	void imprimi_Invertida();

	//Retorna a frequencia invertida  da palavra
	double frequencia_invertida_palavra(string palavra);

	~frequencia_invertida();
};

#endif //FREQUENCIA_INVERTIDA
