#pragma once

#include "Razlomak.h"
#include "Znak.h"
#include <iostream>
#include <string>
using namespace std;

class Nota : public Znak {
public:
	enum Height{DO, RE, MI, FA, SOL, LA, SI};

	Nota(int, Height, Razlomak);

	Nota & operator<<=(int);
	Nota & operator>>=(int);

	string Desc() const override;
protected:
private:
	static string heights[7];
	int okt;
	Height hei;
};

string Nota::heights[7] = { "DO", "RE", "MI", "FA", "SOL", "LA", "SI" };

Nota::Nota(int aOkt, Height aHei, Razlomak aDur) : okt(aOkt), hei(aHei), Znak(aDur) {}

Nota & Nota::operator<<=(int pom) {
	okt -= pom;
	return *this;
}

Nota & Nota::operator>>=(int pom) {
	okt += pom;
	return *this;
}

string Nota::Desc() const {
	return heights[hei];
}