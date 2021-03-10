#include "LevaZagrada.h"

char LevaZagrada::GetOzn() const {
	return '(';
}

string LevaZagrada::GetNatpis() const {
	return "(";
}

LevaZagrada * LevaZagrada::Copy() const {
	return new LevaZagrada(*this);
}
