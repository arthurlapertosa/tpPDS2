#ifndef LEITURAARQUIVOs_H
#define LEITURAARQUIVOs_H //Classe para a leitura dos arquivos
#include <set>
#include <map>
#include <fstream>
#include <string>

using namespace std;

//Não soube como chamar a classe: se leitura de arquivos ou indice invertido

class LeituraArquivos {
private:
	//Cria o mapa de string para uma lista de string que contém os documentos (Indice invertido)
	map<string, set<string>> my_map; 

	//Cria o documento
	ifstream words;

	//Cria a variável tipo bool que testa se o elemento já está no mapa
	pair<std::map<string, set<string>>::iterator, bool> ret;

public:
	//Lê os arquivos e coloca eles no indice invertido
	LeituraArquivos();

	//Imprime o indice invertido
	void imprimirIndice();

};


#endif //LEITURAARQUIVOS_H