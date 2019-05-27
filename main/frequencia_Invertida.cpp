#include "frequencia_invertida.h"

frequencia_invertida::frequencia_invertida()
{
}

void frequencia_invertida::inserir_frequencia_invertida(map<string, map<string, int>> frequencia_palavra_, int num_docs_total)
{
for (auto i = frequencia_palavra_.begin(); i != frequencia_palavra_.end(); i++) {
	string palavra = i->first;
	
		map<string, double>::iterator it = frequencia_invertida_palavra_.find(palavra);

		if (it != frequencia_invertida_palavra_.end()) {
		}
		else if (it == frequencia_invertida_palavra_.end()) { //Elemento n�o achado
			double frequencia_int;
			frequencia_int = log10((num_docs_total / frequencia_palavra_[palavra].size()));
			frequencia_invertida_palavra_.insert(std::pair<string, double>(palavra, frequencia_int));//Adiciona o elemento ao mapa frequencia_total_palavra_
		}
	}

}

void frequencia_invertida::imprimi_Invertida()
{
	cout << endl;
	for (auto i = frequencia_invertida_palavra_.begin(); i != frequencia_invertida_palavra_.end(); i++) {
		cout << i->first << " => " << i->second << "   ";
		cout << endl;
	}

}

double frequencia_invertida::frequencia_invertida_palavra(string palavra)
{
	return frequencia_invertida_palavra_[palavra];
}

frequencia_invertida::~frequencia_invertida()
{
}
