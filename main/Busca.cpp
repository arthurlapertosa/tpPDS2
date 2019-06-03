#include "Busca.h"


using namespace std;

Busca::Busca()
{
	LeituraDosArquivos();
}

void Busca::pesquisa_usuario(){
	cout << "Digite sua busca" << endl;
	getline(cin, pesquisa_); //cin para pegar tudo, inclusive os espaços
	

	//monta o tf e depois o W:
	tf_pesquisa();
	w_pesquisa_construcao();
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
	w_pesquisa_.exibir();
}

Busca::~Busca()
{
}
