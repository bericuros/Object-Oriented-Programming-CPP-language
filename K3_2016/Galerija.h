#pragma once

#include "Slika.h"
#include "Lista.h"

class Galerija : public Lista<Slika> {
public:
	friend class Filter;
	Galerija() : Lista<Slika>() {}
};

