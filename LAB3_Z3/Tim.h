#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "Igrac.h"

class Tim {
public:
	Tim(string, int);
	Tim(const Tim &);
	Tim(Tim &&);
	~Tim();

	Tim & operator=(const Tim &);
	Tim & operator=(Tim &&);
	Igrac * operator[](int) const;
	friend bool operator==(const Tim &, const Tim &);
	friend ostream & operator<<(ostream &, const Tim &);

	virtual Tim & Add(Igrac *, int);

	int GetNum() const;
	int CalcAvg() const;
protected:
	virtual void Print(ostream &) const;
	void Copy(const Tim &);
	void Move(Tim &);
	void Clear();
private:
	string naziv;
	int kap, num;
	Igrac **igr;
};

