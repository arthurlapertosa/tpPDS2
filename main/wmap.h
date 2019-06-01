#ifndef WSET_H
#define WSET_H
#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;


class wmap {
private:
	map<string, double> wmap_;
public:
	void inserir_no_wmap(string palavra, double valor);

	void exibir();
};

#endif WSET_H
