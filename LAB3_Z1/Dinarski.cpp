#include "Dinarski.h"

Dinarski::Dinarski(Osoba *aOso, string aBroj) : Racun(aOso, aBroj) {}

string Dinarski::GetOzn() const {
	return "RSD";
}
