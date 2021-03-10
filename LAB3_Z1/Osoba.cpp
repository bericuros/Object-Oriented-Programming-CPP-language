#include "Osoba.h"

Osoba::Osoba(string aIme, string aJmbg, const Datum &aDat) : ime(aIme), jmbg(aJmbg), dat(aDat) {}

string Osoba::GetIme() const {
	return ime;
}

string Osoba::GetJmbg() const {
	return jmbg;
}

Datum Osoba::GetDat() const {
	return dat;
}

ostream & operator<<(ostream &os, const Osoba &o) {
	return os << "O(" << o.ime << ", " << o.jmbg << ", " << o.dat << ")";
}
