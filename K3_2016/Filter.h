#pragma once

#include "Element.h"
#include "Slika.h"
#include "Galerija.h"

class Filter {
public:
	virtual void Work(Element &) const = 0;
	void OnGalery(Galerija &) const;
protected:
private:
};

class Invertor : public Filter {
public:
	void Work(Element &) const override;
protected:
private:
};
