#include <iostream>
#include "Punkt.h"
#include <vector>
#include "Lista.h"
#include "Stos.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

Punkt PUNKT_STARTOWY;

template<class pkt>
float odleglosc_kw(pkt p1, pkt p2) { // tested
	return (p1.pokaz_x() - p2.pokaz_x()) * (p1.pokaz_x() - p2.pokaz_x()) + (p1.pokaz_y() - p2.pokaz_y()) * (p1.pokaz_y() - p2.pokaz_y());
}

template<class pkt>
int kierunek(pkt p1, pkt p2, pkt p3) { // tested
	float iloczyn_poprzeczny = (p2.pokaz_x() - p1.pokaz_x()) * (p3.pokaz_y() - p1.pokaz_y()) - (p2.pokaz_y() - p1.pokaz_y()) * (p3.pokaz_x() - p1.pokaz_x());
	if (iloczyn_poprzeczny > 0) return 1; // zgodnie z ruchem wskazówek zegara
	else if (iloczyn_poprzeczny < 0)  return -1; // przeciwnie
	else return 0; // równe
}

template<class pkt>
int komparator(const void* wsk_p1, const void* wsk_p2) { // tested
	pkt* p1 = (pkt*)wsk_p1;
	pkt* p2 = (pkt*)wsk_p2;

	int k = kierunek(PUNKT_STARTOWY, *p1, *p2);

	if (k == 0) {
		if (odleglosc_kw(PUNKT_STARTOWY, *p2) >= odleglosc_kw(PUNKT_STARTOWY, *p1)) {
			return -1;
		}
		else return 1;
	}
	else {
		return k;
	}
}

template<class pkt>
Lista<pkt> importuj(string nazwa_pliku) { // tested
	fstream plik(nazwa_pliku, ios_base::in);
	string wiersz;
	int rozmiar;
	
	float x, y;
	(plik >> rozmiar);

	Lista<pkt> Punkty = Lista<pkt>(rozmiar);
	while (plik >> x >> y) {
		pkt p(x, y);
		Punkty.dodaj_pkt(p);
	}

	return Punkty;
}

template<class pkt>
class Graham_Algorithm {
private:
	Lista<pkt> punkty;

public:
	Graham_Algorithm() { // tested
		this->punkty = Lista<pkt>();
	}

	Graham_Algorithm(Lista<pkt> lista) { // tested
		this->punkty = lista;
	}

	int znajdz_punkt_startowy() { // tested
		pkt najnizszy = pkt();
		int indeks = 0;

		for (int i = 0; i < this->punkty.ilosc_elem(); i++) {
			if (this->punkty[i].pokaz_y() < najnizszy.pokaz_y() ||
				(this->punkty[i].pokaz_y() == najnizszy.pokaz_y() && this->punkty[i].pokaz_x() < najnizszy.pokaz_x())) {
				najnizszy = this->punkty[i];
				indeks = i;
			}
		}

		PUNKT_STARTOWY = this->punkty[indeks];
		this->punkty.zamien_miejscami(0, indeks);
		return indeks;
	}

	void sortuj_wzgledem(int indeks) { // tested
		qsort(&this->punkty[1], (long long)this->punkty.ilosc_elem() - 2, sizeof(Punkt), komparator<pkt>);
	}

	void opakuj() {
		this->sortuj_wzgledem(this->znajdz_punkt_startowy());

		Stos<pkt> stos = Stos<pkt>(this->punkty.ilosc_elem());

		stos.wloz(this->punkty[0]);
		stos.wloz(this->punkty[1]);

		for (int i = 2; i < this->punkty.ilosc_elem() - 1; i++) {

		}

	}
};

int main()
{
	Lista<Punkt> lista = importuj<Punkt>("points1.txt");
	Graham_Algorithm<Punkt> graham = Graham_Algorithm<Punkt>(lista);
	
	
	
	
	

}
