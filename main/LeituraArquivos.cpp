#include "LeituraArquivos.h"
#include <list>

using namespace std;


LeituraArquivos::LeituraArquivos() {
	numero_doc_ = 0;
}

void LeituraArquivos::ler(string tipo) {
	//Cria o documento
	ifstream words;
	vector<string> palavras; // Vetor auxiliar
	for (int i = 1; 1; i++) {
		words.open(tipo + to_string(i) + ".txt"); //vai lendo cada um dos documentos : d1.txt, d2.txt, ... , dn.txt
		if (i == 1) {
			if (!words.is_open()) {
				cout << "Falha na leitura de arquivos" << endl;
				numero_doc_ = 0;
				break;
			}
		}
		else if (!words.is_open()) { //Se acabarem os documentos, ele sai do loop
			numero_doc_ = i - 1;
			break;
		}
		string a;
		while (!words.eof()) { //Lê todo o arquivo
			words >> a; //atribui a palavra a variável "a"
			a = minusculo(a);
			a = verifica(a);
			indice_.inserir(a, tipo + to_string(i) + ".txt"); //Adiciona a palavra ao indice invertido
			frequencia_.inserir(a, tipo + to_string(i) + ".txt");
			palavras.insert(palavras.end(), a);
		}
		words.close();
	}
	frequencia_invertida_.inserir(frequencia_.frequenciaPalavra(), numero_doc_);
	cout << "s";
	palavras = wvector_.vetorNaoRep(palavras); // Elimina palavras repetidas no vetor
	auto i1 = palavras.begin();
	lerclone(tipo, palavras);
}

void LeituraArquivos::imprimirIndice(){
	indice_.imprimirIndice();
}

void LeituraArquivos::imprimirFrequenciaPalavras() {
	frequencia_.imprimir();
}

int LeituraArquivos::tf(string documento, string palavra)
{
	return frequencia_.frequenciaPalavraNoDocumento(documento, palavra);
}

void LeituraArquivos::imprimirFrequenciaInvertidaPalavras()
{
	frequencia_invertida_.imprimi_Invertida();
}

double LeituraArquivos::idf(string palavra)
{
	return frequencia_invertida_.frequencia_invertida_palavra(palavra);
}

string LeituraArquivos::verifica(string a) {
	for (int i = 0; i < a.size(); i++) { //verifica cada caracter da palavra
		if (!(a[i] >= 'a' && a[i] <= 'z' || a[i] == 'ç')) { //verifica quais sao especiais
			for (int j = i; j < a.size() - 1; j++) {
				a[j] = a[j + 1]; //substitui pelo caracter seguinte
			}
			a[a.size() - 1] = '\0'; //elimina o ultimo
		}
	}
	return a;
}

string LeituraArquivos::minusculo(string a) {
	transform(a.begin(), a.end(), a.begin(), ::tolower); //Coloca todas as letras para minúsculo
	return a;
}

indice_invertido LeituraArquivos::indiceInvertido() {
	return indice_;
}

int LeituraArquivos::numeroDocs() {
	return numero_doc_;
}

int LeituraArquivos::numero_Doc_Palavra(string palavra)
{
	return frequencia_.frequenciaPalavra()[palavra].size();
}

void LeituraArquivos::lerclone(string tipo, vector<string> palavras) {
	ifstream words;
	for (int i = 1; 1; i++) {
		words.open(tipo + to_string(i) + ".txt"); //vai lendo cada um dos documentos : d1.txt, d2.txt, ... , dn.txt
		if (i == 1) {
			if (!words.is_open()) {
				cout << "Falha na leitura de arquivos" << endl;
				break;
			}
		}
		else if (!words.is_open()) { //Se acabarem os documentos, ele sai do loop
			break;
		}
		string a;
		wmap aux; // Map auxiliar
		auto i1 = palavras.begin();
		for (i1 = palavras.begin(); i1 != palavras.end(); ++i1) { 
			// Insere todas as palavras e seus Ws(tf * idf) no wmap auxiliar
			aux.inserir_no_wmap(*i1, tf(tipo + to_string(i) + ".txt", *i1) * idf(*i1)); 
		}
		wvector_.inserir_vetor(aux); // Incrementa o wvector oficial com o wmap auxiliar (um para cada doc)
		words.close();
	}
}

void LeituraArquivos::imprimir_w() {
	wvector_.exibir();
}

