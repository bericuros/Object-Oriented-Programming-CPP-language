#include "Sastojak.h"

Sastojak::Sastojak(const Namirnica &aNam, double aKol) : nam(aNam), kol(aKol) {}

Namirnica Sastojak::GetNam() const {
	return nam;
}

double Sastojak::GetKol() const {
	return kol;
}

NutVred Sastojak::CalcNv() const {
	return NutVred(nam.GetNv().GetUgh() * kol / 100.0, nam.GetNv().GetMas() * kol / 100.0, nam.GetNv().GetPro() * kol / 100.0);
}

double Sastojak::CalcCal() const {
	return nam.GetNv().CalcCal() * kol / 100.0;
}

ostream & operator<<(ostream &os, const Sastojak &s) {
	return os << "[" << s.CalcCal() << "kcal] " << s.kol << "g " << "x " << s.nam;
}
