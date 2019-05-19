#include "frequencia_palavra.h"



frequencia_palavra::frequencia_palavra()
{
}


void frequencia_palavra::inserir(string palavra, string documento) {
	map<string, map<string, int>>::iterator it = a.find(palavra);
	

	if (it != a.end()) { // Elemento foi achado
		map<string, int>::iterator it2 = a[palavra].find(documento);

		if (it2 != a[palavra].end()){ //elemento segundo mapa foi achado
			a[palavra][documento]++;
		}
		else if (it2 == a[palavra].end()) { //Elemento segundo mapa não achado
			a[palavra].insert(std::pair<string, int>(documento, 1));
		}
	}
	else if (it == a.end()) { //Elemento não achado
		map<string, int> docs; //cria o mapa com o documento e a quantidade de vezes que repetiu
		docs.insert(std::pair<string, int>(documento, 1));
		a.insert(std::pair<string, map<string, int>>(palavra, docs));
	}
}

void frequencia_palavra::imprimir() {
	for (auto i = a.begin(); i != a.end(); i++) {
		cout << i->first << " ====> ";
			for (auto j = i->second.begin(); j != i->second.end(); j++) {
				cout << j->first << " => " << j->second << "   ";
		}
			cout << endl;
	}
}

frequencia_palavra::~frequencia_palavra()
{
}
