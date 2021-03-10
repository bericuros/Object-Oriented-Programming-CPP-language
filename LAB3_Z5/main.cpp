#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "Destinacija.h"
#include "Smestaj.h"
#include "Prevoz.h"
#include "Datum.h"
#include "Aranzman.h"

int main() {

	Destinacija d1("A", "B");
	d1.Mark(3);
	d1.Mark(5);
	d1.Mark(1);
	d1.Mark(2);
	d1.Mark(10);
	d1.Mark(5);
	d1.Mark(5);
	d1.Mark(4);
	d1.Mark(2);
	d1.Mark(5);

	Smestaj s1(d1, Smestaj::HOTEL, "Galaxy", 5, 1302.4);
	Prevoz p1(d1, 5000);

	Aranzman a1(d1, Datum(9, 1, 2021), Datum(16, 1, 2021));

	a1.SetSmes(new Smestaj(s1));
	a1.SetPrev(new Prevoz(p1));

	cout << a1;

	return 0;
}