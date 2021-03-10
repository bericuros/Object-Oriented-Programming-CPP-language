#pragma once

#include <iostream>
using namespace std;

class NutVred {
public:
	NutVred(double, double, double);

	friend NutVred operator+(const NutVred &, const NutVred &);
	friend ostream & operator<<(ostream &, const NutVred &);

	double GetUgh() const;
	double GetMas() const;
	double GetPro() const;
	double CalcCal() const;
protected:
private:
	double ugh, mas, pro;
};

