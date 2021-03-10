#pragma once

#include"okvirPodatka.h"
#include"mrezniInterfejs.h"

class MrezniUredjaj {
public:
	MrezniUredjaj(int);

	MrezniInterfejs * GetFree() const;
protected:
private:
	MrezniInterfejs **itf;
	int num;
};

MrezniUredjaj::MrezniUredjaj(int aNum) : num(aNum) {
	itf = new MrezniInterfejs*[num];
	for (int i = 0; i < num; i++) {
		itf[i] = new MrezniInterfejs(this);
	}
}

MrezniInterfejs * MrezniUredjaj::GetFree() const {
	return nullptr;
}
