#include "Music.h"

void Music::Mplay() {
		cout << "Music::Mplay();" << endl;

}

Music::Music()
:Mvocal(""),Mname(""),Mnum(0),Mgenre(""){

}

void Music::Print(string str) {
	cout << str << endl;
}