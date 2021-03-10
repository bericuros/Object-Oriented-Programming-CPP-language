#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "Boja.h"
#include "Element.h"
#include "Slika.h"
#include "Lista.h"
#include "Galerija.h"
#include "Filter.h"

int main() {
	try {
		Slika s1(1, 1); CrnoBela cb(1, 1);
		Siva s(1, 1); Galerija g;
		s1.ChangeColor(0, 0, Boja(50, 20, 200));
		cb.ChangeColor(0, 0, Boja(0, 0, 0));
		s.ChangeColor(0, 0, Boja(100, 100, 100));
		g.Add(s1).Add(cb).Add(s);
		cout << g; Invertor i; i.OnGalery(g);
		cout << g;
	}
	catch (exception e) {
		cout << e.what() << "\n";
	}
	return 0;
}