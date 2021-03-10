#include "Jelo.h"

Jelo::Jelo(string aName) : name(aName) {
	change = 0;
	hour = 0;
}

Jelo::~Jelo() {
	for (list.CurrHead(); list.CurrExists(); list.CurrStep()) {
		delete list.GetData();
	}
}

double Jelo::GetPrice() const {
	double sum = 0;
	for (list.CurrHead(); list.CurrExists(); list.CurrStep()) {
		sum += list.GetData()->GetPrice(list.GetInfo());
	}
	return sum;
}

Jelo & Jelo::Add(Sastojak &s, int a) {
	if (!Okay(s)) {
		throw ENoOkayIng();
	}
	list.Add(&s, a);
	return *this;
}

void Jelo::SetChange(double aChange) {
	change = aChange;
}

void Jelo::SetHour(int aHour) {
	hour = aHour;
}

ostream & operator<<(ostream &os, const Jelo &j) {
	os << j.name << ":" << j.GetPrice() << "\n";
	for (j.list.CurrHead(); j.list.CurrExists(); j.list.CurrStep()) {
		os << *j.list.GetData() << ":" << j.list.GetInfo() << "\n";
	}
	return os;
}

Predjelo::Predjelo(string aName) : Jelo(aName) {}

double Predjelo::GetPrice() const {
	if (hour >= 9 && hour <= 12) {
		return Jelo::GetPrice() * (100.0 - change) / 100;
	}
	return Jelo::GetPrice();
}

bool Predjelo::Okay(Sastojak &s) const {
	if (s.GetType() == Sastojak::SLAD) {
		return false;
	}
	return true;
}

char Predjelo::GetType() const {
	return 'P';
}

Glavno::Glavno(string aName) : Jelo(aName) {}

double Glavno::GetPrice() const {
	if (hour >= 20 && hour <= 23) {
		return Jelo::GetPrice() * (100.0 + change) / 100;
	}
	return Jelo::GetPrice();
}

bool Glavno::Okay(Sastojak &s) const {
	if (s.GetType() == Sastojak::SLAD) {
		return false;
	}
	return true;
}

char Glavno::GetType() const {
	return 'G';
}

Dezert::Dezert(string aName) : Jelo(aName) {}

bool Dezert::Okay(Sastojak &s) const {
	if (s.GetType() == Sastojak::SLAN) {
		return false;
	}
	return true;
}

char Dezert::GetType() const {
	return 'D';
}
