#pragma once

#include "Takt.h"

class Kompozicija {
public:
	Kompozicija();
	Kompozicija(const Kompozicija &) = delete;

	Kompozicija & operator=(const Kompozicija &) = delete;
	friend ostream & operator<<(ostream &, const Kompozicija &);

	Kompozicija & Add(Takt &);
protected:
private:
	Sekvenca<Takt *> seq;
	Razlomak takt;
	bool finalized;
};

Kompozicija::Kompozicija() : takt(0), finalized(false) {}

ostream & operator<<(ostream &os, const Kompozicija &k) {
	for (int i = 0; i < k.seq.GetSize(); i++) {
		os << *k.seq[i] << "\n";
	}
	return os;
}

Kompozicija & Kompozicija::Add(Takt &t) {
	if (!t.GetOver()) {
		throw ENoAdd();
	}

	if (!seq.GetSize()) {
		takt = t.GetMaxx();
	}
	else {
		if (t.GetMaxx() > takt || takt > t.GetMaxx()) {
			throw ENotEqualLength();
		}
		if (t.GetNotCompleted()) {
			if (!finalized) {
				finalized = true;
			}
			else {
				throw ENotFinalized();
			}
		}
	}

	seq.Add(&t);

	return *this;
}