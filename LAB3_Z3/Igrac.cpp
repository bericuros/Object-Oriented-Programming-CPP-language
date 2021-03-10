#include "Igrac.h"

Igrac::Igrac(string aIme, int aVred) : ime(aIme), vred(aVred) {}

string Igrac::GetIme() const {
	return ime;
}

int Igrac::GetVred() const {
	return vred;
}

void Igrac::Incr(double pc) {
	vred = static_cast<int>((100.0 + pc) / 100 * vred);
}

void Igrac::Decr(double pc) {
	vred = static_cast<int>((100.0 - pc) / 100 * vred);
}

bool operator==(const Igrac &i1, const Igrac &i2) {
	return i1.ime == i2.ime && i1.vred == i2.vred;
}

ostream & operator<<(ostream &os, const Igrac &i) {
	return os << i.ime << "#" << i.vred;
}
