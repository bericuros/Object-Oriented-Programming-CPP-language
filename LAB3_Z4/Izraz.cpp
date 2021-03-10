#include "Izraz.h"

Izraz::~Izraz() {}

Izraz * Izraz::Copy() const {
	return new Izraz(*this);
}
