#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Punkt {
private:
	float x;
	float y;

public:
	Punkt() { // tested
		this->x = 100;
		this->y = 100;
	}

	Punkt(float x, float y) { // tested
		this->x = x;
		this->y = y;
	}

	float pokaz_x() { // tested
		return this->x;
	}

	float pokaz_y() { // tested
		return this->y;
	}

	bool to_ten_sam_pkt(Punkt pkt) { // tested
		if (this->x == pkt.pokaz_x() && this->y == pkt.pokaz_y()) return true;
		else return false;
	}

	void wypisz_kordy() { // tested
		cout << setprecision(13) << this->x << " " << this->y << endl;
	}
};
