#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class Lista {
private:
	T *lista;
	int rozmiar = 0;
	int ie = 0;


public:
	Lista() {}

	Lista(int rozmiar) {
		lista = new T[rozmiar];
		this->rozmiar = rozmiar;
	}

	T& operator[](int indeks)
	{
		if (indeks >= rozmiar) {
			cout << "Indeks przekracza rozmiar tablicy";
			exit(0);
		}
		return lista[indeks];
	}

	T pokaz(int indeks) {
		if (indeks >= rozmiar) {
			cout << "Indeks przekracza rozmiar tablicy";
			exit(0);
		}
		return lista[indeks];
	}

	void dodaj_pkt(T Punkt) {
		lista[ie] = Punkt;
		this->ie++;
	}

	int ilosc_elem() {
		return ie;
	}

	void pokaz_zbior() {
		for (int i = 0; i < this->ie; i++) {
			cout << setprecision(13) << lista[i].pokaz_x() << " " <<  lista[i].pokaz_y() << endl;
		}
	}


};