#pragma once

#include <exception>
using namespace std;

class GZvezdice : public exception {
public:
	const char * what() const  override {
		return "*** Pogresan broj zvezdica! ***";
	}
};

class GPogresanDatum : public exception {
public:
	const char * what() const  override {
		return "*** Neispravan datum! ***";
	}
};

class GPogDest : public exception {
public:
	const char * what() const  override {
		return "*** Smestaj i/ili prevoz imaju pogresnu destinaciju! ***";
	}
};

class GSmesPrev : public exception {
public:
	const char * what() const  override {
		return "*** Smestaj i/ili prevoz nisu dodeljeni aranzmanu! ***";
	}
};