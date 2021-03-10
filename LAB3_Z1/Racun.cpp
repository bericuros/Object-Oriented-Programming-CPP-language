#include "Racun.h"

Racun::Racun(Osoba *aOso, string aBroj) : oso(aOso), broj(aBroj), iznos(0) {}

Racun & Racun::operator+=(double aIznos) {
	iznos += aIznos;
	return *this;
}

Osoba * Racun::GetOso() const {
	return oso;
}

string Racun::GetBroj() const {
	return broj;
}

double Racun::GetIznos() const {
	return iznos;
}

bool Racun::Transfer(double aIznos, Racun &rac) {
	if (iznos >= aIznos) {
		iznos -= aIznos;
		rac += aIznos;
		return true;
	}
	return false;
}

ostream & operator<<(ostream &os, const Racun &rac) {
	return os << "R:" << rac.broj << ":=:" << rac.iznos << "-" << rac.GetOzn();
}
