#include "Element.h"

ostream & operator<<(ostream &os, const Element &el) {
	return os << el.GetNatpis();
}

Element::~Element() {}