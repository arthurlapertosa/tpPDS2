#include "Busca.h"


using namespace std;

Busca::Busca()
{
	LeituraDosArquivos();
	wvector_ = arquivos_.retornar_w_vector();
	parte_de_cima_ = 0;
	parte_de_baixo_esq_ = 0;
	parte_de_baixo_dir_ = 0;
}

Busca::Busca(string pesquisa) : Busca() {
	pesquisa_usuario(pesquisa);
}

void Busca::pesquisa_usuario_digita()
{
	string pesquisa;
	string comeca;
	cout << "Digite 1 para realizar uma busca nos documentos: " << endl; //Espera para iniciar a pesquisa e faz o cin.ignore() funcionar 
	cin >> comeca;
	cout << endl <<  "Digite sua busca" << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Ignora qualquer coisa digitada antes, que pode influenciar no getline I
	getline(cin, pesquisa); //cin para pegar tudo, inclusive os espaços
	pesquisa_usuario(pesquisa); //Realiza a pesquisa

	imprimir_resultado_pesquisa();//imprime o resultado da pesquisa
}



void Busca::pesquisa_usuario(string pesquisa){

	
	pesquisa = arquivos_.minusculo(pesquisa); //Transforma tudo em minusculo

	pesquisa_ = pesquisa;

	//monta o tf e depois o W:
	tf_pesquisa();
	w_pesquisa_construcao();

	cosine_ranking_build(); // monta o ranking cosseno

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
		w_pesquisa_.inserir_no_wmap(palavra, tf_retorna(palavra) * arquivos_.idf(palavra), "pesquisa"); //Vai montando o W da pesquisa
	}
	//w_pesquisa_.exibir();
}

void Busca::cosine_ranking_build()
{
	double sim;
	double cima, baixo_dir, baixo_esq; //variáveis para receber os valores para fazer a divisão da formula do rank cosseno
	string documento;
	//Elemento ja pode estar no mapa, pois se existirem 2 documentos com o mesmo peso, um dos 2 documentos não será adicionado ao mapa
	pair<map<double, list<string>>::iterator, bool> ret; //Cria a variável tipo bool que testa se o elemento já está no mapa

	for (int i = 1; i <= arquivos_.numeroDocs(); i++) { //Itera entre os documentos

		try { //tratamento exçecões divisão por zero
			parte_de_cima_sim(i);
			cima = parte_de_cima_; // parte de cima da divisao
			baixo_dir = sqrt(parte_de_baixo_dir_); // Parte de baixo direita da divisao
			baixo_esq = sqrt(parte_de_baixo_esq_); //Parte de baixo esquerda da divisao
			if (baixo_dir == 0 && baixo_esq == 0) throw 0;
			if (baixo_dir == 0) throw 1;
			if (baixo_esq == 0) throw 2;
			sim = cima / (baixo_dir * baixo_esq);
		}
		catch (int erro) {
			if (erro == 0) {
				sim = cima;
			}
			if (erro == 1) {
				sim = cima / baixo_esq;
			}
			if (erro == 2) {
				sim = cima / baixo_dir;
			}
		}
		//wvector_[i].nome_doc;
		documento = wvector_[i].nome_doc();

		ret = cosine_ranking_.insert({ sim, {documento} }); //Insere o elemento no dicionário, sendo o indice a similaridade do documento com a busca. Se a palavra já existir, retorna false para o iterator ret, e o índice não é criado
		if (!ret.second) { //Se não existir o elemento já no mapa
			cosine_ranking_[sim].push_back(documento); //vai adicionando os nomes dos documentos
		}
		cout << "montou o cosine ranking do arquivo " << i << endl;
	}
}


void Busca::parte_de_cima_sim(int num_doc)
{
	vector<string> palavras = arquivos_.palavras_return(); //Pega todas as palavras que estão nos arquivos para fazer as operações
	for (string palavra : palavras) {
		parte_de_cima_ = parte_de_cima_ + (wvector_[num_doc][palavra] * w_pesquisa_[palavra]);
		parte_de_baixo_dir_ = parte_de_baixo_dir_ + (w_pesquisa_[palavra] * w_pesquisa_[palavra]);
		parte_de_baixo_esq_ = parte_de_baixo_esq_ + (wvector_[num_doc][palavra] * wvector_[num_doc][palavra]);
	}
}

void Busca::imprimir_resultado_pesquisa() {
	int rank = 1;
	cout << endl;
	for (auto it = cosine_ranking_.rbegin(); it != cosine_ranking_.rend(); it++)
	{
		cout << it->first << " => ";
		for (auto i = it->second.begin(); i != it->second.end(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
}

std::map<double, std::list<string>> Busca::cosine_ranking()
{
	return cosine_ranking_;
}
