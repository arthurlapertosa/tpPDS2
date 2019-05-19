#ifndef LEITURAARQUIVOs_H
#define LEITURAARQUIVOs_H //Classe para a leitura dos arquivos
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include "indice_invertido.h"
#include "frequencia_palavra.h"

using namespace std;


class LeituraArquivos {
private:

	//numero total de documentos na colecao
	int numero_doc_;

	//O indice invertido do documento
	indice_invertido indice_;

	//Verifica se tem algum caracter especial e substitui
	string verifica(string a);

	//Coloca todos em minusculo
	string minusculo(string a);

	//A frequencia de cada palavra no documento
	frequencia_palavra frequencia_;

public:
	//Inicializa a classe
	LeituraArquivos();

	//Lê os arquivos e coloca eles no indice invertido
	void ler();

	//Imprime o indice invertido
	void imprimirIndice();

	//Imprime a frequencia das palavras
	void imprimirFrequenciaPalavras();
	
	//retorna o indice invertido
	indice_invertido indiceInvertido();

	//Retorna o numero total de elementos da coleção
	int numeroDocs();
};


#endif //LEITURAARQUIVOS_H