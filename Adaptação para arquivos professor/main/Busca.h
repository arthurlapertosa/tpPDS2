#ifndef BUSCA_H
#define BUSCA_H
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
	
	//////////////////////   ATRIBUTOS:

	//A classe leitura arquivos, com todas as informações da leitura dos arquivos
	LeituraArquivos arquivos_;

	//A string contendo a pesquisa do usuário
	string pesquisa_;

	//O w da pesquisa do usuário
	wmap w_pesquisa_;

	//Tf da pesquisa
	frequencia_palavra tf_pesquisa_;
	
	//Map do cosine ranking
	std::map<double, list<string>> cosine_ranking_;

	//wvector do documento
	wvector wvector_;

	//Para retornar os atributos para os Testes
	friend class Teste;

	double parte_de_cima_;
	double parte_de_baixo_esq_;
	double parte_de_baixo_dir_;


	/////////////////////////	METODOS:

	//Realiza todo o processo da maquininha de busca
	void pesquisa_usuario(string pesquisa);
	
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
	void parte_de_cima_sim(int num_doc);

public:
	//Inicializa a classe busca vazia
	Busca();
	
	//Inicializa a classe busca e realiza a busca com o parametro passado
	Busca(string pesquisa);

	//Realiza todo o processo de pesquisar com o usuário digitando a pesquisa na tela
	void pesquisa_usuario_digita();
	
	//Imprime o resultado da pesquisa
	void imprimir_resultado_pesquisa();

	//Retorna o dicionario do cosine ranking - para qualquer tipo de uso desejado
	std::map<double, std::list<string>> cosine_ranking();
};

#endif //BUSCA_H