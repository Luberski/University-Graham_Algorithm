#include <iostream>
#include "Punkt.h"
#include <vector>
#include "Lista.h"
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
	long double x, y;
	
	if (!(plik >> rozmiar)) {
		cout << "Wystapil blad" << endl;
		return NULL;
	}
	else {
		Lista<pkt> 
	}

	printf("%d\n", rozmiar);
	while (plik >> x >> y) {

		cout << setprecision(14) << x << " " << y << endl;
	}
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

};

int main()
{
	importuj<Punkt>("points1.txt");
}
