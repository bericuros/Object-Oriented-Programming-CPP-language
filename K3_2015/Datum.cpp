#include "Datum.h"

Datum::Datum(int aMes, int aGod) : mes(aMes), god(aGod) {}

bool operator==(const Datum &d1, const Datum &d2) {
	return d1.mes == d2.mes && d1.god == d2.god;
}

bool operator!=(const Datum &d1, const Datum &d2) {
	return d1.mes != d2.mes || d1.god != d2.god;
}

ostream & operator<<(ostream &os, const Datum &d) {
	return os << d.mes << "/" << d.god;
}
