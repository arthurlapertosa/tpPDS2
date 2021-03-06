#include "wvector.h"

void wvector() {
}

void wvector::inserir_vetor(wmap documento) {
	auto i = w_.end();
	w_.insert(i, documento);
}

void wvector::exibir() {
	for (auto it = begin(w_); it != end(w_); ++it) {
		it->exibir();
		cout << endl << endl;
	}
}

vector<string>wvector::vetorNaoRep(vector<string> palavra) {
	vector<string> aux;
	aux.clear();
	string p;
	auto i = palavra.begin();
	for (i = palavra.begin(); i != palavra.end(); ++i) {
		p = *i;
		if (!existe(aux, p)) {
			aux.insert(aux.end(), p);
		}
	}
	return aux;
}

bool wvector::existe(vector<string> x, string palavra) {
	if (x.empty()) {
		return false;
	}
	string p;
	auto i = x.begin();
	for (i = x.begin(); i != x.end(); ++i) {
		p = *i;
		if (p == palavra) {
			return true;
		}
	}
	return false;
}

wmap wvector::operator[](int documento)
{
	int indice = documento - 1;
	return w_[indice];
}

vector<wmap> wvector::w_vector()
{
	return w_;
}

