#pragma once

#include <iostream>
using namespace std;

#include "Izuzeci.h"

class Datum {
public:
	Datum(int, int, int);

	friend int operator-(const Datum &, const Datum &);
	friend ostream & operator<<(ostream &, const Datum &);

	int GetDan() const;
	int GetMes() const;
	int GetGod() const;
protected:
private:
	static int days[13];
	int DaysMonth(int, int) const;
	int dan, mes, god;
};

