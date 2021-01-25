#pragma once
#include <iostream>


using namespace std;

template<class T>
class Lista {
private:
	T *lista;
	int rozmiar = 0;
	int ie = 0;


public:
	Lista() { // tested
		this->lista = new T[1000]; 
		this->rozmiar = 1000; }

	Lista(int rozmiar) { // tested
		this->lista = new T[rozmiar];
		this->rozmiar = rozmiar;
	}

	T& operator[](int indeks) // tested
	{
		if (indeks >= this->rozmiar) {
			cout << "Indeks przekracza rozmiar tablicy";
			exit(0);
		}
		return this->lista[indeks];
	}

	void zamien_miejscami(int ind1, int ind2) { // tested
		if (ind1 != ind2) {
			T temp = this->lista[ind1];
			this->lista[ind1] = this->lista[ind2];
			this->lista[ind2] = temp;
		}
	}

	void dodaj_pkt(T Punkt) { // tested
		this->lista[this->ie] = Punkt;
		this->ie++;
	}

	int ilosc_elem() { // tested
		return this->ie;
	}

	void pokaz_zbior() {
		for (int i = 0; i < this->ie; i++) {
			lista[i].wypisz_kordy();
		}
	}


};