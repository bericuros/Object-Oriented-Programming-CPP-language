#pragma once

#include "Izuzeci.h"

class Boja {
public:
	Boja(int, int, int);

	friend bool operator==(const Boja &, const Boja &);

	int GetRed() const;
	int GetGre() const;
	int GetBlu() const;
protected:
private:
	int red, gre, blu;
};

