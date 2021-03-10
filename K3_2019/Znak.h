#pragma once

#include "Razlomak.h"

#include <iostream>
#include <string>
using namespace std;

class Znak {
public:
	explicit Znak(const Razlomak &);
	virtual ~Znak();

	friend Razlomak operator+(const Znak &, const Znak &);
	friend ostream & operator<<(ostream &, const Znak &);
	operator Razlomak() const;

	Razlomak GetDur() const;
	virtual string Desc() const = 0;
protected:
private:
	Razlomak dur;
};

Znak::Znak(const Razlomak &aDur) : dur(aDur) {}

Znak::~Znak() {}

Razlomak Znak::GetDur() const {
	return dur;
}

Razlomak operator+(const Znak &z1, const Znak &z2) {
	return z1.dur + z2.dur;
}

Znak::operator Razlomak() const {
	return dur;
}

ostream & operator<<(ostream &os, const Znak &z) {
	return os << z.Desc() << "(" << z.dur << ")";
}