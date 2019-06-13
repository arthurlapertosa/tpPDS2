#include "wmap.h"

wmap::wmap() {
	norma_vetor_ = 0;
}

void wmap::inserir_no_wmap(string palavra, double valor, string documento) {
	wmap_.insert({ palavra, valor });
	double soma = 0;
	norma_vetor_ = norma_vetor_ + (valor * valor);
	nome_doc_ = documento;

}

void wmap::exibir() {
	map<string, double>::iterator it;
	for (it = wmap_.begin(); it != wmap_.end(); it++)
	{
		std::cout << it->first << "  " << it->second << "  ";
	}
	//system("pause");
}

double wmap::operator[](string palavra)
{
	return wmap_[palavra];
}

map<string, double> wmap::w_map()
{
	return wmap_;
}

double wmap::norma_vetor()
{
	return norma_vetor_;
}

string wmap::nome_doc()
{
	return nome_doc_;
}

void wmap::clear()
{
	wmap_.clear();
}
