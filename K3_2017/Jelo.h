#pragma once

#include "Sastojak.h"
#include "Lista.h"

class Jelo {
public:
	Jelo(string);
	~Jelo();

	friend ostream & operator<<(ostream &, const Jelo &);

	virtual double GetPrice() const;
	virtual bool Okay(Sastojak &) const = 0;
	virtual char GetType() const = 0;

	Jelo & Add(Sastojak &, int);

	void SetChange(double);
	void SetHour(int);
protected:
	double change;
	int hour;
private:
	string name;
	Lista<Sastojak *> list;
};

class Predjelo : public Jelo {
public:
	Predjelo(string);

	double GetPrice() const override;
	bool Okay(Sastojak &) const override;
	char GetType() const override;
protected:
private:
};

class Glavno : public Jelo {
public:
	Glavno(string);

	double GetPrice() const override;
	bool Okay(Sastojak &) const override;
	char GetType() const override;
protected:
private:
};

class Dezert : public Jelo {
public:
	Dezert(string);

	bool Okay(Sastojak &) const override;
	char GetType() const override;
protected:
private:
};