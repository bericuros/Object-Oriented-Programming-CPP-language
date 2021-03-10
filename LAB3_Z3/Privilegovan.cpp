#include "Privilegovan.h"

Privilegovan::Privilegovan(string aNaziv, int aKap, int aMinVred) : Tim(aNaziv, aKap), minVred(aMinVred) {}

Privilegovan & Privilegovan::Add(Igrac *ig, int idx) {
	if (ig->GetVred() < minVred) {
		throw GMalaVred();
	}
	Tim::Add(ig, idx);
	return *this;
}

void Privilegovan::Print(ostream &os) const {
	os << "(" << minVred << ")";
	Tim::Print(os);
}
