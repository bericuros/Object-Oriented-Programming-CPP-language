#pragma once

#include "Element.h"

class DesnaZagrada : public Element {
public:
	char GetOzn() const override;
	string GetNatpis() const override;
	DesnaZagrada * Copy() const override;
protected:
private:
};

