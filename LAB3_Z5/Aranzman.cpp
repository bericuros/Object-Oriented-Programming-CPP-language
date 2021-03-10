#include "Aranzman.h"

Aranzman::Aranzman(const Destinacija &aDest, const Datum &aPoc, const Datum &aKraj) :
	dest(aDest), poc(aPoc), kraj(aKraj) {
	smes = nullptr;
	prev = nullptr;
}

Aranzman::Aranzman(const Aranzman &a) : dest(a.dest), poc(a.poc), kraj(a.kraj) {
	Copy(a);
}

Aranzman::Aranzman(Aranzman &&a) : dest(a.dest), poc(a.poc), kraj(a.kraj) {
	Move(a);
}

Aranzman::~Aranzman() {
	Clear();
}

Aranzman & Aranzman::operator=(const Aranzman &a) {
	if (this != &a) {
		Clear();
		Copy(a);
	}
	return *this;
}

Aranzman & Aranzman::operator=(Aranzman &&a) {
	if (this != &a) {
		Clear();
		Move(a);
	}
	return *this;
}

Destinacija Aranzman::GetDest() const {
	return dest;
}

Datum Aranzman::GetPoc() const {
	return poc;
}

Datum Aranzman::GetKraj() const {
	return kraj;
}

int Aranzman::GetDuration() const {
	return kraj - poc;
}

double Aranzman::GetPrice() const {
	if (!smes || !prev) {
		throw GSmesPrev();
	}
	return smes->GetCena() + prev->GetCena();
}

void Aranzman::SetSmes(Smestaj *aSmes) {
	if (aSmes->GetDest() != dest) {
		throw GPogDest();
	}
	smes = aSmes;
}

void Aranzman::SetPrev(Prevoz *aPrev) {
	if (aPrev->GetDest() != dest) {
		throw GPogDest();
	}
	prev = aPrev;
}

void Aranzman::Copy(const Aranzman &a) {
	dest = a.dest;
	poc = a.poc;
	kraj = a.kraj;
	smes = new Smestaj(*a.smes);
	prev = new Prevoz(*a.prev);
}

void Aranzman::Move(Aranzman &a) {
	dest = a.dest;
	poc = a.poc;
	kraj = a.kraj;
	smes = a.smes;
	prev = a.prev;
	a.smes = nullptr;
	a.prev = nullptr;
}

void Aranzman::Clear() {
	delete smes;
	smes = nullptr;
	delete prev;
	prev = nullptr;
}

ostream & operator<<(ostream &os, const Aranzman &a) {
	return os << a.dest << "\n" << *a.smes << "\n" << a.GetPrice() << "\n";
}
