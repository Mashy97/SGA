#include "Jazz.h"
void Jazz::Mplay() {
	Print(" ���� ���� :");
	Print(Mname);
}

Jazz::Jazz() {
	Mgenre = "Jazz";
}

Jazz::Jazz(string vocal, string name) {
	Mvocal = vocal;
	Mname = name;
	Mgenre = "Jazz";
}

Jazz::~Jazz() {

}
