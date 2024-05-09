#include "Pop.h"
void Pop::Mplay() {
	Print(" À½¾Ç Á¦¸ñ :");
	Print(Mname);
}

Pop::Pop() {
	Mgenre = "Pop";
}

Pop::Pop(string vocal, string name) {
	Mvocal = vocal;
	Mname = name;
	Mgenre = "Pop";
}

Pop::~Pop() {

}
