#include "Datum.h"

Datum::Datum(int aDan, int aMes, int aGod) : dan(aDan), mes(aMes), god(aGod) {}

bool operator==(const Datum &d1, const Datum &d2) {
	return d1.dan == d2.dan && d1.mes == d2.mes && d1.god == d2.god;
}

ostream & operator<<(ostream &os, const Datum &d) {
	return os << d.dan << "." << d.mes << "." << d.god << ".";
}
