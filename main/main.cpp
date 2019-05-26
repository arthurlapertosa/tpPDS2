#include <iostream>
#include "LeituraArquivos.h"

int main(){
	LeituraArquivos arquivos;
	arquivos.ler();
	arquivos.imprimirFrequenciaPalavras();
	//arquivos.imprimirIndice();
	cout << endl << "O numero total de documentos eh: " << arquivos.numeroDocs() << endl;
	cout << "Entre com a palavra: " << endl;
	string palavra;
	cin >> palavra;
	cout << endl << "O numero total de documentos que a palavra aparece eh: " << arquivos.numero_Doc_Palavra(palavra) << endl;
	arquivos.imprimirFrequenciaInvertidaPalavras();
}
