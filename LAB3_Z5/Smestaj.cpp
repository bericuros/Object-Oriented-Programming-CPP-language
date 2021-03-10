#include "Smestaj.h"

Smestaj::Smestaj(const Destinacija &aDest, Tip aTip, string aNaziv, int aBrzv, double aCena) :
	dest(aDest), tip(aTip), naziv(aNaziv), brzv(aBrzv), cena(aCena) {
	if (brzv < 1 || brzv > 5) {
		throw GZvezdice();
	}
}

Destinacija Smestaj::GetDest() const {
	return dest;
}

Smestaj::Tip Smestaj::GetTip() const {
	return tip;
}

string Smestaj::GetNaziv() const {
	return naziv;
}

int Smestaj::GetBrzv() const {
	return brzv;
}

double Smestaj::GetCena() const {
	return cena;
}

ostream & operator<<(ostream &os, const Smestaj &s) {
	return os << (s.tip == 0 ? "HOTEL" : "APARTMAN") << " " << s.naziv << " " << setw(s.brzv) << setfill('*') << "";
}
