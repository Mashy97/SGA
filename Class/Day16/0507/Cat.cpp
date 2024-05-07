#include "Cat.h"

Cat::Cat(){
	sound = "¾ß¿Ë";
	aniname = "°í¾çÀÌ";
	legs = 4;
}

Cat::Cat(string str){
	sound = str;
}

Cat::~Cat(){

}

void Cat::PlaySound(){
	Print(sound);
}
