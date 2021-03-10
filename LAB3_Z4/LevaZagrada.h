#pragma once

#include "Element.h"

class LevaZagrada : public Element {
public:
	char GetOzn() const override;
	string GetNatpis() const override;
	LevaZagrada * Copy() const override;
protected:
private:
};

