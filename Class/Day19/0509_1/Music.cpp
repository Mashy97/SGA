#include "Music.h"

void Music::Mplay() {
	Print(" ���� ���� : "+Mname);
}

Music::Music()
:Mvocal(""),Mname(""),Mnum(0),Mgenre(""){

}

void Music::Print(string str) {
	cout << str << endl;
}