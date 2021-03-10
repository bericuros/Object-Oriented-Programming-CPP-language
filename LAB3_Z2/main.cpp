#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "NutVred.h"
#include "Namirnica.h"
#include "Sastojak.h"
#include "Lista.h"

int main() {

	Namirnica n1("A", NutVred(30, 30, 10), 0);
	Namirnica n2("B", NutVred(70, 10, 2), 1);
	Namirnica n3("C", NutVred(20, 30, 20), 0);
	Namirnica n4("D", NutVred(30, 30, 15), 1);
	Namirnica n5("E", NutVred(5, 50, 20), 0);

	Sastojak s1(n1, 150);
	Sastojak s2(n2, 50);
	Sastojak s3(n3, 220);
	Sastojak s4(n4, 450);
	Sastojak s5(n5, 1000);

	Lista<Sastojak> l1;
	l1.Add(s1).Add(s2).Add(s3).Add(s4).Add(s5);

	for (l1.CurrHead(); l1.CurrExists(); l1.CurrNext()) {
		cout << l1.GetData() << "\n";
	}

	l1.Clear();

	return 0;
}