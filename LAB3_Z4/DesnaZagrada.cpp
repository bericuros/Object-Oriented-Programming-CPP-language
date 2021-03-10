#include "DesnaZagrada.h"

char DesnaZagrada::GetOzn() const {
	return ')';
}

string DesnaZagrada::GetNatpis() const {
	return ")";
}

DesnaZagrada * DesnaZagrada::Copy() const {
	return new DesnaZagrada(*this);
}
