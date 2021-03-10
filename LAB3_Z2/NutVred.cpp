#include "NutVred.h"

NutVred::NutVred(double aUgh, double aMas, double aPro) : ugh(aUgh), mas(aMas), pro(aPro) {}

double NutVred::GetUgh() const {
	return ugh;
}

double NutVred::GetMas() const {
	return mas;
}

double NutVred::GetPro() const {
	return pro;
}

double NutVred::CalcCal() const {
	return (ugh + pro) * 4 + mas * 9;
}

NutVred operator+(const NutVred &n1, const NutVred &n2) {
	return NutVred(n1.ugh + n2.ugh, n1.mas + n2.mas, n1.pro + n2.pro);
}

ostream & operator<<(ostream &os, const NutVred &nv) {
	return os << "[uh:" << nv.ugh << ", ma:" << nv.mas << ", pr:" << nv.pro << "]";
}
