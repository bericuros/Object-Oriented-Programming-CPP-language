#pragma once

#include <iostream>
using namespace std;

class Datum {
public:
	Datum(int, int);

	friend bool operator==(const Datum &, const Datum &);
	friend bool operator!=(const Datum &, const Datum &);
	friend ostream & operator<<(ostream &, const Datum &);
protected:
private:
	int mes, god;
};