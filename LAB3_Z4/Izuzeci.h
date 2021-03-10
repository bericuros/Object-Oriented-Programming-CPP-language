#pragma once

#include <exception>
using namespace std;

class GPrazna : public exception {
public:
	const char * what() const override {
		return "*** Lista je prazna! ***";
	}
};

class GPostfiks: public exception {
public:
	const char * what() const override {
		return "*** Izraz je neispravan! ***";
	}
};