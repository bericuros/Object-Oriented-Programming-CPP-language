#pragma once

#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "Igrac.h"
#include "Tim.h"
#include "Privilegovan.h"
#include "Par.h"

class Mec {
public:
	enum Ishod{POBEDA_DOMACIN, NERESENO, POBEDA_GOST};
	Mec(Tim *, Tim *);

	friend ostream & operator<<(ostream &, const Mec &);

	Par<Tim> GetPar() const;
	Par<int> GetPoeni() const;
	bool GetOdigran() const;

	void Play();
protected:
private:
	Par<Tim> par;
	Par<int> poeni;
	Ishod ishod;
	bool odigran;
};

