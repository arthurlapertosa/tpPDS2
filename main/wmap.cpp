#include "wmap.h"

void wmap() {
}

void wmap::inserir_no_wmap(string palavra, double valor) {
	wmap_.insert({ palavra, valor });
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
