#include <iostream>
#include <string>
using namespace std;

#include "Datum.h"
#include "Osoba.h"
#include "Racun.h"
#include "Dinarski.h"

int main() {

	Osoba o1("Milan", "0123456789", Datum(5, 5, 1995));
	Osoba o2("Milica", "1029384756", Datum(1, 12, 1990));
	Osoba o3("Emilija", "1234554321", Datum(26, 4, 1989));
	Osoba o4("Novak", "8383838383", Datum(6, 1, 2001));
	Osoba o5("Natasa", "5555555555", Datum(19, 6, 1990));

	cout << o1 << endl;
	cout << o2 << endl;
	cout << o3 << endl;
	cout << o4 << endl;
	cout << o5 << endl;

	Dinarski d1(&o1, "1");
	Dinarski d2(&o2, "2");
	Dinarski d3(&o3, "3");
	Dinarski d4(&o4, "4");
	Dinarski d5(&o5, "5");

	d1 += 500;
	d2 += 100;
	d3 += 1500;
	d4 += 1000;
	d5 += 230;
	d3 += 50;

	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << d4 << endl;
	cout << d5 << endl;

	cout << d3.Transfer(400, d2) << endl;
	cout << d5.Transfer(250, d1) << endl;
	cout << d3.Transfer(1200, d1) << endl;

	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << d4 << endl;
	cout << d5 << endl;

	return 0;
}