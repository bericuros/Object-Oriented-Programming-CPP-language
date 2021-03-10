#include "Destinacija.h"

Destinacija::Destinacija(string aNaziv, string aOpis) : naziv(aNaziv), opis(aOpis) {
	mark = 0;
	num = 0;
}

string Destinacija::GetNaziv() const {
	return naziv;
}

string Destinacija::GetOpis() const {
	return opis;
}

double Destinacija::GetMark() const {
	return mark;
}

void Destinacija::Mark(unsigned char aMark) {
	if (aMark > 0 && aMark <= 5) {
		double temp = mark * num;
		num++;
		mark = (temp + aMark) / num;
	}
}

bool operator>(const Destinacija &d1, const Destinacija &d2) {
	return d1.mark > d2.mark;
}

bool operator!=(const Destinacija &d1, const Destinacija &d2) {
	return d1.naziv != d2.naziv || d1.opis != d2.opis || d1.mark != d2.mark || d1.num != d2.num;
}

ostream & operator<<(ostream &os, const Destinacija &d) {
	return os << "[" << d.mark << "]" << d.naziv << "(" << d.opis << ")";
}
