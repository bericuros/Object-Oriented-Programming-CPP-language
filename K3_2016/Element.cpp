#include "Element.h"

Element::Element(const Boja & aCol) : col(aCol) {}

Boja Element::GetColor() const {
	return col;
}

void Element::ChangeColor(const Boja &aCol) {
	col = aCol;
}

ostream & operator<<(ostream &os, const Element &el) {
	return os << "(" << el.col.GetRed() << ", " << el.col.GetGre() << ", " << el.col.GetBlu() << ")";
}
