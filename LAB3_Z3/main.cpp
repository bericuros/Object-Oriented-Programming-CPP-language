#include <iostream>
using namespace std;

#include "Izuzeci.h"
#include "Igrac.h"
#include "Tim.h"
#include "Privilegovan.h"
#include "Par.h"
#include "Mec.h"

int main() {

	Igrac *i1 = new Igrac("A", 500);
	Igrac *i2 = new Igrac("B", 400);
	Igrac *i3 = new Igrac("C", 1000);
	Igrac *i4 = new Igrac("D", 1000);
	Igrac *i5 = new Igrac("E", 500);
	Igrac *i6 = new Igrac("F", 200);

	i1->Decr(27.5);
	cout << *i1 << "\n";
	i1->Incr(50);
	cout << *i1 << "\n";
	i1->Incr(100);
	cout << *i1 << "\n";
	
	Tim t1("X", 11), t2("Y", 5);
	t1.Add(new Igrac(*i1), 7);
	t1.Add(new Igrac(*i2), 6);
	t2 = t1;
	t2.Add(new Igrac(*i3), 10);

	Privilegovan p1("Z", 4, 500);

	try {
		p1.Add(new Igrac(*i4), 0).Add(new Igrac(*i5), 0).Add(new Igrac(*i6), 0);
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
	cout << t1 << endl;
	cout << t2 << endl;
	cout << p1 << endl;

	t1.Add(new Igrac("O", 999), 5);
	Mec m1(new Tim(t1), new Privilegovan(p1));
	cout << m1 << endl;
	
	try {
		cout << m1.GetPoeni() << endl;
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
	
	if (!m1.GetOdigran()) {
		m1.Play();
	}
	cout << m1 << endl;
	cout << m1.GetPoeni() << endl;

	delete i1;
	delete i2;
	delete i3;
	delete i4;
	delete i5;
	delete i6;

	return 0;
}