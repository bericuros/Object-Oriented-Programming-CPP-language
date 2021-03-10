#pragma once

#include <exception>
using namespace std;

class ENoCurr : public exception {
public:
	const char * what() const override {
		return "*** Ne postoji tekuci pokazivac! ***";
	}
};

class ENoOkayIng : public exception {
public:
	const char * what() const override {
		return "*** Sastojak nije adekvatan! ***";
	}
};