#pragma once

#include "Karta.h"
#include "Zbirka.h"

template<int cap = 10>
class Aparat {
public:
	Aparat() = default;
	Aparat(const Aparat &) = delete;

	Aparat & operator=(const Aparat &) = delete;
	Aparat & operator+=(Karta *);
	void IsValid(double, const Datum &) const;
protected:
private:
	Zbirka<Karta, cap> cards;
};

template<int cap>
inline Aparat<cap> & Aparat<cap>::operator+=(Karta *k) {
	cards << k;
	return *this;
}

template<int cap>
inline void Aparat<cap>::IsValid(double aPrice, const Datum &aDate) const {
	while (cards.GetSize()) {
		Karta *k;
		cards >> k;
		bool valid = k->IsValid(aPrice, aDate);
		cout << "Karta " << *k << " ";
		if (!valid) {
			cout << "nije ";
		}
		cout << "valjana.\n";
	}
}
