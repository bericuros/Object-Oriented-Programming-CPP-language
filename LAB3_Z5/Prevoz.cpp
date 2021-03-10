#include "Prevoz.h"

Prevoz::Prevoz(const Destinacija &aDest, double aKarta) : dest(aDest), karta(aKarta) {}

Prevoz::~Prevoz() {}

Destinacija Prevoz::GetDest() const {
	return dest;
}

double Prevoz::GetCena() const {
	return karta;
}
