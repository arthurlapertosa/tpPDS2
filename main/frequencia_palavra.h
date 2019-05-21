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

	//Frequencia total da palavra N na coleção
	map<string, int> frequencia_total_palavra_;

public:
	//Inicializa um dicionario de palavra vazio
	frequencia_palavra();

	//Insere novas palavras
	void inserir(string palavra, string documento);

	//Monta a variavel frequencia total da palavra N na coleção
	void frequencia_total(string palavra);

	//Imprime
	void imprimir();

	~frequencia_palavra();
};

#endif //FREQUENCIA_PALAVRA