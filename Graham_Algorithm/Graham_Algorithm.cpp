#include <iostream>
#include "Punkt.h"
#include <vector>
#include "Lista.h"
#include "Stos.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

template<class pkt>
Lista<pkt> importuj(string nazwa_pliku) {
	fstream plik(nazwa_pliku, ios_base::in);
	string wiersz;
	int rozmiar;
	
	double x, y;
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
	Graham_Algorithm() {
		punkty = Lista<pkt>();
	}

	Graham_Algorithm(Lista<pkt> lista) {
		punkty = lista;
	}

	int punkt_startowy() {
		pkt najnizszy = pkt();
		int indeks = 0;

		for (int i = 0; i < punkty.ilosc_elem(); i++) {
			if (punkty[i].pokaz_y() < najnizszy.pokaz_y() ||
				(punkty[i].pokaz_y() == najnizszy.pokaz_y() && punkty[i].pokaz_x() < najnizszy.pokaz_x())) {
				najnizszy = punkty[i];
				indeks = i;
			}
		}

		return indeks;
	}

};

int main()
{
	
	Lista<Punkt> a = (importuj<Punkt>("points4.txt"));
	Graham_Algorithm<Punkt> graham = Graham_Algorithm<Punkt>(a);
	int i = graham.punkt_startowy();

	cout << i << ": " << a[i].pokaz_x() << " " << a[i].pokaz_y() << endl;

}
