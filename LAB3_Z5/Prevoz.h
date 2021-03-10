#pragma once

#include "Destinacija.h"

class Prevoz {
public:
	Prevoz(const Destinacija &, double);
	virtual ~Prevoz();

	Destinacija GetDest() const;
	double GetCena() const;
protected:
private:
	Destinacija dest;
	double karta;
};

