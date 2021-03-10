#pragma once

#include "Element.h"

class Operand : public Element {
public:
	Operand(string);

	char GetOzn() const override;
	string GetNatpis() const override;
	Operand * Copy() const override;
protected:
private:
	string natpis;
};

