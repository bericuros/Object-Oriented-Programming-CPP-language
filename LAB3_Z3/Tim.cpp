#include "Tim.h"

Tim::Tim(string aNaziv, int aKap) : naziv(aNaziv), kap(aKap) {
	num = 0;
	igr = new Igrac*[kap];
	for (int i = 0; i < kap; i++) {
		igr[i] = nullptr;
	}
}

Tim::Tim(const Tim &t) {
	Copy(t);
}

Tim::Tim(Tim &&t) {
	Move(t);
}

Tim::~Tim() {
	Clear();
}

Tim & Tim::operator=(const Tim &t) {
	if (this != &t) {
		Clear();
		Copy(t);
	}
	return *this;
}

Tim & Tim::operator=(Tim &&t) {
	if (this != &t) {
		Clear();
		Move(t);
	}
	return *this;
}

Igrac * Tim::operator[](int idx) const {
	return igr[idx];
}

Tim & Tim::Add(Igrac *ig, int idx) {
	if (igr[idx]) {
		delete igr[idx];
		num--;
	}
	igr[idx] = ig;
	num++;
	return *this;
}

int Tim::GetNum() const {
	return num;
}

int Tim::CalcAvg() const {
	int sum = 0;
	for (int i = 0; i < kap; i++) {
		if (igr[i]) {
			sum += igr[i]->GetVred();
		}
	}
	if (num) {
		sum /= num;
	}
	return sum;
}

void Tim::Print(ostream &os) const {
	os << "[";
	for (int i = 0; i < kap; i++) {
		if (igr[i]) {
			os << *igr[i];
		}
		else {
			os << " / ";
		}
		os << (i != kap - 1 ? ", " : "]");
	}
}

void Tim::Copy(const Tim &t) {
	naziv = t.naziv;
	kap = t.kap;
	num = t.num;
	igr = new Igrac*[kap];
	for (int i = 0; i < kap; i++) {
		igr[i] = nullptr;
		if (t[i]) {
			igr[i] = new Igrac(*t[i]);
		}
	}
}

void Tim::Move(Tim &t) {
	naziv = t.naziv;
	kap = t.kap;
	num = t.num;
	igr = t.igr;
	t.kap = 0;
	t.igr = nullptr;
}

void Tim::Clear() {
	for (int i = 0; i < kap; i++) {
		delete igr[i];
	}
	delete[]igr;
	igr = nullptr;
	kap = num = 0;
}

bool operator==(const Tim &t1, const Tim &t2) {
	if (t1.naziv != t2.naziv || t1.kap != t2.kap || t1.num != t2.num) {
		return false;
	}
	for (int i = 0; i < t1.kap; i++) {
		if (!t1[i] && !t2[i]) {
			continue;
		}
		if (!t1[i] && t2[i] || t1[i] && !t2[i]) {
			return false;
		}
		if (!(*t1[i] == *t2[i])) {
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream &os, const Tim &t) {
	os << t.naziv;
	t.Print(os);
	return os;
}
