#include "indice_invertido.h"
#include "leituraArquivos.h"

indice_invertido::indice_invertido() {}

void indice_invertido::inserir(string a, string documento) {
	set<string> docs = { documento }; //Cria uma set com o primeiro elemento com o nome do documento
	pair<map<string, set<string>>::iterator, bool> ret; //Cria a vari�vel tipo bool que testa se o elemento j� est� no mapa
	ret = my_map_.insert(pair <string, set<string>>(a, docs)); //Insere o elemento no dicion�rio, sendo o �ndice a palavra. Se a palavra j� existir, retorna false para o iterator ret, e o �ndice n�o � criado
	if (!ret.second) { //Se n�o existir o elemento j� no mapa
		my_map_[a].insert(documento); //vai adicionando os nomes dos documentos
	}
}

void indice_invertido::imprimirIndice() {
	//map<string, set<string>>::iterator it; //Interadores
	//std::set<string>::iterator it2;
	for (auto it = my_map_.begin(); it != my_map_.end(); ++it) { //Imprime todo o mapa com os respectivos valores das listas
		cout << it->first << " => ";// << it->second << endl;
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
			cout << ' ' << *it2;
		cout << endl;
	}
}


