#include <iostream>
#include <string>
#include <exception>
using namespace std;

#include "Izuzeci.h"
#include "Lista.h"
#include "Element.h"
#include "Operand.h"
#include "Operator.h"
#include "Sabiranje.h"
#include "LevaZagrada.h"
#include "DesnaZagrada.h"
#include "Izraz.h"
#include "GenPost.h"

int main() {

	Izraz i;
	LevaZagrada e1;
	Operand e2("A");
	Sabiranje e3;
	Operand e4("B");
	DesnaZagrada e5;
	Sabiranje e6;
	LevaZagrada e7;
	Operand e8("C");
	Sabiranje e9;
	Operand e10("D");
	DesnaZagrada e11;
	Sabiranje e12;
	Operand e13("E");

	i += e1;
	i += e2;
	i += e3;
	i += e4;
	i += e5;
	i += e6;
	i += e7;
	i += e8;
	i += e9;
	i += e10;
	i += e11;
	i += e12;
	i += e13;

	cout << i << endl;
	cout << i.GetSize() << endl;

	try {
		GenPost *genPost = GenPost::GetGenPost();
		Izraz *temp = genPost->operator()(&i);
		cout << *temp << endl;
	}
	catch(exception &e) {
		cout << e.what() << endl;
	}

	return 0;
}