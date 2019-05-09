#include "LeituraArquivos.h"
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

LeituraArquivos::LeituraArquivos() {
	for (int i = 1; 1; i++) {
		words.open("d" + to_string(i) + ".txt"); //vai lendo cada um dos documentos : d1.txt, d2.txt, ... , dn.txt
		if (i == 1) {
			if (!words.is_open()) {
				cout << "Falha na leitura de arquivos" << endl;
				break;
			}
		}
		if (!words.is_open()) //Se acabarem os documentos, ele sai do loop
			break;
		string a;
		while (!words.eof()) { //Lê todo o arquivo
			words >> a; //atribui a palavra a variável "a"
			transform(a.begin(), a.end(), a.begin(), ::tolower); //Coloca todas as letras para minúsculo
			set<string> docs = { "d" + to_string(i) + ".txt" }; //Cria uma set com o primeiro elemento com o nome do documento
			ret = my_map.insert(pair <string, set<string>>(a, docs)); //Insere o elemento no dicionário, sendo o índice a palavra. Se a palavra já existir, retorna false para o iterator ret, e o índice não é criado
			if (!ret.second) { //Se não existir o elemento já no mapa
				my_map[a].insert("d" + to_string(i) + ".txt"); //vai adicionando os nomes dos documentos
			}
		}
		words.close();
	}
}

void LeituraArquivos::imprimirIndice() {
	map<string, set<string>>::iterator it; //Interadores
	std::set<string>::iterator it2;
	for (it = my_map.begin(); it != my_map.end(); ++it) { //Imprime todo o mapa com os respectivos valores das listas
		cout << it->first << " => ";// << it->second << endl;
		for (it2 = it->second.begin(); it2 != it->second.end(); ++it2)
			cout << ' ' << *it2;
		cout << endl;
	}
}