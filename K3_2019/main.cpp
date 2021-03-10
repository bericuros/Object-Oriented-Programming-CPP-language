#include <iostream>
using namespace std;

#include "Kompozicija.h"

int main() {
	try {
		Razlomak osm(1, 8), cet(1, 4), pol(1, 2);
		Nota mi_2(2, Nota::MI, pol),
			re_4(2, Nota::RE, cet),
			do_8(2, Nota::DO, osm),
			la_8(2, Nota::LA, osm),
			sol_4(2, Nota::SOL, cet),
			si_2(2, Nota::SI, pol);
		Pauza p_2(pol), p_4(cet), p_8(osm);
		Takt t1(pol), t2(pol), t3(pol);
		t1.Add(re_4).SetOver();
		t2.Add(mi_2).SetOver();
		t3.Add(la_8).Add(p_8).Add(sol_4).SetOver();
		Kompozicija k;
		cout << k.Add(t1).Add(t2).Add(t3);
	}
	catch (exception &e) {
		cout << endl << e.what();
	}
}