#include "Dove.h"

Dove::Dove(){
	sound = "구구";
	aniname = "비둘기";
	legs = 2;
}

Dove::Dove(string str){
	sound = str;
}

Dove::~Dove(){

}

void Dove::PlaySound(){
	Print(sound);
}
