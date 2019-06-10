#include "Busca.h"


using namespace std;

Busca::Busca()
{
	LeituraDosArquivos();
	wvector_ = arquivos_.retornar_w_vector();
}

void Busca::pesquisa_usuario(){
	cout << "Digite sua busca" << endl;
	getline(cin, pesquisa_); //cin para pegar tudo, inclusive os espaços
	

	//monta o tf e depois o W:
	tf_pesquisa();
	w_pesquisa_construcao();

	//cout << endl;
	//arquivos_.imprimir_w();

	cosine_ranking_build();
}


void Busca::LeituraDosArquivos()
{
	arquivos_.ler();
	//arquivos_.imprimirFrequenciaInvertidaPalavras();
	//arquivos_.imprimir_w();
}

void Busca::tf_pesquisa()
{
	istringstream divider(pesquisa_);
	string palavra;

	while (divider >> palavra) //Dividindo a string em palavras
	{
		tf_pesquisa_.inserir(palavra, "pesquisa"); //vai inserindo no tf
	}
	//tf_pesquisa_.imprimir();
}

int Busca::tf_retorna(string palavra)
{
	return tf_pesquisa_.frequenciaPalavraNoDocumento("pesquisa", palavra); //Retorna o tf da pesquisa para aquela palavra especifica
}

void Busca::w_pesquisa_construcao()
{
	vector<string> palavras = arquivos_.palavras_return(); //Pega todas as palavras que estão nos arquivos para montar o W da pesquisa
	for (string palavra : palavras) { //for each nas palavras dos arquivos
		w_pesquisa_.inserir_no_wmap(palavra, tf_retorna(palavra) * arquivos_.idf(palavra)); //Vai montando o W da pesquisa
	}
	//w_pesquisa_.exibir();
}

void Busca::cosine_ranking_build()
{
	double sim;
	string documento;
	for (int i = 1; i <= arquivos_.numeroDocs(); i++) { //tem o mais um aqui, pois 
		sim = parte_de_cima_sim(i) / (sqrt(parte_de_baixo_dir_sim()) * sqrt(parte_de_baixo_esq_sim(i)));
		documento = "d" + to_string(i) + ".txt";
		cosine_ranking_.insert({ sim, documento });
	}
	for (auto it = cosine_ranking_.rbegin(); it != cosine_ranking_.rend(); it++)
	{
		std::cout << it->first << "  " << it->second << endl;
	}
}

double Busca::parte_de_cima_sim(int num_doc)
{
	double soma = 0; //soma da parte de cima
	vector<string> palavras = arquivos_.palavras_return(); //Pega todas as palavras que estão nos arquivos para fazer as operações
	for (string palavra : palavras) {
		soma = soma + (wvector_[num_doc][palavra] * w_pesquisa_[palavra]);
	}
	return soma;
}

double Busca::parte_de_baixo_dir_sim()
{
	double soma = 0; //soma da parte de baixo direita
	vector<string> palavras = arquivos_.palavras_return(); //Pega todas as palavras que estão nos arquivos para fazer as operações
	for (string palavra : palavras) {
		soma = soma + (w_pesquisa_[palavra] * w_pesquisa_[palavra]);
	}
	return soma;
}

double Busca::parte_de_baixo_esq_sim(int num_doc)
{
	double soma = 0; //soma da parte de baixo esq
	vector<string> palavras = arquivos_.palavras_return(); //Pega todas as palavras que estão nos arquivos para fazer as operações
	for (string palavra : palavras) {
		soma = soma + (wvector_[num_doc][palavra] * wvector_[num_doc][palavra]);
	}
	return soma;
}

Busca::~Busca()
{
}
