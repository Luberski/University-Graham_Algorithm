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
	Stos() {}

	Stos(int rozmiar) {
		stos = new T[rozmiar];
		this->rozmiar = rozmiar;
	}

	void wloz(T pkt) {
		stos[ie] = pkt;
		this->ie++;
	}

	void zdejmij() {
		ie--;
	}
	
	void pokaz_zbior() {
		for (int i = 0; i < this->ie - 1; i++) {
			cout << setprecision(13) << stos[i].pokaz_x() << " " << stos[i].pokaz_y() << endl;
		}
	}

};
