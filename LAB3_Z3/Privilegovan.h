#pragma once

#include <string>
using namespace std;

#include "Izuzeci.h"
#include "Tim.h"

class Privilegovan : public Tim {
public:
	Privilegovan(string, int, int);

	Privilegovan & Add(Igrac *, int) override;
protected:
private:
	void Print(ostream &) const override;

	int minVred;
};

