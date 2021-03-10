#pragma once

#include <iostream>
#include <string>
using namespace std;

class Sastojak {
public:
	enum Type { SLAN, SLAD, NEUT };

	Sastojak(string, double);

	friend ostream & operator<<(ostream &, const Sastojak &);

	virtual Sastojak::Type GetType() const = 0;
	double GetPrice(int) const;
protected:
private:
	string name;
	double unit;
};

class Slan : public Sastojak {
public:
	Slan(string, double);

	Sastojak::Type GetType() const override;
protected:
private:
};

class Sladak : public Sastojak {
public:
	Sladak(string, double);

	Sastojak::Type GetType() const override;
protected:
private:
};

class Neutralan : public Sastojak {
public:
	Neutralan(string, double);

	Sastojak::Type GetType() const override;
protected:
private:
};