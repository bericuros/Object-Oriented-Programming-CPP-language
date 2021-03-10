#include "Namirnica.h"

Namirnica::Namirnica(string aNaziv, const NutVred &aNv, bool aPosna) : naziv(aNaziv), nv(aNv), posna(aPosna) {}

string Namirnica::GetNaziv() const {
	return naziv;
}

NutVred Namirnica::GetNv() const {
	return nv;
}

bool Namirnica::GetPosna() const {
	return posna;
}

bool operator==(const Namirnica &n1, const Namirnica &n2) {
	return n1.naziv == n2.naziv;
}

ostream & operator<<(ostream &os, const Namirnica &n) {
	return os << n.naziv << "-" << n.nv;
}
