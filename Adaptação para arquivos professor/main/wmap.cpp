#include "wmap.h"

void wmap() {
}

void wmap::inserir_no_wmap(string palavra, double valor, string documento) {
	wmap_.insert({ palavra, valor });
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

string wmap::nome_doc()
{
	return nome_doc_;
}

map<string, double> wmap::w_map()
{
	return wmap_;
}
