#pragma once

#include <iostream>
#include <string>
using namespace std;

class Igrac {
public:
	Igrac(string aIme, int aVred = 1000);

	friend bool operator==(const Igrac &, const Igrac &);
	friend ostream & operator<<(ostream &, const Igrac &);

	string GetIme() const;
	int GetVred() const;

	void Incr(double);
	void Decr(double);
protected:
private:
	string ime;
	int vred;
};

