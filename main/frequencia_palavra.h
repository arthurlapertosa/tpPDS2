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
	map<string, map<string, int>> frequencia_palavra_;

public:
	//Inicializa um dicionario de palavra vazio
	frequencia_palavra();

	//Insere novas palavras
	void inserir(string palavra, string documento);

	//Imprime
	void imprimir();

	//Retorna a variavel frquencia_palavra_
	map<string, map<string, int>> frequenciaPalavra();

	//Retorna o map com os documentos que a palavra "palavra" aparece
	map<string, int> frequenciaPalavra(string palavra);

	//Numero de vezes que a palavra apareceu no documento
	int frequenciaPalavraNoDocumento(string documento, string palavra);

	~frequencia_palavra();
};

#endif //FREQUENCIA_PALAVRA