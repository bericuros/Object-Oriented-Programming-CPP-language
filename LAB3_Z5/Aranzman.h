#pragma once

#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "Destinacija.h"
#include "Smestaj.h"
#include "Prevoz.h"
#include "Datum.h"

class Aranzman {
public:
	Aranzman(const Destinacija &, const Datum &, const Datum &);
	Aranzman(const Aranzman &);
	Aranzman(Aranzman &&);
	~Aranzman();

	Aranzman & operator=(const Aranzman &);
	Aranzman & operator=(Aranzman &&);
	friend ostream & operator<<(ostream &, const Aranzman &);

	Destinacija GetDest() const;
	Datum GetPoc() const;
	Datum GetKraj() const;
	int GetDuration() const;
	double GetPrice() const;

	void SetSmes(Smestaj *);
	void SetPrev(Prevoz *);
protected:
private:
	void Copy(const Aranzman &);
	void Move(Aranzman &);
	void Clear();

	Destinacija dest;
	Datum poc, kraj;
	Smestaj *smes;
	Prevoz *prev;
};

