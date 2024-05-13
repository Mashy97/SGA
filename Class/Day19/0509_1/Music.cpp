#include "Music.h"

void Music::Mplay() {
	Print(" À½¾Ç Á¦¸ñ : "+Mname);
}

Music::Music()
:Mvocal(""),Mname(""),Mnum(0),Mgenre(""){

}

void Music::Print(string str) {
	cout << str << endl;
}