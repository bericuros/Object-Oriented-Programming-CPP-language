#include "Boja.h"

Boja::Boja(int aRed, int aGre, int aBlu) : red(aRed), gre(aGre), blu(aBlu) {
	if (red < 0 || red > 255 || gre < 0 || gre > 255 || blu < 0 || blu > 255) {
		throw EWrongColor();
	}
}

int Boja::GetRed() const {
	return red;
}

int Boja::GetGre() const {
	return gre;
}

int Boja::GetBlu() const {
	return blu;
}

bool operator==(const Boja &b1, const Boja &b2) {
	return b1.red == b2.red && b1.gre == b2.gre && b1.blu == b2.blu;
}
