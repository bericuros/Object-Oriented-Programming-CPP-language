#pragma once

#include "Izuzeci.h"
#include "Boja.h"
#include "Element.h"

class Slika {
public:
	Slika(int aRow = 3, int aCol = 4, const Boja &aBoja = { 255, 255, 255 });
	Slika(const Slika &);
	Slika(Slika &&);
	~Slika();

	Slika & operator=(const Slika &);
	Slika & operator=(Slika &&);
	Element & operator()(int, int);
	const Element & operator()(int, int) const;
	friend ostream & operator<<(ostream &, const Slika &);

	int GetRow() const;
	int GetCol() const;

	virtual void ChangeColor(int, int, const Boja &);
protected:
	void Copy(const Slika &);
	void Move(Slika &);
	void Clear();

	int row, col;
private:
	Element **elem;
};

class CrnoBela : public Slika {
public:
	CrnoBela(int aRow = 3, int aCol = 4, const Boja &aBoja = { 255, 255, 255 });

	void ChangeColor(int, int, const Boja &) override;
protected:
private:
};

class Siva : public Slika {
public:
	Siva(int aRow = 3, int aCol = 4, const Boja &aBoja = { 255, 255, 255 });

	void ChangeColor(int, int, const Boja &) override;
protected:
private:
};