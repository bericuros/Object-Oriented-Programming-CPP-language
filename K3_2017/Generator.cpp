#include "Generator.h"

Generator::Generator(Jelovnik &aMenu) : menu(&aMenu) {
	for (int i = 0; i < 3; i++) {
		dish[0] = nullptr;
	}
	price = 0;
}

void Generator::Chose(int h) {
	price = 0;
	char types[3] = { 'P', 'G', 'D' };
	for (int i = 0;i < 3;i++) {
		while (true) {
			int idx = rand() % menu->GetSize();
			for (menu->CurrHead(); menu->CurrExists() && idx--; menu->CurrStep());
			Jelo *d = menu->GetData();
			int &am = menu->GetInfo();
			if (d->GetType() == types[i] && am > 0) {
				am--;
				dish[i] = d;
				d->SetHour(h);
				price += d->GetPrice();
				break;
			}
		}
	}
}

ostream & operator<<(ostream &os, const Generator &g) {
	return os << g.price << "\n" << *g.dish[0] << "\n"
		<< *g.dish[1] << "\n" << *g.dish[2] << "\n";
}
