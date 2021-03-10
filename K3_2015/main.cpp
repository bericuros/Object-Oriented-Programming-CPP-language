#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "Datum.h"
#include "Karta.h"
#include "Zbirka.h"
#include "Aparat.h"

int main() {
	try {
		Aparat<> a;
		Mesecna m1("Marko", 1, 2015);
		Mesecna m2("Petar", 12, 2014);
		Pojedinacna p1(100), p2;
		a += &m1; a += &m2;
		a += &p1; a += &p2;
		a.IsValid(75, Datum(2015, 1));
	}
	catch (exception e) {
		cout << e.what() << "\n";
	}
}