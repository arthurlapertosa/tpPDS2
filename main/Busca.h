#ifndef BUSCA
#define BUSCA
#include "LeituraArquivos.h"
#include "wmap.h"
#include "frequencia_palavra.h"
#include "wvector.h"
#include <string>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

class Busca
{
private:
	
	//A classe leitura arquivos, com todas as informações da leitura dos arquivos
	LeituraArquivos arquivos_;

	//A string contendo a pesquisa do usuário
	string pesquisa_;

	//O w da pesquisa do usuário
	wmap w_pesquisa_;

	//Tf da pesquisa
	frequencia_palavra tf_pesquisa_;
	
	//Map do cosine ranking
	map<double, list<string>> cosine_ranking_;

	//wvector com do documento
	wvector wvector_;

	friend class Teste;

public:
	Busca();

	//Realiza todo o processo da maquininha de busca do usuário
	void pesquisa_usuario();

	//Lê os arquivos na pasta
	void LeituraDosArquivos();

	//Monta o tf da pesquisa
	void tf_pesquisa();

	//Retorna o tf da palavra
	int tf_retorna(string palavra);

	//Constroi o w da pesquisa do usuário
	void w_pesquisa_construcao();

	//constroi o consine ranking
	void cosine_ranking_build();

	//Parte de cima da formula de similaridade
	double parte_de_cima_sim(int num_doc);

	//Parte de baixo-direita da formula de similaridade
	double parte_de_baixo_dir_sim();

	//Parte de baixo-esquerda da formula de similaridade
	double parte_de_baixo_esq_sim(int num_doc);

	//Imprime o resultado da pesquisa
	void imprimir_resultado_pesquisa();
	
};



#endif //BUSCA