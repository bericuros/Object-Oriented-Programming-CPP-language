#pragma once

#include <string>
using namespace std;

#include "Osoba.h"
#include "Racun.h"

class Dinarski : public Racun {
public:
	Dinarski(Osoba *, string);

	string GetOzn() const override;
protected:
private:
};

