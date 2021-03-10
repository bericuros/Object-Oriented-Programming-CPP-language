#pragma once

#include <exception>
using namespace std;

class GNemaTekuci : public exception {
public:
	const char * what() const override {
		return "*** Ne postoji tekuci element! ***";
	}
};
