#include "Dove.h"

Dove::Dove(){
	sound = "����";
	aniname = "��ѱ�";
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
