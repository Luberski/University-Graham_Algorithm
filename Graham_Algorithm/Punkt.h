#pragma once

#include <iostream>

using namespace std;

class Punkt {
private:
	double x;
	double y;

public:
	Punkt() {
		this->x = 1;
		this->y = 1;
	}

	Punkt(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double pokaz_x() {
		return this->x;
	}

	double pokaz_y() {
		return this->y;
	}

	bool to_ten_sam_pkt(Punkt pkt) {
		if (this->x == pkt.pokaz_x() && this->y == pkt.pokaz_y()) return true;
		else return false;
	}


};
