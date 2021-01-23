#pragma once
#include <vector>

using namespace std;

template<class T>
class Lista {
private:
	vector<T> *wektor;

public:
	Lista() {
		wektor = new vector<T>(1000);
	}

	Lista(int rozmiar) {
		wektor = new vector<T>(rozmiar);
	}

	T pokaz(int indeks) {
		return wektor[indeks];
	}

	
};