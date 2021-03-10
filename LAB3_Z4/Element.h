#pragma once

#include <iostream>
#include <string>
using namespace std;

class Element {
public:
	virtual ~Element();

	friend ostream & operator<<(ostream &, const Element &);

	virtual char GetOzn() const = 0;
	virtual string GetNatpis() const = 0;
	virtual Element * Copy() const = 0;
protected:
private:
};

