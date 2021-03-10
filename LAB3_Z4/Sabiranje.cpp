#include "Sabiranje.h"

string Sabiranje::GetNatpis() const {
	return "+";
}

int Sabiranje::GetPrio() const {
	return 1;
}

Sabiranje * Sabiranje::Copy() const {
	return new Sabiranje(*this);
}
