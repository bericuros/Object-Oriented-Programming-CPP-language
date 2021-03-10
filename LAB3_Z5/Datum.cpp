#include "Datum.h"

int Datum::days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

Datum::Datum(int aDan, int aMes, int aGod) : dan(aDan), mes(aMes), god(aGod) {
	if (aMes < 1 || aMes > 12 || aDan < 1 || aDan > DaysMonth(aMes, aGod) || aGod == 0) {
		throw GPogresanDatum();
	}
}

int Datum::GetDan() const {
	return dan;
}

int Datum::GetMes() const {
	return mes;
}

int Datum::GetGod() const {
	return god;
}

int Datum::DaysMonth(int aMes, int aGod) const {
	if (aMes == 2 && ((aGod % 4 == 0 && aGod % 100 != 0) || aGod % 400 == 0)) {
		return 29;
	}
	return days[aMes] - days[aMes - 1];
}

int operator-(const Datum &d1, const Datum &d2) {
	int dan1 = d1.dan - 306;
	int dan2 = d2.dan - 306;
	int mes1 = (153 * (d1.mes + 12 * (d1.mes < 3)) - 457) / 5;
	int mes2 = (153 * (d2.mes + 12 * (d2.mes < 3)) - 457) / 5;
	int god1 = 365 * (d1.god - (d1.mes < 3)) + (d1.god - (d1.mes < 3)) / 4 - (d1.god - (d1.mes < 3)) / 100 + (d1.god - (d1.mes < 3)) / 400;
	int god2 = 365 * (d2.god - (d2.mes < 3)) + (d2.god - (d2.mes < 3)) / 4 - (d2.god - (d2.mes < 3)) / 100 + (d2.god - (d2.mes < 3)) / 400;
	return dan1 + mes1 + god1 - dan2 - mes2 - god2;
}

ostream & operator<<(ostream &os, const Datum &d) {
	return os << d.dan << "." << d.mes << "." << d.god << ".";
}
