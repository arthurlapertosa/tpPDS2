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
