#include "Dog.h"

Dog::Dog(){
	sound = "¸Û¸Û";
	aniname = "°­¾ÆÁö";
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


