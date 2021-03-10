#include "Sastojak.h"

Sastojak::Sastojak(string aName, double aUnit) : name(aName), unit(aUnit) {}

double Sastojak::GetPrice(int amount) const {
	return unit * amount / 1000;
}

Slan::Slan(string aName, double aUnit) : Sastojak(aName, aUnit) {}

Sastojak::Type Slan::GetType() const {
	return SLAN;
}

Sladak::Sladak(string aName, double aUnit) : Sastojak(aName, aUnit) {}

Sastojak::Type Sladak::GetType() const {
	return SLAD;
}

Neutralan::Neutralan(string aName, double aUnit) : Sastojak(aName, aUnit) {}

Sastojak::Type Neutralan::GetType() const {
	return NEUT;
}

ostream & operator<<(ostream &os, const Sastojak &s) {
	return os << s.name << "-" << s.unit << "/kg";
}
