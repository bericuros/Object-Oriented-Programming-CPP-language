#include<iostream>
#include<string>
using namespace std;

#include"lista.h"
#include"adresa.h"
#include"okvirPodatka.h"
#include"mrezniInterfejs.h"
#include"mrezniUredjaj.h"

int main() {
	Lista<string> l;
	l.AddBeg("Vuk").AddEnd("Kozu").AddBeg("Stari").AddEnd("Jede");
	for (l.CurrHead(); l.CurrExists(); l.CurrNext()) {
		cout << l.GetData() << " ";
	}
	cout << "\n";
	l.CurrHead();
	l.DeleteData();
	for (l.CurrHead(); l.CurrExists(); l.CurrNext()) {
		cout << l.GetData() << " ";
	}
	cout << "\n";
	l.CurrTail();
	l.DeleteData();
	for (l.CurrHead(); l.CurrExists(); l.CurrNext()) {
		cout << l.GetData() << " ";
	}
	cout << "\n";
	try {
		l.DeleteData();
	}
	catch (exception &e) {
		cout << e.what() << "\n";
	}

	unsigned char arr[6] = { 'u', 'g', 'a', '4', '5', ']' };
	Adresa a(arr);
	cout << a << "\n";
}