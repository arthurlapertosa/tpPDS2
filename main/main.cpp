#include <iostream>
#include "LeituraArquivos.h"

int main(){
	LeituraArquivos arquivos;
	arquivos.ler();
	arquivos.imprimirIndice();
	cout << endl << "O numero total de documentos eh: " << arquivos.numeroDocs() << endl;
}
