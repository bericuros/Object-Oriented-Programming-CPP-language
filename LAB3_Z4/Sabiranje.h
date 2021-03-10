#pragma once

#include "Operator.h"

class Sabiranje : public Operator {
public:
	string GetNatpis() const override;
	int GetPrio() const override;
	Sabiranje * Copy() const override;
protected:
private:
};
