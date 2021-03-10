#pragma once

#include <exception>
using namespace std;

class EWrongColor : public exception {
public:
	const char * what() const override {
		return "*** Pogresna vrednost za boju! ***";
	}
};

class EWrongIndex : public exception {
public:
	const char * what() const override {
		return "*** Pogresna vrednost indeksa! ***";
	}
};