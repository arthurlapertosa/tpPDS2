#include <iostream>
#include "LeituraArquivos.h"

int main(){
	LeituraArquivos arquivos;
	arquivos.ler("d");
	arquivos.imprimir_w();
	//arquivos.imprimirFrequenciaPalavras();
	//arquivos.imprimirIndice();
	cout << endl << "O numero total de documentos eh: " << arquivos.numeroDocs() << endl;
	cout << "Entre com a palavra e com o documento: " << endl;
	string palavra, documento;
	cin >> palavra;
	cin >> documento;
	cout << endl << "O numero total de documentos que a palavra aparece eh: " << arquivos.numero_Doc_Palavra(palavra) << endl;
	cout << endl << "O tf("<< documento << ", " << palavra << ") eh = "  << arquivos.tf(documento, palavra) << endl;
	cout << endl << "O idf(" << palavra << ") eh = " << arquivos.idf(palavra) << endl;
	arquivos.imprimirFrequenciaInvertidaPalavras();
	
}
