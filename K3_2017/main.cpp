#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "Lista.h"
#include "Sastojak.h"
#include "Jelo.h"
#include "Jelovnik.h"
#include "Generator.h"

int main() {
	Jelo* j1 = new Predjelo("Sendvic"),
		*j2 = new Glavno("Piletina sa sirom"),
			* j3 = new Dezert("Tufahije");
	j1->SetChange(10); j2->SetChange(20);
	try {
		j1->Add(*(new Neutralan("Hleb", 50)), 200);
		j1->Add(*(new Slan("Sunka", 500)), 150);
		j2->Add(*(new Slan("Belo meso", 800)), 300);
		j2->Add(*(new Neutralan("Zejtin", 200)), 100);
		j2->Add(*(new Slan("Sir", 400)), 100);
		j3->Add(*(new Sladak("Jabuke", 300)), 200);
		j3->Add(*(new Sladak("Secer", 150)), 100);
		j3->Add(*(new Neutralan("Orasi", 1500)), 100);
		Jelovnik j; j.Add(j1, 5).
			Add(j2, 3).Add(j3, 10);
		Generator g(j); g.Chose(21);
		cout << g << endl;
	}
	catch (...) {
		cout <<
			"Doslo je do greske!";
	}
	delete j1; delete j2; delete j3; return 0;
}