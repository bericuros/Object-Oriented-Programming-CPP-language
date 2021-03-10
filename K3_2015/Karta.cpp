#include "Karta.h"

int Karta::stId = 0;

ostream & operator<<(ostream &os, const Karta &k) {
	k.Print(os);
	return os;
}

Mesecna::Mesecna(string aOwner, int aGod, int aMes) : Karta(), owner(aOwner), god(aGod), mes(aMes) {}

void Mesecna::Extend(int aGod, int aMes) {
	god = aGod;
	mes = aMes;
}

bool Mesecna::IsValid(double aPrice, const Datum &aDate) {
	return aDate == Datum(mes, god);
}

void Mesecna::Print(ostream &os) const {
	os << owner << "(";
	Karta::Print(os);
	os << ")" << Datum(mes, god);
}

void Karta::Print(ostream &os) const {
	os << id;
}

Pojedinacna::Pojedinacna(double aAmount) : amount(aAmount) {}

bool Pojedinacna::IsValid(double aPrice, const Datum &aDate) {
	if (amount >= aPrice) {
		amount -= aPrice;
		return true;
	}
	return false;
}

void Pojedinacna::Sup(double aBonus) {
	amount += aBonus;
}

void Pojedinacna::Print(ostream &os) const {
	os << amount << "(";
	Karta::Print(os);
	os << ")";
}
