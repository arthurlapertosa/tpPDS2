#include "LeituraArquivos.h"

using namespace std;


LeituraArquivos::LeituraArquivos() {
	numero_doc_ = 0;
}

void LeituraArquivos::ler() {
	//Cria o documento
	ifstream words;
	for (int i = 1; 1; i++) {
		words.open("d" + to_string(i) + ".txt"); //vai lendo cada um dos documentos : d1.txt, d2.txt, ... , dn.txt
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
			indice_.inserir(a, "d" + to_string(i) + ".txt"); //Adiciona a palavra ao indice invertido
			frequencia_.inserir(a, "d" + to_string(i) + ".txt");
		}
		words.close();
	}
}

void LeituraArquivos::imprimirIndice(){
	indice_.imprimirIndice();
}

void LeituraArquivos::imprimirFrequenciaPalavras() {
	frequencia_.imprimir();
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