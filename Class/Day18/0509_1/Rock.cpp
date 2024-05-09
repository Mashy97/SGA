#include "Rock.h"
void Rock::Mplay() {
	Print(" À½¾Ç Á¦¸ñ :");
	Print(Mname);
}

Rock::Rock() {
	Mgenre = "Rock";
}

Rock::Rock(string vocal, string name) {
	Mvocal = vocal;
	Mname = name;
	Mgenre = "Rock";
}

Rock::~Rock() {

}
