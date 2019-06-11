//#include <iostream>
//#include "Busca.h"
//
//int main(){
//	Busca primeiro;
//	primeiro.pesquisa_usuario();
//} 

/////////////////////////// ACIMA DISTO, MAIN NORMAL 


///////////////////////////////////////////////// TESTES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//Palavras chave para teste : oi - 6, voce - 5, casa - 4, coisas - 3, pessoas - 2

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "busca.h"
#include <iostream>
#include "doctest.h"

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
	map<double, list<string>> cosine_ranking(const Busca &a) {
		return a.cosine_ranking_; //Map do cosine ranking
	}
	wvector w_vector(const Busca& a) {
		return a.wvector_; //wvector com do documento
	}
};

//std::ostream& operator<< (std::ostream& os, Complexo& c) {
//	if (c.imag() >= 0.0) {
//		os << c.real() << " + " << c.imag() << "i";
//	}
//	else {
//		os << c.real() << " - " << -c.imag() << "i";
//	}
//	return os;
//}

TEST_SUITE("Busca") {
	Busca a;
	TEST_CASE("Numero Documentos") {
		CHECK(Teste::arquivos(a).numeroDocs() == 6);
	}
	TEST_CASE("TF Documentos") {
		CHECK(Teste::arquivos(a).tf("d1.txt", "oi") == 3);
		CHECK(Teste::arquivos(a).tf("d2.txt", "esta") == 1);
		CHECK(Teste::arquivos(a).tf("d3.txt", "voce") == 4);
		CHECK(Teste::arquivos(a).tf("d4.txt", "coisas") == 2);
		CHECK(Teste::arquivos(a).tf("d5.txt", "casa") == 2);
		CHECK(Teste::arquivos(a).tf("d6.txt", "pessoas") == 1);
	}
	TEST_CASE("IDF Documentos") {
		CHECK((Teste::arquivos(a).idf("voce") >= 0.07 && Teste::arquivos(a).idf("voce") <= 0.08));
		// ANDRE - FAZER PELO MENOS DAS PALAVRAS oi , casa , coisas , pessoas 
	}
	TEST_CASE("Numero documentos que a palavra aparece") {
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("oi") == 6);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("voce") == 5);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("casa") == 4);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("coisas") == 3);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("pessoas") == 2);
		CHECK(Teste::arquivos(a).numero_Doc_Palavra("precisamos") == 1);
	}
}