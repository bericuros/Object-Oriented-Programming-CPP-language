#pragma once

#include <iostream>
using namespace std;

class Datum {
public:
	Datum(int aDan = 1, int aMes = 1, int aGod = 2021);

	friend bool operator==(const Datum &, const Datum &);
	friend ostream & operator<<(ostream &, const Datum &);
protected:
private:
	int dan, mes, god;
};

