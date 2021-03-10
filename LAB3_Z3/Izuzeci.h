#pragma once

#include <exception>
using namespace std;

class GMalaVred : public exception {
public:
	const char * what() const override {
		return "*** Vrednost igraca je premala! ***";
	}
};

class GNeodigranMec: public exception {
public:
	const char * what() const override {
		return "*** Mec jos nije odigran! ***";
	}
};