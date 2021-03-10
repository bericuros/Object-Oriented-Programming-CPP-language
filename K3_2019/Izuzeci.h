#pragma once

#include <exception>
using namespace std;

class ENoAdd : public exception {
public:
	const char * what() const override {
		return "*** Nije moguce dodati novi element! ***";
	}
};

class ENoElements : public exception {
public:
	const char * what() const override {
		return "*** Sekvenca je prazna! ***";
	}
};

class EInvalidIndex : public exception {
public:
	const char * what() const override {
		return "*** Pogresna vrednost indeksa! ***";
	}
};

class EFinalized : public exception {
public:
	const char * what() const override {
		return "*** Takt je zavrsen! ***";
	}
};

class ENotEqualLength: public exception {
public:
	const char * what() const override {
		return "*** Nejednake duzine! ***";
	}
};

class ENotFinalized : public exception {
public:
	const char * what() const override {
		return "*** Takt nije zavrsen! ***";
	}
};