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
#include "wmap.h"
#include "wvector.h"

using namespace std;


class LeituraArquivos {
private:

	//numero total de documentos na colecao
	int numero_doc_;

	//O indice invertido do documento
	indice_invertido indice_;

	//A frequencia de cada palavra no documento
	frequencia_palavra frequencia_;	

	//Vari�vel frequencia_palavra para ser utilizado ao chamar a fun��o TF(Que dependendo pode mudar o .size() do segundo map)
	frequencia_palavra frequencia_clone_;
	
	//A frequencia invertida de cada palavra no documento
	frequencia_invertida frequencia_invertida_;

	//O w propriamente dito
	wvector wvector_;

	//Vector com todas as palavras dos documentos
	vector<string> palavras_;

public:
	//Inicializa a classe
	LeituraArquivos();

	//L� os arquivos e coloca eles no indice invertido
	void ler();

	//Imprime o indice invertido
	void imprimirIndice();

	//Imprime a frequencia das palavras
	void imprimirFrequenciaPalavras();

	//Numero de vezes que a palavra apareceu no documento (tf(documento, palavra))
	int tf(string documento, string palavra); //testado

	//Imprime a frequencia invertida das palavras
	void imprimirFrequenciaInvertidaPalavras();

	//Retorna o idf(palavra)
	double idf(string palavra); //Testado
	
	//retorna o indice invertido
	indice_invertido indiceInvertido(); //Testado

	//Retorna o numero total de elementos da cole��o
	int numeroDocs(); //Testado

	//Retorna o numero de documentos que a palavra aparece
	int numero_Doc_Palavra(string palavra); //Testado

	//Refaz o processo de leitura de arquivos para incrementar no w
	void lerclone(vector<string> palavras);

	//Verifica se tem algum caracter especial e substitui
	string verifica(string a); //Testado

	//Coloca todos em minusculo
	string minusculo(string a); //Testado

	//Retorna a vari�vel palavras_
	vector<string> palavras_return(); //Testado

	//Imprime o W vector
	void imprimir_w();

	//retorna o w_vector
	wvector retornar_w_vector();
};


#endif //LEITURAARQUIVOS_H