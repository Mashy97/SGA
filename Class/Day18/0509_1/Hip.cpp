#include "Hip.h"
void Hip::Mplay() {
	Print(" ���� ���� :");
	Print(Mname);
}

Hip::Hip() {
	Mgenre = "Hip";
}

Hip::Hip(string vocal, string name) {
	Mvocal = vocal;
	Mname = name;
	Mgenre = "Hip";
}

Hip::~Hip() {

}
