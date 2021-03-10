#include "Slika.h"

Slika::Slika(int aRow, int aCol, const Boja & aBoja) : row(aRow), col(aCol) {
	elem = new Element *[row];
	for (int i = 0; i < row; i++) {
		elem[i] = new Element[col];
		for (int j = 0; j < col; j++) {
			elem[i][j].ChangeColor(aBoja);
		}
	}
}

Slika::Slika(const Slika &sl) {
	Copy(sl);
}

Slika::Slika(Slika &&sl) {
	Move(sl);
}

Slika::~Slika() {
	Clear();
}

Slika & Slika::operator=(const Slika &sl) {
	if (this != &sl) {
		Clear();
		Copy(sl);
	}
	return *this;
}

Slika & Slika::operator=(Slika &&sl) {
	if (this != &sl) {
		Clear();
		Move(sl);
	}
	return *this;
}

Element & Slika::operator()(int aRow, int aCol) {
	if (aRow < 0 || aRow >= row || aCol < 0 || aCol >= col) {
		throw EWrongIndex();
	}
	return elem[aRow][aCol];
}

const Element & Slika::operator()(int aRow, int aCol) const {
	return const_cast<Slika &>(*this)(aRow, aCol);
}

int Slika::GetRow() const {
	return row;
}

int Slika::GetCol() const {
	return col;
}

void Slika::ChangeColor(int aRow, int aCol, const Boja &aBoja) {
	elem[aRow][aCol].ChangeColor(aBoja);
}

void Slika::Copy(const Slika &sl) {
	row = sl.row;
	col = sl.col;
	elem = new Element *[row];
	for (int i = 0; i < row; i++) {
		elem[i] = new Element[col];
		for (int j = 0; j < col; j++) {
			elem[i][j] = sl(i, j);
		}
	}
}

void Slika::Move(Slika &sl) {
	row = sl.row;
	col = sl.col;
	elem = sl.elem;
	sl.row = sl.col = 0;
	sl.elem = nullptr;
}

void Slika::Clear() {
	for (int i = 0; i < row; i++) {
		delete[]elem[i];
	}
	delete[]elem;
	row = col = 0;
	elem = nullptr;
}

ostream & operator<<(ostream &os, const Slika &sl) {
	for (int i = 0; i < sl.row; i++) {
		for (int j = 0; j < sl.col; j++) {
			os << sl(i, j) << " ";
		}
		os << "\n";
	}
	return os;
}

CrnoBela::CrnoBela(int aRow, int aCol, const Boja & aBoja) : Slika(aRow, aCol, aBoja) {
	if (aBoja == Boja(0, 0, 0) || aBoja == Boja(255, 255, 255)) {}
	else {
		throw EWrongColor();
	}
}

void CrnoBela::ChangeColor(int aRow, int aCol, const Boja &aBoja) {
	if (aBoja == Boja(0, 0, 0) || aBoja == Boja(255, 255, 255)) {
		Slika::ChangeColor(aRow, aCol, aBoja);
	}
	else {
		throw EWrongColor();
	}
}


Siva::Siva(int aRow, int aCol, const Boja & aBoja) : Slika(aRow, aCol, aBoja) {
	if (aBoja.GetRed() == aBoja.GetGre() && aBoja.GetGre() == aBoja.GetBlu()) {}
	else {
		throw EWrongColor();
	}
}

void Siva::ChangeColor(int aRow, int aCol, const Boja &aBoja) {
	if (aBoja.GetRed() == aBoja.GetGre() && aBoja.GetGre() == aBoja.GetBlu()) {
		Slika::ChangeColor(aRow, aCol, aBoja);
	}
	else {
		throw EWrongColor();
	}
}
