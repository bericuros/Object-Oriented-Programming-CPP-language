#pragma once

#include "Znak.h"

class Pauza : public Znak {
public:
	Pauza(Razlomak);

	string Desc() const override;
protected:
private:
};

Pauza::Pauza(Razlomak aDur) : Znak(aDur) {}

string Pauza::Desc() const {
	return "_";
}