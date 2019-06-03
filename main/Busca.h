#ifndef BUSCA
#define BUSCA
#include "LeituraArquivos.h"
#include "wmap.h"
#include "frequencia_palavra.h"
#include <string>
#include <sstream>

class Busca
{
private:
	
	//A classe leitura arquivos, com todas as informações da leitura dos arquivos
	LeituraArquivos arquivos_;

	//A string contendo a pesquisa do usuário
	string pesquisa_;

	//O w da pesquisa do usuário
	wmap w_pesquisa_;

	//Tf da pesquisa
	frequencia_palavra tf_pesquisa_;
public:
	Busca();

	//Busca do usuário
	void pesquisa_usuario();

	//Lê os arquivos na pasta
	void LeituraDosArquivos();

	//Monta o tf da pesquisa
	void tf_pesquisa();

	//Retorna o tf da palavra
	int tf_retorna(string palavra);

	//Constroi o w da pesquisa do usuário
	void w_pesquisa_construcao();

	~Busca();
};



#endif //BUSCA