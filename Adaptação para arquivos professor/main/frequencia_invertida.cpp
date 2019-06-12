#include "frequencia_invertida.h"

frequencia_invertida::frequencia_invertida()
{
}

void frequencia_invertida::inserir(map<string, map<string, int>> frequencia_palavra_, int num_docs_total)
{
for (auto i = frequencia_palavra_.begin(); i != frequencia_palavra_.end(); i++) {//percorre o map frequencia palavra e adiciona os 
	string palavra = i->first;
	double frequencia_int;
	double num_docs = num_docs_total;
	double quantidade_docs_palavra_aparece = frequencia_palavra_[palavra].size();
	frequencia_int = log10((num_docs / quantidade_docs_palavra_aparece));// calcula a frequencia invertida de cada palavra
	frequencia_invertida_palavra_.insert(std::pair<string, double>(palavra, frequencia_int));//Adiciona o elemento ao mapa frequencia_invertida_palavra_
	}
}


void frequencia_invertida::imprimi_Invertida()
{
	cout << endl;
	for (auto i = frequencia_invertida_palavra_.begin(); i != frequencia_invertida_palavra_.end(); i++) {//for que percorre todo o map frequencia_invertida_palavra_
		cout << i->first << " => " << i->second << "   ";//escreve na tela a frequencia invertida da posição atual
		cout << endl;
	}

}

double frequencia_invertida::frequencia_invertida_palavra(string palavra)
{
	return frequencia_invertida_palavra_[palavra];// Retornando a frquencia invertida da palavra em especifico
}

frequencia_invertida::~frequencia_invertida()
{
}
