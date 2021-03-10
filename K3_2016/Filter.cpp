#include "Filter.h"
#include "Filter.h"

void Filter::OnGalery(Galerija &g) const {
	for (Galerija::Elem *p = g.head; p; p = p->next) {
		for (int i = 0; i < p->data.GetRow(); i++) {
			for (int j = 0; j < p->data.GetCol(); j++) {
				Work(p->data(i, j));
			}
		}
	}
}

void Invertor::Work(Element &el) const {
	el.ChangeColor(Boja(255 - el.GetColor().GetRed(), 255 - el.GetColor().GetGre(), 255 - el.GetColor().GetBlu()));
}
