#ifndef LEITURAARQUIVOs_H
#define LEITURAARQUIVOs_H //Classe para a leitura dos arquivos
#include <set>
#include <map>
#include <fstream>
#include <string>

using namespace std;

//N�o soube como chamar a classe: se leitura de arquivos ou indice invertido

class LeituraArquivos {
private:
	//Cria o mapa de string para uma lista de string que cont�m os documentos (Indice invertido)
	map<string, set<string>> my_map; 

	//Cria o documento
	ifstream words;

	//Cria a vari�vel tipo bool que testa se o elemento j� est� no mapa
	pair<std::map<string, set<string>>::iterator, bool> ret;

public:
	//L� os arquivos e coloca eles no indice invertido
	LeituraArquivos();

	//Imprime o indice invertido
	void imprimirIndice();

};


#endif //LEITURAARQUIVOS_H