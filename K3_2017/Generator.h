#pragma once

#include "Jelovnik.h"

class Generator {
public:
	Generator(Jelovnik &);

	friend ostream & operator<<(ostream &, const Generator &);

	void Chose(int);
protected:
private:
	Jelovnik *menu;
	Jelo *dish[3];
	double price;
};

