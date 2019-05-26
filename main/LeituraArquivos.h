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
#include "frequencia_invertida.h"

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
	
	//A frequencia invertida de cada palavra no documento
	frequencia_invertida frequencia_invertida_;

public:
	//Inicializa a classe
	LeituraArquivos();

	//L� os arquivos e coloca eles no indice invertido
	void ler();

	//Imprime o indice invertido
	void imprimirIndice();

	//Imprime a frequencia das palavras
	void imprimirFrequenciaPalavras();

	//Imprime a frequencia invertida das palavras
	void imprimirFrequenciaInvertidaPalavras();
	
	//retorna o indice invertido
	indice_invertido indiceInvertido();

	//Retorna o numero total de elementos da cole��o
	int numeroDocs();

	//Retorna o numero de documentos que a palavra aparece
	int numero_Doc_Palavra(string palavra);
};


#endif //LEITURAARQUIVOS_H