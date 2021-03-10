#pragma once

#include<iostream>
using namespace std;

class Adresa {
public:
	Adresa() = default;
	Adresa(const unsigned char *);

	friend bool operator==(const Adresa &, const Adresa &);
	friend ostream & operator<<(ostream &, const Adresa &);
protected:
private:
	unsigned char arr[6] = {0, 0, 0, 0, 0, 0};
};

Adresa::Adresa(const unsigned char *aArr) {
	for (int i = 0; i < 6; i++) {
		arr[i] = aArr[i];
	}
}

bool operator==(const Adresa &a1, const Adresa & a2) {
	for (int i = 0; i < 6; i++) {
		if (a1.arr[i] != a2.arr[i]) {
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream &os, const Adresa &a) {
	for (int i = 0; i < 5; i++) {
		os << hex << (int)a.arr[i] << ':';
	}
	return os << hex << (int)a.arr[5];
}