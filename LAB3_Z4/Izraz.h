#pragma once

#include "Lista.h"
#include "Element.h"

class Izraz : public Lista<Element> {
public:
	virtual ~Izraz();
	virtual Izraz * Copy() const;
protected:
private:
};

