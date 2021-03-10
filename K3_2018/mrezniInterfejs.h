#pragma once

#include"adresa.h"
#include"okvirPodatka.h"
#include"mrezniUredjaj.h"

class MrezniInterfejs {
public:
	MrezniInterfejs(MrezniUredjaj *);
	MrezniInterfejs(const MrezniInterfejs &) = delete;

	MrezniInterfejs(MrezniInterfejs &&) = delete;

	Adresa GetAdr() const;
	MrezniInterfejs * GetItf() const;

	void SetAdr(const Adresa &);
	void SetItf(MrezniInterfejs *);

	void Send(const OkvirPodatka &);
	void Accept(const OkvirPodatka &);
protected:
private:
	Adresa adr;
	MrezniInterfejs *itf;
	MrezniUredjaj *dev;
};

MrezniInterfejs::MrezniInterfejs(MrezniUredjaj * aDev) : dev(aDev) {
	itf = nullptr;
}

Adresa MrezniInterfejs::GetAdr() const {
	return adr;
}

MrezniInterfejs * MrezniInterfejs::GetItf() const {
	return itf;
}

void MrezniInterfejs::SetAdr(const Adresa &aAdr) {
	adr = aAdr;
}

void MrezniInterfejs::SetItf(MrezniInterfejs *aItf) {
	itf = aItf;
}

void MrezniInterfejs::Send(const OkvirPodatka &op) {
	itf->Accept(op);
}

void MrezniInterfejs::Accept(const OkvirPodatka &op) {
	dev->Work(op, this);
}