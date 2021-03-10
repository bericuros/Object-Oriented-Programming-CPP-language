#pragma once

#include <iostream>
using namespace std;

#include "Boja.h"

class Element {
public:
	Element(const Boja &aCol = { 255, 255, 255 });

	friend ostream & operator<<(ostream &, const Element &);

	Boja GetColor() const;

	void ChangeColor(const Boja &);
protected:
private:
	Boja col;
};

