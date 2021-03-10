#include "Operator.h"

bool operator>(const Operator &o1, const Operator &o2) {
	return o1.GetPrio() > o2.GetPrio();
}

Operator::~Operator() {}

char Operator::GetOzn() const {
	return 'O';
}
