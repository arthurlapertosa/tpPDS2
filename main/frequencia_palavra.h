#ifndef FREQUENCIA_PALAVRA
#define FREQUENCIA_PALAVRA
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::endl;

class frequencia_palavra
{
private:
	//Relaciona as palavras com seus respectivos documentos e a quantidade de vezes que repetiu naquele documento
	map<string, map<string, int>> a;

public:
	//Inicializa um dicionario de palavra vazio
	frequencia_palavra();

	//Insere novas palavras
	void inserir(string palavra, string documento);

	//Imprime
	void imprimir();

	~frequencia_palavra();
};

#endif //FREQUENCIA_PALAVRA