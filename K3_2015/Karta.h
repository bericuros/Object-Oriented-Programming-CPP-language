#pragma once

#include "Datum.h"
#include <iostream>
#include <string>
using namespace std;

class Karta {
public:
	Karta() = default;
	Karta(const Karta &) = delete;
	virtual ~Karta() {}

	Karta & operator=(const Karta &) = delete;
	friend ostream & operator<<(ostream &, const Karta &);

	virtual bool IsValid(double, const Datum &) = 0;
protected:
	virtual void Print(ostream &) const;
private:
	static int stId;
	int id = ++stId;
};

class Mesecna : public Karta {
public:
	Mesecna(string, int, int);

	bool IsValid(double, const Datum &) override;
	void Extend(int, int);
protected:
private:
	void Print(ostream &) const override;

	string owner;
	int god, mes;
};

class Pojedinacna : public Karta {
public:
	Pojedinacna(double aAmount = 50);

	bool IsValid(double, const Datum &) override;
	void Sup(double aBonus);
protected:
private:
	void Print(ostream &) const override;

	double amount;
};