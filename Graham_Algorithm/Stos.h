#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class Stos {
private:
	T* stos;
	int rozmiar = 0;
	int ie = 0;

public:
	Stos() {
		this->stos = new T[1000];
		this->rozmiar = 1000;
	}

	Stos(int rozmiar) {
		this->stos = new T[rozmiar];
		this->rozmiar = rozmiar;
	}

	void wloz(T pkt) {
		this->stos[ie] = pkt;
		this->ie++;
	}

	void zdejmij() {
		this->ie--;
	}
	
	void pokaz_zbior() {
		for (int i = 0; i < this->ie - 1; i++) {
			cout << setprecision(13) << this->stos[i].wypisz_kordy() << endl;
		}
	}

};
