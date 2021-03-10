#include "GenPost.h"

GenPost * GenPost::genPost = nullptr;

Izraz * GenPost::operator()(Izraz *aI) const {
	Izraz *i = new Izraz;
	Izraz *s = new Izraz;
	int rank = 0;
	while (aI->GetSize()) {
		Element *el = **aI;
		if (el->GetOzn() == 'D') {
			*i += *el;
			rank++;
		}
		else if (el->GetOzn() == '(') {
			*s += *el;
		}
		else if (el->GetOzn() == ')') {
			while (s->GetSize()) {
				Element *temp = -*s;
				if (temp->GetOzn() == '(') {
					break;
				}
				*i += *temp;
				rank--;
				if (rank < 1) {
					throw GPostfiks();
				}
			}
		}
		else {  // upitanju je operator
			Operator *op = dynamic_cast<Operator *>(el);
			while (s->GetSize()) {
				Element *temp = -*s;
				if (temp->GetOzn() == '(') {
					*s += *temp;
					break;
				}
				Operator *tempOp = dynamic_cast<Operator *>(temp);
				if (op->GetPrio() <= tempOp->GetPrio()) {
					*i += *tempOp;
					rank--;
					if (rank < 1) {
						throw GPostfiks();
					}
				}
				else {
					*s += *tempOp;
					break;
				}
			}
			*s += *op;
		}
	}
	while (s->GetSize()) {
		*i += *-*s;
		rank--;
	}
	if (rank != 1) {
		throw GPostfiks();
	}
	return i;
}

GenPost * GenPost::GetGenPost() {
	if (!genPost) {
		genPost = new GenPost;
	}
	return genPost;
}

GenPost::GenPost() {}
