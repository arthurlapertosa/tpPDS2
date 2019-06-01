#include "wvector.h"
using namespace std;

void wvector() {
}

void wvector::inserir_vetor(wmap documento) {
	auto i = w_.begin();
	w_.insert(i, documento);
}

void wvector::exibir() {
	for (auto it = begin(w_); it != end(w_); ++it) {
		it->exibir();
		cout << endl;
	}
}

vector<string>wvector::vetorNaoRep(vector<string> palavra, string documento) {
	vector<string> aux;
	aux.clear();
	string p;
	auto i = palavra.begin();
	for (i = palavra.begin(); i != palavra.end(); ++i) {
		p = *i;
		if (!existe(aux, p)) {
			aux.insert(aux.begin(), p);
		}
	}
	return aux;
}

bool wvector::existe(vector<string> x, string palavra) {
	auto i = x.begin();
	if (x.empty()) {
		return false;
	}
	string p;
	for (i = x.begin(); i != x.end(); ++i) {
		p = *i;
		if (p == palavra) {
			return true;
		}
		else {
			return false;
		}
	}
}

