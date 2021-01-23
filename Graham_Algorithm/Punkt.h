#pragma once

#include <iostream>

using namespace std;

class Punkt {
private:
	double x;
	double y;

public:
	Punkt() {
		this->x = 0;
		this->y = 0;
	}

	Punkt(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double get_x() {
		return this->x;
	}

	double get_y() {
		return this->y;
	}

	bool to_ten_sam_pkt(Punkt pkt) {
		if (this->x == pkt.get_x() && this->y == pkt.get_y()) return true;
		else return false;
	}


};
