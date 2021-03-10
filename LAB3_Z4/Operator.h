#pragma once

#include "Element.h"

class Operator : public Element {
public:
	virtual ~Operator();

	friend bool operator>(const Operator &, const Operator &);

	char GetOzn() const override;
	virtual int GetPrio() const = 0;
protected:
private:
};

