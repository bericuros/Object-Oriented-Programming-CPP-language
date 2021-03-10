#pragma once

#include <iostream>
using namespace std;

class Razlomak {
public:
	Razlomak(int aCou, int aDen = 1);

	friend Razlomak operator+(const Razlomak &, const Razlomak &);
	friend bool operator>(const Razlomak &, const Razlomak &);
	friend ostream & operator<<(ostream &, const Razlomak &);
protected:
private:
	int cou, den;
};

Razlomak::Razlomak(int aCou, int aDen) : cou(aCou), den(aDen) {}

Razlomak operator+(const Razlomak &r1, const Razlomak &r2) {
	return Razlomak(r1.cou * r2.den + r1.den * r2.cou, r1.den * r2.den);
}

bool operator>(const Razlomak &r1, const Razlomak &r2) {
	return r1.cou * r2.den > r1.den * r2.cou;
}

ostream & operator<<(ostream &os, const Razlomak &r) {
	return os << r.cou << "/" << r.den;
}