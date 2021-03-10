#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "NutVred.h"

class Namirnica {
public:
	Namirnica(string, const NutVred &, bool);

	friend bool operator==(const Namirnica &, const Namirnica &);
	friend ostream & operator<<(ostream &, const Namirnica &);

	string GetNaziv() const;
	NutVred GetNv() const;
	bool GetPosna() const;
protected:
private:
	string naziv;
	NutVred nv;
	bool posna;
};

