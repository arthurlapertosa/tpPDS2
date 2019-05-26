#include "frequencia_palavra.h"



frequencia_palavra::frequencia_palavra()
{
}


void frequencia_palavra::inserir(string palavra, string documento) {
	map<string, map<string, int>>::iterator it = frequencia_palavra_.find(palavra);

	if (it != frequencia_palavra_.end()) { // Elemento foi achado
		map<string, int>::iterator it2 = frequencia_palavra_[palavra].find(documento);

		if (it2 != frequencia_palavra_[palavra].end()){ //elemento segundo mapa foi achado
			frequencia_palavra_[palavra][documento]++;
		}
		else if (it2 == frequencia_palavra_[palavra].end()) { //Elemento segundo mapa não achado
			frequencia_palavra_[palavra].insert(std::pair<string, int>(documento, 1));
		}
	}
	else if (it == frequencia_palavra_.end()) { //Elemento não achado
		map<string, int> docs; //cria o mapa com o documento e a quantidade de vezes que repetiu
		docs.insert(std::pair<string, int>(documento, 1));
		frequencia_palavra_.insert(std::pair<string, map<string, int>>(palavra, docs));
	}
}

void frequencia_palavra::imprimir() {
	for (auto i = frequencia_palavra_.begin(); i != frequencia_palavra_.end(); i++) {
		cout << i->first << " ====> ";
			for (auto j = i->second.begin(); j != i->second.end(); j++) {
				cout << j->first << " => " << j->second << "   ";
		}
			cout << endl;
	}
}


map<string, map<string, int>> frequencia_palavra::frequenciapalavra()
{
	return frequencia_palavra_;
}

frequencia_palavra::~frequencia_palavra()
{
}
