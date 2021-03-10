#pragma once

#include "Izuzeci.h"
#include "Sekvenca.h"
#include "Razlomak.h"
#include "Znak.h"
#include "Nota.h"
#include "Pauza.h"

#include <iostream>
using namespace std;

class Takt {
public:
	explicit Takt(const Razlomak &);
	Takt(const Takt &) = delete;

	Takt & operator=(const Takt &) = delete;
	friend ostream & operator<<(ostream &, const Takt &);

	Takt & Add(Znak &);
	Razlomak GetMaxx() const;

	Takt & SetOver();

	bool GetOver() const;
	bool GetNotCompleted() const;
protected:
private:
	Sekvenca<Znak *> seq;
	Razlomak maxx, curr;
	bool over;
};

Takt::Takt(const Razlomak &aMaxx) : maxx(aMaxx), curr(0), over(false) {}

Takt & Takt::Add(Znak &z) {
	if (over) {
		throw EFinalized();
	}
	if (z + curr > maxx) {
		throw ENoAdd();
	}

	seq.Add(&z);
	curr = curr + z;

	return *this;
}

Razlomak Takt::GetMaxx() const {
	return maxx;
}

Takt & Takt::SetOver() {
	over = true;
	return *this;
}

bool Takt::GetOver() const {
	return over;
}

bool Takt::GetNotCompleted() const {
	return maxx > curr;
}

ostream & operator<<(ostream &os, const Takt &t) {
	for (int i = 0; i < t.seq.GetSize(); i++) {
		os << *t.seq[i] << " ";
	}
	return os << "|";
}