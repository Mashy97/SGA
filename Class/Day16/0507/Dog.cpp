#include "Dog.h"

Dog::Dog(){
	sound = "�۸�";
	aniname = "������";
	legs = 4;
}

Dog::Dog(string str){
	sound = str;
}

Dog::~Dog(){

}

void Dog::PlaySound(){
	Print(sound);
}


