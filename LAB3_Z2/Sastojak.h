#pragma once

#include <iostream>
using namespace std;

#include "Namirnica.h"

class Sastojak {
public:
	Sastojak(const Namirnica &, double);

	friend ostream & operator<<(ostream &, const Sastojak &);

	Namirnica GetNam() const;
	double GetKol() const;

	NutVred CalcNv() const;
	double CalcCal() const;
protected:
private:
	Namirnica nam;
	double kol;
};

