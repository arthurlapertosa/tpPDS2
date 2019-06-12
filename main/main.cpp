//#include <iostream>
//#include "Busca.h"
//
//int main(){
//	Busca primeiro;
//	primeiro.pesquisa_usuario_digita();
//} 

/////////////////////////// ACIMA DISTO, MAIN NORMAL 


///////////////////////////////////////////////// TESTES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//Palavras chave para teste : oi - 6, voce - 5, casa - 4, coisas - 3, pessoas - 2

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "busca.h"
#include <iostream>
#include "doctest.h"
#include <cmath>
#include <list>

#include <limits>

class Teste
{
public:
	static LeituraArquivos arquivos(const Busca& a) { //A classe leitura arquivos, com todas as informações da leitura dos arquivos
		return a.arquivos_;
	}
	static string pesquisa(const Busca& b) {
		return b.pesquisa_; //A string contendo a pesquisa do usuário
	}
	static wmap w_pesquisa(const Busca& a) {
		return a.w_pesquisa_; //O w da pesquisa do usuário
	}
	static frequencia_palavra tf_pesquisa(const Busca& a) {
		return a.tf_pesquisa_; //Tf da pesquisa
	}
	map<double, list<string>> cosine_ranking(const Busca& a) {
		return a.cosine_ranking_; //Map do cosine ranking
	}
	wvector w_vector(const Busca& a) {
		return a.wvector_; //wvector com do documento
	}
};

//////////////////////////////////////////// FERRAMENTA PARA COMPARAR DUAS LISTAS
bool compare_lists(list<string> a, list<string> b) {
	if (a.size() != b.size()) return false;
	auto i = a.begin();
	auto j = b.begin();
	for (; i != a.end() && j != b.end(); i++, j++) {
		if (*i != *j) return false;
	}
	return true;
}
//////////////////////// FERRAMENTAS PARA AJUDAR A ACESSAR AS LISTAS DE DOCUMENTOS DO MAP DO COSINE RANKING -- EM ORDEM DO DOCUMENTO MAIS RELEVANTE PARA O MENOS RELEVANTE
list<string> first_list(map<double, list<string>> a) { //retorna a lista do ultimo elemento do map
	auto i = a.rbegin();
	return i->second;
}
list<string> second_list(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++;
	return i->second;
}
list<string> third_list(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++;
	return i->second;
}
list<string> fourth_list(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++; i++;
	return i->second;
}
list<string> fifth_list(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++; i++; i++;
	return i->second;
}
list<string> sixth_list(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++; i++; i++; i++;
	return i->second;
}

///////////////////////////////////////// FERRAMENTAS PARA AJUDAR A ACESSAR OS ELEMENTOS CHAVE DO MAP DO COSINE RANKING
double first_key(map<double, list<string>> a) { //retorna a lista do ultimo elemento do map
	auto i = a.rbegin();
	return i->first;
}
double second_key(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++;
	return i->first;
}
double third_key(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++;
	return i->first;
}
double fourth_key(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++; i++;
	return i->first;
}
double fifth_key(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++; i++; i++;
	return i->first;
}
double sixth_key(map<double, list<string>> a) {
	auto i = a.rbegin();
	i++; i++; i++; i++; i++;
	return i->first;
}

TEST_SUITE("Busca") {
	Busca a;
	TEST_CASE("LeituraArquivos: Numero Documentos") {
		CHECK(Teste::arquivos(a).numeroDocs() == 6);
	}
	TEST_CASE("LeituraArquivos: TF Documentos") {
		CHECK(Teste::arquivos(a).tf("d1.txt", "oi") == 3);
		CHECK(Teste::arquivos(a).tf("d2.txt", "esta") == 1);
		CHECK(Teste::arquivos(a).tf("d3.txt", "voce") == 4);
		CHECK(Teste::arquivos(a).tf("d4.txt", "coisas") == 2);
		CHECK(Teste::arquivos(a).tf("d5.txt", "casa") == 2);
		CHECK(Teste::arquivos(a).tf("d6.txt", "pessoas") == 1);
	}
	TEST_CASE("LeituraArquivos: IDF Documentos") {
		CHECK((Teste::arquivos(a).idf("voce") >= 0.07 && Teste::arquivos(a).idf("voce") <= 0.08));
		CHECK(Teste::arquivos(a).idf("oi") == 0.0);
		CHECK((Teste::arquivos(a).idf("casa") >= 0.17 && Teste::arquivos(a).idf("casa") <= 0.18));
		CHECK((Teste::arquivos(a).idf("coisas") >= 0.30 && Teste::arquivos(a).idf("coisas") <= 0.31));
		CHECK((Teste::arquivos(a).idf("pessoas") >= 0.47 && Teste::arquivos(a).idf("pessoas") <= 0.48));
	}
	TEST_CASE("LeituraArquivos: frequencia_palavra: Numero documentos que a palavra aparece") {
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("oi") == 6);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("voce") == 5);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("casa") == 4);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("coisas") == 3);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("pessoas") == 2);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("precisamos") == 1);
	}
	TEST_CASE("LeituraArquivos: Verifica(caracteres especiais)") {
		CHECK(Teste::arquivos(a).verifica("guarda-chuva") == "guardachuva");
		CHECK(Teste::arquivos(a).verifica("micro--ondas") == "microondas");
		CHECK(Teste::arquivos(a).verifica("67890a!b@3#c$d%e¨f&g*h(i)12345") == "abcdefghi");
	}
	TEST_CASE("LeituraArquivos: minusculo(transforma em minusculo)") {
		CHECK(Teste::arquivos(a).minusculo("OLA COMO VAI VOCE") == "ola como vai voce");
		CHECK(Teste::arquivos(a).minusculo("OlA CoMo VaI vOcE") == "ola como vai voce");
	}
	TEST_CASE("LeituraArquivos: Indice Invertido: Tamanho do MAP (Quantidade de palavras totais") {
		CHECK(Teste::arquivos(a).indiceInvertido().indiceInvertido().size() == 27);
	}
	TEST_CASE("LeituraArquivos: Indice Invertido: Numero de documentos que a palavra aparece") {
		CHECK(Teste::arquivos(a).indiceInvertido().indiceInvertido()["oi"].size() == 6);
		CHECK(Teste::arquivos(a).indiceInvertido().indiceInvertido()["voce"].size() == 5);
		CHECK(Teste::arquivos(a).indiceInvertido().indiceInvertido()["casa"].size() == 4);
		CHECK(Teste::arquivos(a).indiceInvertido().indiceInvertido()["coisas"].size() == 3);
		CHECK(Teste::arquivos(a).indiceInvertido().indiceInvertido()["pessoas"].size() == 2);
		CHECK(Teste::arquivos(a).indiceInvertido().indiceInvertido()["precisamos"].size() == 1);
	}
	TEST_CASE("LeituraArquivos: palavras_return(): Size") {
		CHECK(Teste::arquivos(a).palavras_return().size() == 27);
	}
	TEST_CASE("LeituraArquivos: WVECTOR Size") {
		CHECK(Teste::arquivos(a).retornar_w_vector().w_vector().size() == 6);
	}
	TEST_CASE("LeituraArquivos: WVECTOR -> WMAP Size") {
		CHECK(Teste::arquivos(a).retornar_w_vector().w_vector()[0].w_map().size() == 27);
		CHECK(Teste::arquivos(a).retornar_w_vector().w_vector()[1].w_map().size() == 27);
		CHECK(Teste::arquivos(a).retornar_w_vector().w_vector()[2].w_map().size() == 27);
		CHECK(Teste::arquivos(a).retornar_w_vector().w_vector()[3].w_map().size() == 27);
		CHECK(Teste::arquivos(a).retornar_w_vector().w_vector()[4].w_map().size() == 27);
		CHECK(Teste::arquivos(a).retornar_w_vector().w_vector()[5].w_map().size() == 27);
	}
	TEST_CASE("LeituraArquivos: WVECTOR -> WMAP valores W para cada documento/palavra") {
		//////////////////////////////// d1.txt:
		CHECK(Teste::arquivos(a).retornar_w_vector()[1]["oi"] == 0); //W da palavra oi do documento d1.txt
		CHECK((Teste::arquivos(a).retornar_w_vector()[1]["voce"] > 0.158 && Teste::arquivos(a).retornar_w_vector()[1]["voce"] < 0.159)); //0.1583
		CHECK((Teste::arquivos(a).retornar_w_vector()[1]["casa"] > 0.175 && Teste::arquivos(a).retornar_w_vector()[1]["casa"] < 0.177)); //0.1760
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[1]["coisas"] * 10000) / 10000 == 0.3010); //Função floor usada para arrendondar o valor com 3 casas de decimais
		CHECK(Teste::arquivos(a).retornar_w_vector()[1]["pessoas"] == 0); 
		CHECK(Teste::arquivos(a).retornar_w_vector()[1]["precisamos"] == 0); 

		/////////////////////////////// d2.txt
		CHECK(Teste::arquivos(a).retornar_w_vector()[2]["oi"] == 0); //W da palavra oi do documento d1.txt
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[2]["voce"] * 10000) / 10000 == 0.0791);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[2]["casa"] * 10000) / 10000 == 0.1760);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[2]["coisas"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[2]["pessoas"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[2]["precisamos"]* 10000) / 10000 == 0);

		/////////////////////////////// d3.txt
		CHECK(Teste::arquivos(a).retornar_w_vector()[3]["oi"] == 0); //W da palavra oi do documento d1.txt
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[3]["voce"] * 10000) / 10000 == 0.3167);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[3]["casa"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[3]["coisas"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[3]["pessoas"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[3]["precisamos"] * 10000) / 10000 == 0);

		/////////////////////////////// d4.txt
		CHECK(Teste::arquivos(a).retornar_w_vector()[4]["oi"] == 0); //W da palavra oi do documento d1.txt
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[4]["voce"] * 10000) / 10000 == 0.3959);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[4]["casa"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[4]["coisas"] * 10000) / 10000 == 0.6020);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[4]["pessoas"] * 10000) / 10000 == 0.4771);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[4]["precisamos"] * 10000) / 10000 == 0.7781);

		/////////////////////////////// d5.txt
		CHECK(Teste::arquivos(a).retornar_w_vector()[5]["oi"] == 0); //W da palavra oi do documento d1.txt
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[5]["voce"] * 10000) / 10000 == 0.0791);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[5]["casa"] * 10000) / 10000 == 0.3521);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[5]["coisas"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[5]["pessoas"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[5]["precisamos"] * 10000) / 10000 == 0);

		/////////////////////////////// d6.txt
		CHECK(Teste::arquivos(a).retornar_w_vector()[6]["oi"] == 0); //W da palavra oi do documento d1.txt
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[6]["voce"] * 10000) / 10000 == 0);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[6]["casa"] * 10000) / 10000 == 0.1760);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[6]["coisas"] * 10000) / 10000 == 0.3010);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[6]["pessoas"] * 10000) / 10000 == 0.4771);
		CHECK(floor(Teste::arquivos(a).retornar_w_vector()[6]["precisamos"] * 10000) / 10000 == 0);
	}

	TEST_CASE("LeituraArquivos: W_VECTOR - bool existe(vector<string> x, string palavra)") {
		CHECK(Teste::arquivos(a).retornar_w_vector().existe({ "ola", "como", "bool" }, "bool"));
		CHECK_FALSE(Teste::arquivos(a).retornar_w_vector().existe({ "ola", "como", "bool" }, "oi"));
		CHECK(Teste::arquivos(a).retornar_w_vector().existe({ "ola", "como", "bool", "PDS", "trabalho" }, "trabalho"));
	}

	TEST_CASE("LeituraArquivos: W_VECTOR - vector<string> vetorNaoRep(vector<string> palavra)") {
		CHECK(Teste::arquivos(a).retornar_w_vector().vetorNaoRep({"como", "como"}).size() == 1);
		CHECK(Teste::arquivos(a).retornar_w_vector().vetorNaoRep({"oi", "oi", "oi"}).size() == 1);
		CHECK(Teste::arquivos(a).retornar_w_vector().vetorNaoRep({"oi", "oi", "como", "como"}).size() == 2);
		CHECK(Teste::arquivos(a).retornar_w_vector().vetorNaoRep({"oi", "oi", "como", "ola"}).size() == 3);
		CHECK_FALSE(Teste::arquivos(a).retornar_w_vector().vetorNaoRep({"oi", "oi", "como", "ola"}).size() == 4);
	}

	TEST_CASE("Busca(string pesquisa): realizar várias pesquisas diferentes e conferir resultado do cosine ranking") {
		Busca first("Oi");
		CHECK(first.cosine_ranking().size() == 1);
		CHECK(first_key(first.cosine_ranking()) == 0.0);
		CHECK(compare_lists(first.cosine_ranking()[0.0], { "d1.txt", "d2.txt", "d3.txt", "d4.txt", "d5.txt", "d6.txt" }));
		CHECK(compare_lists(first_list(first.cosine_ranking()), { "d1.txt", "d2.txt", "d3.txt", "d4.txt", "d5.txt", "d6.txt" }));

		Busca second("guardachuva como");
		CHECK(second.cosine_ranking().size() == 2);
		CHECK(compare_lists(first_list(second.cosine_ranking()), { "d1.txt" })); //Testa se o documento mais proximo dessa pesquisa realmente eh o d1.txt
		CHECK(compare_lists(second_list(second.cosine_ranking()), { "d2.txt", "d3.txt", "d4.txt", "d5.txt", "d6.txt" }));
		CHECK(floor(first_key(second.cosine_ranking()) * 10000) / 10000 == 0.7853); //Testa se o cosine ranking entre a pesquisa "guarda-chuva como" e o documento "d1.txt" é igual a 0.7853
		CHECK(floor(second_key(second.cosine_ranking()) * 10000) / 10000 == 0.0); //Testa se o cosine ranking entre a pesquisa "guarda-chuva como" e os documentos {"d2.txt", "d3.txt", "d4.txt", "d5.txt", "d6.txt"} é igual a 0.0

	}
}