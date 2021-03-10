#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Datum.h"

class Osoba {
public:
	Osoba(string, string, const Datum &);
	Osoba(const Osoba &) = delete;

	Osoba & operator=(const Osoba &) = delete;
	friend ostream & operator<<(ostream &, const Osoba &);

	string GetIme() const;
	string GetJmbg() const;
	Datum GetDat() const;
protected:
private:
	string ime, jmbg;
	Datum dat;
};

