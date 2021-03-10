#include "Mec.h"

Mec::Mec(Tim *dom, Tim *gost) : par(dom, gost), poeni(new int, new int) {
	odigran = false;
}

Par<Tim> Mec::GetPar() const {
	return par;
}

Par<int> Mec::GetPoeni() const {
	if (!odigran) {
		throw GNeodigranMec();
	}
	return poeni;
}

bool Mec::GetOdigran() const {
	return odigran;
}

void Mec::Play() {
	Tim *dom = par.GetFirst();
	Tim *gost = par.GetSecond();
	Tim *pob = nullptr, *gub = nullptr;
	int domVred = dom->CalcAvg();
	int gostVred = gost->CalcAvg();

	if (domVred > gostVred) {
		ishod = POBEDA_DOMACIN;
		pob = dom;
		gub = gost;
		poeni.SetFirst(new int(3));
		poeni.SetSecond(new int(0));
	}
	else if (domVred < gostVred) {
		ishod = POBEDA_GOST;
		pob = gost;
		gub = dom;
		poeni.SetFirst(new int(0));
		poeni.SetSecond(new int(3));
	}
	else {
		ishod = NERESENO;
		poeni.SetFirst(new int(1));
		poeni.SetSecond(new int(1));
	}

	if (ishod != NERESENO) {
		int it = pob->GetNum();
		for (int i = 0; it; i++) {
			if ((*pob)[i]) {
				(*pob)[i]->Incr(10);
				it--;
			}
		}
		it = gub->GetNum();
		for (int i = 0; it; i++) {
			if ((*gub)[i]) {
				(*gub)[i]->Incr(10);
				it--;
			}
		}
	}

	odigran = true;
}

ostream & operator<<(ostream &os, const Mec &mec) {
	os << *mec.par.GetFirst() << "\n";
	os << *mec.par.GetSecond() << "\n";
	if (mec.odigran) {
		if (mec.ishod == 0) {
			os << "POBEDA_DOMACIN\n";
		}
		else if (mec.ishod == 2) {
			os << "POBEDA_GOST\n";
		}
		else {
			os << "NERESENO\n";
		}
	}
	return os;
}
