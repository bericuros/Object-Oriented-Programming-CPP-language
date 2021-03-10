#pragma once

#include <exception>
using namespace std;

class EFullColl : public exception {
public:
	const char * what() const override {
		return "*** Zbirka je puna! ***";
	}
};

class EEmptyColl : public exception {
public:
	const char * what() const override {
		return "*** Zbirka je prazna! ***";
	}
};