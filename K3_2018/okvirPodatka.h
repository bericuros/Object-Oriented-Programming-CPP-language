#pragma once

#include"adresa.h"

class OkvirPodatka {
public:
	OkvirPodatka(const Adresa &, const Adresa &, unsigned char *, int);
	OkvirPodatka(const OkvirPodatka &) = delete;
	
	OkvirPodatka & operator=(const OkvirPodatka &) = delete;
	friend ostream & operator<<(ostream &, const OkvirPodatka &);

	Adresa GetSrc() const;
	Adresa GetDst() const;
	unsigned char * GetCon() const;
	int GetSize() const;
protected:
private:
	Adresa src, dst;
	unsigned char *con;
	int size;
};

OkvirPodatka::OkvirPodatka(const Adresa &aSrc, const Adresa &aDst, unsigned char *aCon, int aSize) :
	src(aSrc), dst(aDst), con(aCon), size(aSize) {}

Adresa OkvirPodatka::GetSrc() const {
	return src;
}

Adresa OkvirPodatka::GetDst() const {
	return dst;
}

unsigned char * OkvirPodatka::GetCon() const {
	return con;
}

int OkvirPodatka::GetSize() const {
	return size;
}

ostream & operator<<(ostream &os, const OkvirPodatka &op) {
	return os << "Frame[src: " << op.src << ", dst: " << op.dst << ", content: " << op.con << "]";
}


