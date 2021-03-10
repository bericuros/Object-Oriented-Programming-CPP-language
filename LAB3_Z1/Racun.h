#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Osoba.h"

class Racun {
public:
	Racun(Osoba *, string);
	Racun(const Racun &) = delete;

	Racun & operator=(const Racun &) = delete;
	Racun & operator+=(double);
	friend ostream & operator<<(ostream &, const Racun &);

	Osoba * GetOso() const;
	string GetBroj() const;
	double GetIznos() const;
	virtual string GetOzn() const = 0;

	bool Transfer(double, Racun &);
protected:
private:
	Osoba *oso;
	string broj;
	double iznos;
};

