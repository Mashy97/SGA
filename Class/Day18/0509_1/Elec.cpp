#include "Elec.h"

void Elec::Mplay() {
	Print(" ���� ���� :");
	Print(Mname);
}

Elec::Elec(){
	Mgenre = "Elec";
}

Elec::Elec(string vocal, string name) {
	Mvocal = vocal;
	Mname = name;
	Mgenre = "Elec";
}

Elec::~Elec(){

}
