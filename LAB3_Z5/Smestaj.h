#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Izuzeci.h"
#include "Destinacija.h"

class Smestaj {
public:
	enum Tip{HOTEL, APARTMAN};
	Smestaj(const Destinacija &, Tip, string, int, double);

	friend ostream & operator<<(ostream &, const Smestaj &);

	Destinacija GetDest() const;
	Smestaj::Tip GetTip() const;
	string GetNaziv() const;
	int GetBrzv() const;
	double GetCena() const;
protected:
private:
	Destinacija dest;
	Tip tip;
	string naziv;
	int brzv;
	double cena;
};

