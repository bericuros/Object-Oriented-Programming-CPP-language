#pragma once

#include <iostream>
#include <string>
using namespace std;

class Destinacija {
public:
	Destinacija(string, string);

	friend bool operator>(const Destinacija &, const Destinacija &);
	friend bool operator!=(const Destinacija &, const Destinacija &);
	friend ostream & operator<<(ostream &, const Destinacija &);

	string GetNaziv() const;
	string GetOpis() const;
	double GetMark() const;

	void Mark(unsigned char);
protected:
private:
	string naziv, opis;
	double mark;
	int num;
};

