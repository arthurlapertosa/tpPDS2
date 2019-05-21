#include <iostream>
#include "LeituraArquivos.h"

int main(){
	LeituraArquivos arquivos;
	arquivos.ler();
	arquivos.imprimirFrequenciaPalavras();
	//arquivos.imprimirIndice();
	cout << endl << "O numero total de documentos eh: " << arquivos.numeroDocs() << endl;
}
